#include "Mesh.h"
#include "Director.h"
#include "Define.h"


CMesh::CMesh()
{

	_mtrlBuffer = NULL;
	_d3dxMaterials = new D3DXMATERIAL();

	_pos = D3DXVECTOR3(0,0,0); // 위치
	_acp = D3DXVECTOR3(0,0,0); // 앵커포인트
	_scale = D3DXVECTOR3(1,1,1);	// 크기
	D3DXMatrixIdentity(&_mat); // 매트릭스
	_col = D3DXCOLOR(1,1,1,1);

	_degreeX = 0;
	_degreeY = 0;
	_degreeZ = 0;
	D3DXQuaternionIdentity(&_qut);

}


CMesh::~CMesh()
{
}

bool CMesh::Init(const char* a_sFileName)
{
										// Load the mesh from the specified file
	D3DXLoadMeshFromX(a_sFileName, D3DXMESH_SYSTEMMEM,
		CDrawMgr->getDevice(), NULL,
		&_mtrlBuffer, NULL, &_numMaterials,
		&_mesh);

	// We need to extract the material properties and texture names from the 
	// pD3DXMtrlBuffer
	_d3dxMaterials = (D3DXMATERIAL*)_mtrlBuffer->GetBufferPointer();
	_materials = new D3DMATERIAL9[_numMaterials];
	_textures = new CTexture*[_numMaterials];

	for (DWORD i = 0; i < _numMaterials; i++)
	{
		_textures[i] = new CTexture();
		// Copy the material
		_materials[i] = _d3dxMaterials[i].MatD3D;

		// Set the ambient color for the material (D3DX does not do this)
		_materials[i].Ambient = _materials[i].Diffuse;

		if (_d3dxMaterials[i].pTextureFilename != NULL &&
			lstrlenA(_d3dxMaterials[i].pTextureFilename) > 0)
		{
			// Create the texture
			_textures[i]->createTexture(_d3dxMaterials[i].pTextureFilename);
		}
	}

	// Done with the material buffer
	_mtrlBuffer->Release();

	return true;
}
void CMesh::UpdateMatrix()
{
	D3DXQuaternionRotationYawPitchRoll(&_qut, D3DXToRadian(_degreeY), D3DXToRadian(_degreeX), D3DXToRadian(_degreeZ));

	D3DXMatrixTransformation(&_mat, &_acp, NULL, &_scale, &_acp, &_qut, &_pos);
}
void CMesh::Render()
{
	UpdateMatrix();

	CDrawMgr->getDevice()->SetTransform(D3DTS_WORLD, &_mat);

	// Meshes are divided into subsets, one for each material. Render them in
	// a loop
	for (DWORD i = 0; i < _numMaterials; i++)
	{
		// Set the material and texture for this subset
		CDrawMgr->getDevice()->SetMaterial(&_materials[i]);
		CDrawMgr->getDevice()->SetTexture(0, _textures[i]->getTexture());

		// Draw the mesh subsetS
		_mesh->DrawSubset(i);
		
	}
}
void CMesh::Release()
{

}

void CMesh::setPos(D3DXVECTOR3 a_Pos)
{
	_pos = a_Pos;
}
void CMesh::setAcp(D3DXVECTOR3 a_Acp)
{
	_acp = a_Acp;
}
void CMesh::setScale(D3DXVECTOR3 a_Scale)
{
	_scale = a_Scale;
}
void CMesh::setMat(D3DXMATRIX a_Mat)
{
	_mat = a_Mat;
}
void CMesh::setColor(D3DXCOLOR a_Col)
{
	_col = a_Col;
}

D3DXVECTOR3 CMesh::getPos()
{
	return _pos;
}
D3DXVECTOR3 CMesh::getAcp()
{
	return _acp;
}
D3DXVECTOR3 CMesh::getScale()
{
	return _scale;
}
D3DXMATRIX CMesh::getMat()
{
	return _mat;
}
D3DXCOLOR CMesh::getColor()
{
	return _col;
}
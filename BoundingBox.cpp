#include "BoundingBox.h"
#include "Director.h"


CBoundingBox::CBoundingBox()
{
	_visible = false;
}


CBoundingBox::~CBoundingBox()
{
}

bool CBoundingBox::Init()
{
	_max = D3DXVECTOR3(FLT_MAX, FLT_MAX, FLT_MAX);
	_min = D3DXVECTOR3(FLT_MIN, FLT_MIN, FLT_MIN);


	return true;
}
void CBoundingBox::GetMinMax(LPD3DXMESH mesh)
{
	_fvf = mesh->GetFVF();
	D3DXVECTOR3* tempHighVertex = 0;
	mesh->LockVertexBuffer(0, (void**)&tempHighVertex);
	for (DWORD i = 0; i < mesh->GetNumVertices(); ++i)
	{
		if (tempHighVertex[i].x > _max.x) _max.x = tempHighVertex[i].x;
		if (tempHighVertex[i].y > _max.y) _max.y = tempHighVertex[i].y;
		if (tempHighVertex[i].z > _max.z) _max.z = tempHighVertex[i].z;
		if (tempHighVertex[i].x < _min.x) _min.x = tempHighVertex[i].x;
		if (tempHighVertex[i].y < _min.y) _min.y = tempHighVertex[i].y;
		if (tempHighVertex[i].z < _min.z) _min.z = tempHighVertex[i].z;
	}
	mesh->UnlockVertexBuffer();
}
void CBoundingBox::CreateBox()
{
	_boxVertices[0] = D3DXVECTOR3(_min.x, _max.y, _min.z);
	_boxVertices[1] = D3DXVECTOR3(_max.x, _max.y, _min.z);
	_boxVertices[2] = D3DXVECTOR3(_min.x, _min.y, _min.z);
	_boxVertices[3] = D3DXVECTOR3(_max.x, _min.y, _min.z);

	//뒷면
	_boxVertices[4] = D3DXVECTOR3(_min.x, _max.y, _max.z);
	_boxVertices[5] = D3DXVECTOR3(_max.x, _max.y, _max.z);
	_boxVertices[6] = D3DXVECTOR3(_min.x, _min.y, _max.z);
	_boxVertices[7] = D3DXVECTOR3(_max.x, _min.y, _max.z);

	//좌에서 우로
	_boxIndex[0] = 0;
	_boxIndex[1] = 1;
	_boxIndex[2] = 4;
	_boxIndex[3] = 5;
	_boxIndex[4] = 3;
	_boxIndex[5] = 2;
	_boxIndex[6] = 6;
	_boxIndex[7] = 7;

	// 아래에서 위로
	_boxIndex[8] = 0;
	_boxIndex[9] = 4;
	_boxIndex[10] = 1;
	_boxIndex[11] = 5;
	_boxIndex[12] = 2;
	_boxIndex[13] = 6;
	_boxIndex[14] = 3;
	_boxIndex[15] = 7;

	// 앞에서 뒤로
	_boxIndex[16] = 0;
	_boxIndex[17] = 2;
	_boxIndex[18] = 1;
	_boxIndex[19] = 3;
	_boxIndex[20] = 5;
	_boxIndex[21] = 7;
	_boxIndex[22] = 4;
	_boxIndex[23] = 6;

}
void CBoundingBox::Render()
{
	CDrawMgr->getDevice()->SetTexture(0, NULL);
	CDrawMgr->getDevice()->SetFVF(_fvf);
}

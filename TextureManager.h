#pragma once
#include <vector>

class CTexture;

class CTextureManager
{
public:
	CTexture* createTexture(const char* a_sFileName);

	CTextureManager();
	~CTextureManager();

private:
	std::vector<CTexture*> _textureInfo;
};


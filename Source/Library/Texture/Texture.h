#pragma once

#include "Common.h"
#include "Texture/WICTextureLoader.h"


class Texture
{
public:
	Texture(const std::filesystem::path&);
	~Texture();
	HRESULT Initialize(ID3D11Device*, ID3D11DeviceContext*);
	ComPtr<ID3D11ShaderResourceView>& GetTextureResourceView();
	ComPtr<ID3D11SamplerState>& GetSamplerState();

protected:
	std::filesystem::path m_filePath;
	ComPtr<ID3D11ShaderResourceView> m_textureRV;
	ComPtr<ID3D11SamplerState> m_samplerLinear;
};

class Material
{
public:
	Material();
	~Material();

	std::shared_ptr<Texture> pDiffuse;
	std::shared_ptr<Texture> pSpecular;

	XMFLOAT3 AmbientColor;
	XMFLOAT3 DiffuseColor;
	XMFLOAT3 SpecularColor;
};
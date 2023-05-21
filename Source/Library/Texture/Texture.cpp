#include "Texture/Texture.h"

Texture::Texture(const std::filesystem::path& filePath)
{

}

Texture::~Texture()
{

}


HRESULT Texture::Initialize(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext)
{
	HRESULT hr = CreateWICTextureFromFile(pDevice, pImmediateContext,
		m_filePath.c_str(), nullptr, m_textureRV.GetAddressOf());

	if (FAILED(hr))
	{
		OutputDebugString(L"Can't load texture from \"");
		OutputDebugString(m_filePath.c_str());
		OutputDebugString(L"\n");

		return hr;
	}

	// Create the sample state
	D3D11_SAMPLER_DESC sampDesc =
	{
	.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR,
	.AddressU = D3D11_TEXTURE_ADDRESS_WRAP,
	.AddressV = D3D11_TEXTURE_ADDRESS_WRAP,
	.AddressW = D3D11_TEXTURE_ADDRESS_WRAP,
	.ComparisonFunc = D3D11_COMPARISON_NEVER,
	.MinLOD = 0,
	.MaxLOD = D3D11_FLOAT32_MAX
	};

	hr = pDevice->CreateSamplerState(&sampDesc, m_samplerLinear.GetAddressOf());
	if (FAILED(hr))
		return hr;
	return hr;
}

ComPtr<ID3D11ShaderResourceView>& Texture::GetTextureResourceView()
{
	return m_textureRV;
}
ComPtr<ID3D11SamplerState>& Texture::GetSamplerState()
{
	return m_samplerLinear;
}


Material::Material()
{

}
Material::~Material()
{

}
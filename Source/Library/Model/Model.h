#pragma once

#include "Common.h"
#include "Renderer/Renderable.h"
#include "Texture/Texture.h"

struct aiScene;
struct aiMesh;
struct aiMaterial;

class Model :public Renderable
{
public:
	Model() = default;
	Model(_In_ const std::filesystem::path& filePath);
	virtual ~Model() = default;
	virtual HRESULT Initialize(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext);
	HRESULT initFromScene(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext,
		_In_ const aiScene* pScene, _In_ const std::filesystem::path& filePath);

	virtual void Update(_In_ FLOAT deltaTime);

	void countVerticesAndIndices(_Inout_ UINT& uOutNumVertices, _Inout_ UINT& uOutNumIndices, _In_ const aiScene* pScene);
	void reserveSpace(_In_ UINT uNumVertices, _In_ UINT uNumIndices);

	void initAllMeshes(_In_ const aiScene* pScene);
	void initSingleMesh(const aiMesh* pMesh);
	HRESULT initMaterials(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext*
		pImmediateContext, _In_ const aiScene* pScene, _In_ const std::filesystem::path& filePath);

	HRESULT loadTextures(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext,
		_In_ const std::filesystem::path& parentDirectory, _In_ const aiMaterial* pMaterial, _In_ UINT uIndex);
	HRESULT loadDiffuseTexture(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext,
		_In_ const std::filesystem::path& parentDirectory, _In_ const aiMaterial* pMaterial, _In_ UINT uIndex);
	HRESULT loadSpecularTexture(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext,
		_In_ const std::filesystem::path& parentDirectory, _In_ const aiMaterial* pMaterial, _In_ UINT uIndex);
	void loadColors(_In_ const aiMaterial* pMaterial, _In_ UINT uIndex);

	virtual UINT GetNumVertices() const;
	virtual UINT GetNumIndices() const;

protected:
	const virtual SimpleVertex* getVertices() const;
	virtual const WORD* getIndices() const;

	std::filesystem::path m_filePath;
	std::vector<SimpleVertex> m_aVertices;
	std::vector<WORD> m_aIndices;
};
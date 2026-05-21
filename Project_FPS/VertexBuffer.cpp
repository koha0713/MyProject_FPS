#include "VertexBuffer.h"

//==============================
// 初期化
//==============================
bool VertexBuffer::Create(
	ID3D11Device* device,
	const std::vector<Vertex>& vertices)
{
	//====================
	// バッファの設定
	//====================
	D3D11_BUFFER_DESC desc = {};
	desc.ByteWidth =
		static_cast<UINT>(
			sizeof(Vertex) * vertices.size()); // バッファのサイズ
	
	desc.Usage = D3D11_USAGE_DEFAULT; // バッファの使用方法
	
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER; // バインドフラグ
	
	// バッファの初期データ
	D3D11_SUBRESOURCE_DATA data = {};

	data.pSysMem = vertices.data(); // 頂点データの配列

	//====================
	// バッファの作成
	//====================
	HRESULT hr = device->CreateBuffer(
		&desc, 
		&data, 
		m_buffer.GetAddressOf());

	if (FAILED(hr))
	{
		return false;
	}

	return true;

}
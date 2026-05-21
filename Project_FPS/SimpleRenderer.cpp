#include "SimpleRenderer.h"

//==============================
// 初期化関数
//==============================
bool SimpleRenderer::Initialize(
	ID3D11Device* device)
{
	//====================
	// 頂点バッファの初期化
	//====================
	std::vector<Vertex> vertices =
	{
		{{0.0f, 0.5f, 0.0f}},
		{{0.5f, -0.5f, 0.0f}},
		{{-0.5f, -0.5f, 0.0f}}
	};

	//====================
	// VertexBufferの初期化
	//====================
	if (!m_vertexBuffer.Create(
		device,
		vertices))
	{
		return false;
	}

	//====================
	// シェーダーの読み込み
	//====================
	if (!m_vs.Load(
		device,
		L"VS_Basic.hlsl"))
	{
		return false;
	}

	if (!m_ps.Load(
		device,
		L"PS_Basic.hlsl"))
	{
		return false;
	}

	//====================
	// 入力レイアウトの初期化
	//====================
	if (!m_inputLayout.Create(
		device,
		m_vs.GetBlob()))
	{
		return false;
	}

	return true;

}

//==============================
// 描画関数
//==============================
void SimpleRenderer::Draw(
	ID3D11DeviceContext* context)
{
	//====================
	// 頂点バッファの設定
	//====================
	UINT stride = m_vertexBuffer.GetStride(); // 頂点のサイズ
	UINT offset = 0; // バッファの先頭からのオフセット

	ID3D11Buffer* vb =
		m_vertexBuffer.GetBuffer(); // 頂点バッファのアドレス

	context->IASetVertexBuffers(
		0, // スロット番号
		1, // バッファの数
		&vb, // バッファのアドレス
		&stride, // 頂点のサイズ
		&offset); // バッファの先頭からのオフセット

	//====================
	// プリミティブトポロジーの設定
	//====================
	context->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	//====================
	// 入力レイアウトの設定
	//====================
	context->IASetInputLayout(
		m_inputLayout.Get());

	//====================
	// シェーダーの設定
	//====================
	context->VSSetShader(
		m_vs.Get(),
		nullptr,
		0);

	context->PSSetShader(
		m_ps.Get(),
		nullptr,
		0);

	//====================
	// 描画コール
	//====================
	context->Draw(
		3, // 描画する頂点数
		0); // 描画開始位置
}

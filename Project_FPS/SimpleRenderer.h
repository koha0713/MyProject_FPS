#pragma once

#include "VertexBuffer.h"
#include "InputLayout.h"
#include "VertexShader.h"
#include "PixelShader.h"

//==============================
// シンプルレンダラー
//==============================
class SimpleRenderer
{
public:
	//====================
	// 初期化関数
	//====================
	bool Initialize(
		ID3D11Device* device);

	//====================
	// 描画関数
	//====================
	void Draw(
		ID3D11DeviceContext* context);

private:
	//====================
	// メンバ変数
	//====================
	VertexBuffer m_vertexBuffer; // 頂点バッファ
	InputLayout m_inputLayout; // 入力レイアウト

	VertexShader m_vs; // 頂点シェーダー
	PixelShader m_ps; // ピクセルシェーダー

};
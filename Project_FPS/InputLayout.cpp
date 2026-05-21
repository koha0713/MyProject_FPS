#include "InputLayout.h"

//==============================
// 初期化
//==============================
bool InputLayout::Create(
	ID3D11Device* device,
	ID3DBlob* shaderBlob)
{
	//====================
	// 頂点レイアウト
	//====================
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{
			"POSITION", // セマンティクス名
			0, // セマンティクスインデックス
			DXGI_FORMAT_R32G32B32_FLOAT, // フォーマット
			0, // 入力スロット
			0, // アライメントオフセット
			D3D11_INPUT_PER_VERTEX_DATA, // インスタンスデータか頂点データか
			0 // インスタンスデータのステップレート
		}
	};

	//====================
	// 入力レイアウトの作成
	//====================
	HRESULT hr = device->CreateInputLayout(
		layout, // 入力レイアウトの設定配列
		_countof(layout), // 入力レイアウトの設定配列のサイズ
		shaderBlob->GetBufferPointer(), // シェーダーバイトコードのポインタ
		shaderBlob->GetBufferSize(), // シェーダーバイトコードのサイズ
		m_layout.GetAddressOf()); // 入力レイアウトの出力先
	
	if (FAILED(hr))
	{
		return false;
	}

	return true;

}
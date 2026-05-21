#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include "NonCopyable.h"

//==============================
// 入力レイアウト
//==============================
class InputLayout : private NonCopyable
{
	public:
	//====================
	// 初期化
	//====================
	/**
	 * @brief 初期化
	 * @param device デバイス
	 * @param shaderBytecode シェーダーバイトコード
	 * @return 成功したらtrue、失敗したらfalse
	 */
	bool Create(
		ID3D11Device* device,
		ID3DBlob* shaderBlob);

	//====================
	// 取得関数
	//====================
	ID3D11InputLayout* Get() const
	{
		return m_layout.Get();
	}

private:
	//====================
	// メンバ変数
	//====================
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_layout; // 入力レイアウト

};
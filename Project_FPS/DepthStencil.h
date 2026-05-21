#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include "NonCopyable.h"

//==============================
// 前方宣言
//==============================
class Window;

//==============================
// デプスステンシル
//==============================
class DepthStencil final : NonCopyable
{
	public:
	//====================
	// ライフサイクル
	//====================
	/**
	 * @brief コンストラクタ
	 */
	DepthStencil() = default;
	/**
	 * @brief デストラクタ
	 */
	~DepthStencil() = default;

	//====================
	// 初期化
	//====================
	/**
	 * @brief 初期化
	 * @param device デバイス
	 * @param window ウィンドウ
	 * @return 成功したらtrue、失敗したらfalse
	 */
	bool Initialize(
		ID3D11Device* device,
		Window* window);
	
	//====================
	// 取得関数
	//====================
	ID3D11DepthStencilView* GetDSV() const
	{
		return m_dsv.Get();
	}

private:
	//====================
	// メンバ変数
	//====================
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_depthTexture;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> m_dsv;

};
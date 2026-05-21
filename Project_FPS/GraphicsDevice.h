#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include "NonCopyable.h"

//==============================
// 前方宣言
//==============================
class Window;

//==============================
// グラフィックスデバイス
//==============================
class GraphicsDevice : public NonCopyable
{
	public:
	//====================
	// ライフサイクル
	//====================
	/**
	 * @brief コンストラクタ
	 */
	GraphicsDevice() = default;
	/**
	 * @brief デストラクタ
	 */
	~GraphicsDevice() = default;

	//====================
	// 初期化
	//====================

	/**
	 * @brief 初期化
	 * @param window ウィンドウ
	 * @return 成功したらtrue、失敗したらfalse
	 */
	bool Initialize(Window* window);

	//====================
	// 画面クリア
	//====================
	/**
	 * @brief 画面クリア
	 */
	void Clear();

	//====================
	// 描画
	//====================
	/**
	 * @brief 描画
	 */
	void Present();

private:
	//====================
	// RTV生成
	//====================
	bool CreateRenderTarget();

private:
	//====================
	// メンバ変数
	//====================
	Microsoft::WRL::ComPtr<ID3D11Device> m_device; // デバイス
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_context; // デバイスコンテキスト
	Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain; // スワップチェーン

	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_rtv; // レンダーターゲットビュー
};
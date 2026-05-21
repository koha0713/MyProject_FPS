#include "GraphicsDevice.h"
#include "Window.h"
#include <memory>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"dxgi.lib")

using Microsoft::WRL::ComPtr;

//==============================
// 初期化
//==============================
bool GraphicsDevice::Initialize(Window* window)
{
	//====================
	// スワップチェーンの設定
	//====================
	DXGI_SWAP_CHAIN_DESC sd = {};

	sd.BufferCount = 1; // バックバッファの数
	sd.BufferDesc.Width = window->GetWidth(); // バックバッファの幅
	sd.BufferDesc.Height = window->GetHeight(); // バックバッファの高さ
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // バックバッファのフォーマット
	
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // バックバッファの使用方法
	
	sd.OutputWindow = window->GetHandle(); // 出力先のウィンドウハンドル
	
	sd.SampleDesc.Count = 1; // マルチサンプリングのサンプル数
	sd.SampleDesc.Quality = 0; // マルチサンプリングの品質レベル
	
	sd.Windowed = TRUE; // ウィンドウモード
	
	//====================
	// Device生成
	//====================
	UINT createFlags = 0;

#ifdef DEBUG
	createFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // DEBUG

	D3D_FEATURE_LEVEL featureLevel;

	// デバイスとスワップチェーンの作成
	HRESULT hr = D3D11CreateDeviceAndSwapChain(
		nullptr, // アダプタ
		D3D_DRIVER_TYPE_HARDWARE, // ドライバタイプ
		nullptr, // ソフトウェアレンダリングの場合はnullptr
		createFlags, // フラグ
		nullptr, // 機能レベル配列
		0, // 機能レベル配列のサイズ
		D3D11_SDK_VERSION, // SDKバージョン
		&sd, // スワップチェーンの設定
		&m_swapChain, // スワップチェーンの出力先
		&m_device, // デバイスの出力先
		&featureLevel, // 実際に使用された機能レベル（不要な場合はnullptr）
		&m_context); // デバイスコンテキストの出力先

	if (FAILED(hr))
	{
		return false;
	}

	//====================
	// レンダラーターゲット生成
	//====================
	if (!CreateRenderTarget())
	{
		return false;
	}

	//====================
	// DepthStencil生成
	//====================
	m_depthStencil = std::make_unique<DepthStencil>();
	if (!m_depthStencil->Initialize(
		m_device.Get(), 
		window))
	{
		return false;
	}

	//====================
	// Viewportの設定
	//====================
	m_viewport.Width =
		static_cast<float>(window->GetWidth()); // 幅
	m_viewport.Height =
		static_cast<float>(window->GetHeight()); // 高さ

	m_viewport.TopLeftX = 0.0f; // ビューポートの左上X座標
	m_viewport.TopLeftY = 0.0f; // ビューポートの左上Y座標
	m_viewport.MinDepth = 0.0f; // 最小深度
	m_viewport.MaxDepth = 1.0f; // 最大深度

	m_context->RSSetViewports(
		1,
		&m_viewport);

	return true;

}

//====================
// RTV生成
//====================
bool GraphicsDevice::CreateRenderTarget()
{
	//====================
	// バックバッファを取得
	//====================
	ComPtr<ID3D11Texture2D> backBuffer;

	HRESULT hr = m_swapChain->GetBuffer(
		0, 
		__uuidof(ID3D11Texture2D), 
		reinterpret_cast<void**>(
			backBuffer.GetAddressOf()));
	
	if (FAILED(hr))
	{
		return false;
	}

	//====================
	// RTVの作成
	//====================
	hr = m_device->CreateRenderTargetView(
		backBuffer.Get(), 
		nullptr, 
		m_rtv.GetAddressOf());

	if (FAILED(hr))
	{
		return false;
	}

	return true;

}

//====================
// 画面クリア
//====================
void GraphicsDevice::Clear()
{
	//====================
	// クリア色
	//====================
	float clearColor[4] = 
	{ 0.0f, 1.0f, 0.0f, 1.0f }; // 黒色

	//====================
	// RTVセット
	//====================
	m_context->OMSetRenderTargets(
		1,
		m_rtv.GetAddressOf(), 
		m_depthStencil->GetDSV());

	//====================
	// 画面クリア
	//====================
	m_context->ClearRenderTargetView(
		m_rtv.Get(), 
		clearColor);

	//====================
	// 深度ステンシルのクリア
	//====================
	m_context->ClearDepthStencilView(
		m_depthStencil->GetDSV(), 
		D3D11_CLEAR_DEPTH, 
		1.0f, 
		0);
}

//====================
// 描画
//====================
void GraphicsDevice::Present()
{
	//====================
	// スワップチェーンの更新
	//====================
	m_swapChain->Present(1, 0);

}


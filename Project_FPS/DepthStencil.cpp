#include "DepthStencil.h"
#include "Window.h"

using Microsoft::WRL::ComPtr;

//==============================
// 初期化
//==============================
bool DepthStencil::Initialize(
	ID3D11Device* device, 
	Window* window)
{
	//====================
	// テクスチャの設定
	//====================
	D3D11_TEXTURE2D_DESC desc = {};
	
	desc.Width = window->GetWidth(); // 幅
	desc.Height = window->GetHeight(); // 高さ
	
	desc.MipLevels = 1; // ミップマップレベル数
	desc.ArraySize = 1; // 配列サイズ

	desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT; // フォーマット
	
	desc.SampleDesc.Count = 1; // マルチサンプリングのサンプル数
	desc.SampleDesc.Quality = 0; // マルチサンプリングの品質レベル
	
	desc.Usage = D3D11_USAGE_DEFAULT; // 使用方法
	desc.BindFlags = D3D11_BIND_DEPTH_STENCIL; // バインドフラグ
	
	// テクスチャの作成
	HRESULT hr = device->CreateTexture2D(
		&desc, 
		nullptr, 
		m_depthTexture.GetAddressOf());

	if (FAILED(hr))
	{
		return false;
	}

	//====================
	// DSVの生成
	//====================
	hr = device->CreateDepthStencilView(
		m_depthTexture.Get(), 
		nullptr, 
		m_dsv.GetAddressOf());

	if (FAILED(hr))
	{
		return false;
	}

	return true;

}

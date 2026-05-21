#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include "Shader.h"

//==============================
// ピクセルシェーダー
//==============================
class PixelShader : public Shader
{
public:
	//====================
	// 読み込み関数
	//====================
	bool Load(
		ID3D11Device* device,
		const std::wstring& path)
	{
		//========================
		// コンパイル
		//========================
		if (!Compile(
			path,
			"main",
			"ps_5_0"))
		{
			return false;
		}

		//========================
		// PS生成
		//========================
		HRESULT hr = device->CreatePixelShader(
			m_blob->GetBufferPointer(),
			m_blob->GetBufferSize(),
			nullptr,
			m_shader.GetAddressOf());

		if (FAILED(hr))
		{
			return false;
		}

		return true;
	}

	//====================
	// 取得関数
	//====================
	ID3D11PixelShader* Get() const
	{
		return m_shader.Get();
	}

private:
	//====================
	// メンバ変数
	//====================
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_shader; // ピクセルシェーダー

};
#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include "Shader.h"

//==============================
// 頂点シェーダー
//==============================
class VertexShader : public Shader
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
            "vs_5_0"))
        {
            return false;
        }

        //========================
        // VS生成
        //========================
        HRESULT hr = device->CreateVertexShader(
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
    ID3D11VertexShader* Get() const
    {
        return m_shader.Get();
    }

    ID3DBlob* GetBlob() const
    {
        return m_blob.Get();
    }

private:
	//====================
	// メンバ変数
	//====================
    Microsoft::WRL::ComPtr<ID3D11VertexShader> m_shader;
};
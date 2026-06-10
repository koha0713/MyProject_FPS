#pragma once

#include <d3d11.h>
#include <wrl/client.h>

#include "NonCopyable.h"

//==============================
// ConstantBuffer
//==============================
template<class T>
class ConstantBuffer : NonCopyable
{
public:

    ConstantBuffer() = default;
    ~ConstantBuffer() = default;

    //====================
    // ì¬
    //====================
    bool Create(ID3D11Device* device)
    {
        //====================
        // BufferÝ’è
        //====================
        D3D11_BUFFER_DESC desc{};

        desc.ByteWidth =
            sizeof(T);

        desc.Usage =
            D3D11_USAGE_DEFAULT;

        desc.BindFlags =
            D3D11_BIND_CONSTANT_BUFFER;

        //====================
        // Buffer¶¬
        //====================
        HRESULT hr =
            device->CreateBuffer(
                &desc,
                nullptr,
                m_buffer.GetAddressOf());

        if (FAILED(hr))
        {
            return false;
        }

        return true;
    }

    //====================
    // XV
    //====================
    void Update(
        ID3D11DeviceContext* context,
        const T& data)
    {
        context->UpdateSubresource(
            m_buffer.Get(),
            0,
            nullptr,
            &data,
            0,
            0);
    }

    //====================
    // Getter
    //====================
    ID3D11Buffer* Get() const
    {
        return m_buffer.Get();
    }

private:

    Microsoft::WRL::ComPtr<ID3D11Buffer>
        m_buffer;
};
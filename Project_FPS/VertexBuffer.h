#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include <vector>
#include "Vertex.h"
#include "NonCopyable.h"

//==============================
// 頂点バッファ
//==============================
class VertexBuffer : private NonCopyable
{
	public:
	//====================
	// ライフサイクル
	//====================
	/**
	 * @brief コンストラクタ
	 */
	VertexBuffer() = default;
	/**
	 * @brief デストラクタ
	 */
	~VertexBuffer() = default;

	//====================
	// 初期化
	//====================
	/**
	 * @brief 初期化
	 * @param device デバイス
	 * @param vertices 頂点データの配列
	 * @return 成功したらtrue、失敗したらfalse
	 */
	bool Create(
		ID3D11Device* device,
		const std::vector<Vertex>& vertices);

	//====================
	// 取得関数
	//====================
	ID3D11Buffer* GetBuffer() const
	{
		return m_buffer.Get();
	}
	
	UINT GetStride() const
	{
		return sizeof(Vertex);
	}

private:
	//====================
	// メンバ変数
	//====================
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_buffer; // 頂点バッファ

};


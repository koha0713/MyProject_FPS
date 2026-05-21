#pragma once

#include <DirectXMath.h>

//==============================
// カメラ
//==============================
class Camera
{
public:
	//====================
	// 更新
	//====================
	void Update(
		const DirectX::XMFLOAT3& position,
		const DirectX::XMFLOAT3& rotation);

	//====================
	// 取得関数
	//====================
	const DirectX::XMMATRIX& GetView() const
	{
		return m_view;
	}
	const DirectX::XMMATRIX& GetProjection() const
	{
		return m_projection;
	}

private:
	//====================
	// メンバ変数
	//====================
	DirectX::XMMATRIX m_view =
		DirectX::XMMatrixIdentity(); // ビュー行列

	DirectX::XMMATRIX m_projection =
		DirectX::XMMatrixIdentity(); // 射影行列
};
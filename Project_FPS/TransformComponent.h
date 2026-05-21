#pragma once

#include <DirectXMath.h>
#include "Component.h"

//==============================
// 座標コンポーネント
//==============================
class TransformComponent : public Component
{
public:
	//====================
	// ライフサイクル
	//====================
	/**
	 * @brief コンストラクタ
	 */
	TransformComponent() = default;
	/**
	 * @brief デストラクタ
	 */
	~TransformComponent() override = default;

	//====================
	// 更新
	//====================
	void Update() override;

	//====================
	// 位置、回転、スケールの設定と取得
	//====================
	void SetPosition(const DirectX::XMFLOAT3& position);
	DirectX::XMFLOAT3 GetPosition() const { return m_position; }

	void SetRotation(const DirectX::XMFLOAT3& rotation);
	DirectX::XMFLOAT3 GetRotation() const { return m_rotation; }

	void SetScale(const DirectX::XMFLOAT3& scale);
	DirectX::XMFLOAT3 GetScale() const { return m_scale; }

	//====================
	// ワールド行列の取得
	//====================
	DirectX::XMMATRIX GetWorldMatrix() const { return m_worldMatrix; }

private:
	//====================
	// ワールド行列の更新
	//====================
	void UpdateMatrix();

private:
	//====================
	// メンバ変数
	//====================
	DirectX::XMFLOAT3 m_position = { 0.0f, 0.0f, 0.0f };
	DirectX::XMFLOAT3 m_rotation = { 0.0f, 0.0f, 0.0f };
	DirectX::XMFLOAT3 m_scale = { 1.0f, 1.0f, 1.0f };
	DirectX::XMMATRIX m_worldMatrix = 
		DirectX::XMMatrixIdentity();

};

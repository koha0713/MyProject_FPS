#pragma once

#include "Camera.h"
#include "Component.h"

//==============================
// 前方宣言
//==============================
class TransformComponent;

//==============================
// カメラコンポーネント
//==============================
class CameraComponent : public Component
{
public:
	//====================
	// ライフサイクル
	//====================
    /**
     * @brief コンストラクタ
	 */
    CameraComponent();
    /**
     * @brief デストラクタ
	 */
    ~CameraComponent();

	//====================
	// 更新
	//====================
    void Update();

	//====================
	// 取得関数
	//====================
	const Camera& GetCamera() const
	{
		return m_camera;
	}

private:
	//====================
	// メンバ変数
	//====================
    Camera m_camera;
};

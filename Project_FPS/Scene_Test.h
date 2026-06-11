#pragma once

#include <memory>
#include <vector>
#include "BaseScene.h"

class GraphicsDevice;
class GameObject;
class CameraComponent;

//==============================
// テストシーン
//==============================
class Scene_Test : public BaseScene
{
public:
	//====================
	// コンストラクタ・デストラクタ
	//====================
	explicit Scene_Test(
		GraphicsDevice* graphics);
	~Scene_Test() override = default;

	//====================
	// ライフサイクル
	//====================
	/**
	* @brief 初期化
	* @return 成功した場合はtrue、失敗した場合はfalse
	* @details シーンの初期化処理を行う関数
	*/
	bool Initialize() override;

	/**
	* @brief 更新
	* @details シーンの更新処理を行う関数
	*/
	void Update() override;

	/**
	* @brinf 描画
	* @details シーンの描画処理を行う関数
	*/
	void Draw() override;

	/**
	* @brief 終了
	* @details シーンの終了処理を行う関数
	*/
	void Finalize() override;


private:
	// グラフィックスデバイス
	GraphicsDevice* graphics_;
	// カメラコンポーネント
	CameraComponent* m_mainCamera = nullptr;


};
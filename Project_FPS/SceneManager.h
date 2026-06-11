#pragma once

#include <memory>

class IScene;

//==============================
// シーンマネージャー
//==============================
class SceneManager
{
public:
	//====================
	// ライフサイクル
	//====================
	/**
	 * @brief 更新
	 */
	void Update();

	/**
	 * @brief 描画
	 */
	void Draw();

	//====================
	// シーンの切り替え
	//====================
	/**
	 * @brief シーンの切り替え
	 * @details 新しいシーンを設定する関数
	 * @param scene 新しいシーン
	 */
	bool ChangeScene(std::shared_ptr<IScene> scene);

private:
	//====================
	// シーン
	//====================
	std::shared_ptr<IScene> m_scene;

};
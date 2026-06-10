#pragma once
//==============================
// シーン基底クラス
//==============================
class IScene
{
public:
	//====================
	// デストラクタ
	//====================
	virtual ~IScene() = default;

	//====================
	// ライフサイクル
	//===================
	/**
	 * @brief 初期化
	 * @details シーンの初期化処理を行う関数
	 */
	virtual bool Initialize() = 0;

	/**
	 * @brief 更新
	 * @details シーンの更新処理を行う関数
	 */
	virtual void Update() = 0;

	/**
	 * @brief 描画
	 * @details シーンの描画処理を行う関数
	 */
	virtual void Draw() = 0;

	/**
	 * @brief 終了
	 * @details シーンの終了処理を行う関数
	 */
	virtual void Finalize() = 0;


};
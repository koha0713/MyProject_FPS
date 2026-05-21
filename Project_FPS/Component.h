#pragma once

#include "NonCopyable.h"

//==============================
// 前方宣言
//==============================
class GameObject;

//==============================
// コンポーネント基底クラス
//==============================
class Component : private NonCopyable
{
public:
	//====================
	// ライフサイクル
	//====================
	/**
	 * @brief コンストラクタ
	 */
	Component() = default;
	/**
	 * @brief デストラクタ
	 */
	virtual ~Component() = default;

	//====================
	// 初期化
	//====================
	/**
	 * @brief 初期化
	 * @return 成功したらtrue、失敗したらfalse
	 */
	virtual bool Initialize() {}

	//====================
	// 更新
	//====================
	/**
	 * @brief 更新
	 */
	virtual void Update() {}

	//====================
	// 描画
	//====================
	/**
	 * @brief 描画
	 */
	virtual void Draw() {}

	//====================
	// Owner設定
	//====================
	/**
	 * @brief Owner設定
	 * @param owner Ownerのポインタ
	 */
	void SetOwner(GameObject* owner)
	{
		m_owner = owner;
	}

	//====================
	// Owner取得
	//====================
	/**
	 * @brief Owner取得
	 * @return Ownerのポインタ
	 */
	GameObject* GetOwner() const
	{
		return m_owner;
	}

private:
	//====================
	// メンバ変数
	//====================
	GameObject* m_owner = nullptr; // Ownerのポインタ

};
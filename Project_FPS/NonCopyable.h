#pragma once

//==============================
// コピー禁止クラス
//==============================
class NonCopyable
{
protected:
	//====================
	// ライフサイクル
	//====================

	/**
	 * @brief コンストラクタ
	 */
	NonCopyable() = default;

	/**
	 * @brief デストラクタ
	 */
	~NonCopyable() = default;

	//====================
	// コピー禁止
	//====================
	/*
	 * @brief コピーコンストラクタ禁止
	 * @details コピーコンストラクタを禁止することで、オブジェクトのコピーを防ぐ
	*/
	NonCopyable(const NonCopyable&) = delete;

	/*
	 * @brief コピー代入演算子禁止
	 * @details コピー代入演算子を禁止することで、オブジェクトのコピーを防ぐ
	*/
	NonCopyable& operator=(const NonCopyable&) = delete;

};
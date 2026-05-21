#pragma once

#include <Windows.h>
#include <string>
#include "NonCopyable.h"

//==============================
// ウィンドウクラス
//==============================
class Window : public NonCopyable
{
public:
	//====================
	// ライフサイクル
	//====================
	
	/**
	 * @brief コンストラクタ
	 */
	Window() = default;

	/**
	 * @brief デストラクタ
	 */
	~Window() = default;

	//====================
	// 初期化
	//====================
	bool Create(
		const std::wstring& title,
		int width,
		int height);

	//====================
	// メッセージ更新
	//====================
	bool ProcessMessage();

	//====================
	// Getter関数
	//====================
	HWND GetHandle() const { return m_hWnd; }

	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }

private:
	//====================
	// ウィンドウプロシージャ
	//====================
	
	/*
	 * @brief ウィンドウプロシージャ
	 * @details ウィンドウに送られるメッセージを処理する関数
	*/
	static LRESULT CALLBACK WindowProc(
		HWND hwnd,
		UINT uMsg,
		WPARAM wParam,
		LPARAM lParam);

private:
	//====================
	// メンバ変数
	//====================

	HWND m_hWnd = nullptr;	// ウィンドウハンドル
	HINSTANCE m_hInstance = nullptr;	// インスタンスハンドル

	int m_width = 0;		// ウィンドウの幅
	int m_height = 0;		// ウィンドウの高さ

};
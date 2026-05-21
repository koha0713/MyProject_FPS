#include "Window.h"

//==============================
// ウィンドウ生成
//==============================
bool Window::Create(
	const std::wstring& title,
	int width,
	int height)
{
	m_width = width;
	m_height = height;

	m_hInstance = GetModuleHandle(nullptr);;

	//======================
	// WindowClass登録
	//======================
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = m_hInstance;
	wc.lpszClassName = L"GameWindowClass";
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	RegisterClassEx(&wc);

	//======================
	// Windowサイズ調整
	//======================
	RECT rect = { 0,0,width,height };

	AdjustWindowRect(
		&rect,
		WS_OVERLAPPEDWINDOW,
		FALSE);

	//======================
	// Window生成
	//======================
	m_hWnd = CreateWindowEx(
		0,
		wc.lpszClassName,
		title.c_str(),
		WS_OVERLAPPEDWINDOW,

		CW_USEDEFAULT,
		CW_USEDEFAULT,

		rect.right - rect.left,
		rect.bottom - rect.top,

		nullptr,
		nullptr,
		m_hInstance,
		nullptr);

	// 生成失敗
	if (m_hWnd == nullptr)
	{
		return false;
	}

	//======================
	// Window表示
	//======================
	ShowWindow(m_hWnd, SW_SHOW);

	return true;

};

//==============================
// メッセージ更新
//==============================
bool Window::ProcessMessage()
{
	MSG msg{};

	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		// WM_QUITメッセージが来たら終了
		if (msg.message == WM_QUIT)
		{
			return false;
		}
	}

	return true;

}

//==============================
// ウィンドウプロシージャ
//==============================
LRESULT CALLBACK Window::WindowProc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(
		hWnd, 
		uMsg, 
		wParam, 
		lParam);
}
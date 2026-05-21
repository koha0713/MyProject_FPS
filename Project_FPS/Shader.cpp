#include "Shader.h"

#pragma comment(lib,"d3dcompiler.lib")

//==============================
// シェーダーのコンパイル
//==============================
bool Shader::Compile(
	const std::wstring& path,
	const std::string& entryPoint,
	const std::string& target)
{
	UINT flags = D3DCOMPILE_ENABLE_STRICTNESS; // 厳密なコンパイルを有効にするフラグ

#ifdef DEBUG
	flags |= D3DCOMPILE_DEBUG;
#endif

	Microsoft::WRL::ComPtr<ID3DBlob> errorBlob; // エラーメッセージを格納するBlob

	// シェーダーのコンパイル
	HRESULT hr = D3DCompileFromFile(
		path.c_str(), // シェーダーファイルのパス
		nullptr, // 定数マクロの配列
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // インクルードファイルの検索方法
		entryPoint.c_str(), // エントリーポイント
		target.c_str(), // ターゲットプロファイル
		flags, // コンパイルオプション
		0, // エフェクトコンパイルオプション
		m_blob.GetAddressOf(), // コンパイルされたシェーダーバイトコードの出力先
		errorBlob.GetAddressOf()); // エラーメッセージの出力先
	
	if (FAILED(hr))
	{
		if (errorBlob)
		{
			OutputDebugStringA(
				(char*)errorBlob->GetBufferPointer());
		}

		return false;
	}

	return true;

}


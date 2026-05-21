#pragma once

#include <d3dcompiler.h>
#include <wrl/client.h>
#include <string>

//==============================
// シェーダー基底クラス
//==============================
class Shader
{
public:
	//====================
	// ライフサイクル
	//====================
	/**
	 * @brief コンストラクタ
	 */
	Shader() = default;

	/**
	 * @brief デストラクタ
	 */
	virtual ~Shader() = default;

protected:
	//====================
	// シェーダーのコンパイル
	//====================
	/**
	 * @brief シェーダーのコンパイル
	 * @param path シェーダーファイルのパス
	 * @param entryPoint エントリーポイント
	 * @param target ターゲットプロファイル
	 * @return 成功したらtrue、失敗したらfalse
	 */
	bool Compile(
		const std::wstring& path, // シェーダーファイルのパス
		const std::string& entryPoint, // エントリーポイント
		const std::string& target); // ターゲットプロファイル

protected:
	//====================
	// メンバ変数
	//====================
	Microsoft::WRL::ComPtr<ID3DBlob> m_blob; // シェーダーバイトコード

};
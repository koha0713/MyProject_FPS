#pragma once

#include <string>

class BaseScene;

//==============================
// シーン保存 : 現在ダミー
//==============================
class SceneSave
{
public:
	static bool Save(
		BaseScene& scene,
		const std::string& path
	) {
		return true;
	}

	static bool Load(
		BaseScene& scene,
		const std::string& path
	) {
		return true;
	}
};
#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include "NonCopyable.h"
#include "Component.h"

//==============================
// ゲームオブジェクト
//==============================
class GameObject : private NonCopyable
{
public:
	//====================
	// ライフサイクル
	//====================
	/**
	 * @brief コンストラクタ
	 */
	GameObject() = default;
	
	/**
	 * @brief デストラクタ
	 */
	~GameObject() = default;

	//====================
	// 初期化
	//====================
	void Initialize();

	//====================
	// 更新
	//====================
	void Update();

	//====================
	// 描画
	//====================
	void Draw();

	//====================
	// コンポーネント追加
	//====================
    template<class T, class... Args>
    T* AddComponent(Args&&... args)
    {
        static_assert(
            std::is_base_of_v<Component, T>,
            "T must inherit Component");

        //====================
        // Component生成
        //====================
        auto component =
            std::make_unique<T>(
                std::forward<Args>(args)...);

        //====================
        // 生ポインタ保持
        //====================
        T* ptr = component.get();

        //====================
        // Owner設定
        //====================
        ptr->SetOwner(this);

        //====================
        // 保持
        //====================
        m_components.emplace_back(
            std::move(component));

        //====================
        // 初期化
        //====================
        ptr->Initialize();

        return ptr;
    }

    //====================
    // Component取得
    //====================
    template<class T>
    T* GetComponent() const
    {
        for (const auto& component : m_components)
        {
            T* ptr =
                dynamic_cast<T*>(
                    component.get());

            if (ptr)
            {
                return ptr;
            }
        }

        return nullptr;
    }

private:
	//====================
	// メンバ変数
	//====================
    std::vector<
        std::unique_ptr<Component>> m_components;

};
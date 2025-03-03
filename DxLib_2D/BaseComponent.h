#pragma once
#include <memory>

class Entity; // 前方宣言

// すべてのコンポーネントの基底クラス
class BaseComponent {
protected:
	Entity* owner; // このコンポーネントを持っているオブジェクト

public:
	BaseComponent(Entity* owner) : owner(owner) {}
	virtual ~BaseComponent() = default;

	// すべてのコンポーネントが持つ共通メソッド
	virtual void Init() {}   // 初期化
	virtual void Update() {}  // フレームごとの更新
	virtual void Draw() {} // 描画
};
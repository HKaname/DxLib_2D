#pragma once
#include "BaseComponent.h"
#include "DxLib.h"
#include "Transform.h"

class SpriteRenderer : public BaseComponent {
private:
	int spriteHandle;          // 画像ハンドル
	Transform* transform; // 位置情報（他のコンポーネント）

public:
	// コンストラクタ（画像のファイルパスを受け取る）
	SpriteRenderer(Entity* owner, const char* filePath)
		: BaseComponent(owner), spriteHandle(-1), transform(nullptr) {
		LoadSprite(filePath);
	}

	// 画像の読み込み
	void LoadSprite(const char* filePath) {
		spriteHandle = LoadGraph(filePath);
		if (spriteHandle == -1) {
			printf("画像読み込み失敗: %s\n", filePath);
		}
	}

	// 初期化処理（`TransformComponent` を取得）
	void Init() override {
		transform = owner->GetComponent<Transform>();
		if (!transform) {
			printf("Warning: Transform が見つかりません\n");
		}
	}

	// 描画処理
	void Draw() {
		if (transform && spriteHandle != -1) {
			DrawGraph((int)transform->x, (int)transform->y, spriteHandle, TRUE);
		}
	}
};

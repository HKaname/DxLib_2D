#pragma once
#include "BaseComponent.h"
#include "DxLib.h"
#include "Transform.h"

class SpriteRenderer : public BaseComponent {
private:
	int spriteHandle;          // �摜�n���h��
	Transform* transform; // �ʒu���i���̃R���|�[�l���g�j

public:
	// �R���X�g���N�^�i�摜�̃t�@�C���p�X���󂯎��j
	SpriteRenderer(Entity* owner, const char* filePath)
		: BaseComponent(owner), spriteHandle(-1), transform(nullptr) {
		LoadSprite(filePath);
	}

	// �摜�̓ǂݍ���
	void LoadSprite(const char* filePath) {
		spriteHandle = LoadGraph(filePath);
		if (spriteHandle == -1) {
			printf("�摜�ǂݍ��ݎ��s: %s\n", filePath);
		}
	}

	// �����������i`TransformComponent` ���擾�j
	void Init() override {
		transform = owner->GetComponent<Transform>();
		if (!transform) {
			printf("Warning: Transform ��������܂���\n");
		}
	}

	// �`�揈��
	void Draw() {
		if (transform && spriteHandle != -1) {
			DrawGraph((int)transform->x, (int)transform->y, spriteHandle, TRUE);
		}
	}
};

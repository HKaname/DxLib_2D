#pragma once
#include <memory>

class Entity; // �O���錾

// ���ׂẴR���|�[�l���g�̊��N���X
class BaseComponent {
protected:
	Entity* owner; // ���̃R���|�[�l���g�������Ă���I�u�W�F�N�g

public:
	BaseComponent(Entity* owner) : owner(owner) {}
	virtual ~BaseComponent() = default;

	// ���ׂẴR���|�[�l���g�������ʃ��\�b�h
	virtual void Init() {}   // ������
	virtual void Update() {}  // �t���[�����Ƃ̍X�V
	virtual void Draw() {} // �`��
};
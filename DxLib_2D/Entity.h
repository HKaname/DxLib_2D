#pragma once
#include <vector>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include "BaseComponent.h"

class Entity {
private:
	std::unordered_map<std::type_index, std::shared_ptr<BaseComponent>> components;

public:
	template <typename T, typename... Args>
	std::shared_ptr<T> AddComponent(Args&&... args) {
		auto component = std::make_shared<T>(this, std::forward<Args>(args)...);
		components[std::type_index(typeid(T))] = component;
		component->Init();
		return component;
	}

	template <typename T>
	T* GetComponent() {
		auto it = components.find(std::type_index(typeid(T)));
		if (it != components.end()) {
			return static_cast<T*>(it->second.get());
		}
		return nullptr;
	}

	void Init() {
		for (auto& [_, component] : components) {
			component->Init();
		}
	}

	void Update() {
		for (auto& [_, component] : components) {
			component->Update();
		}
	}

	void Draw() {
		for (auto& [_, component] : components) {
			component->Draw();
		}
	}
};


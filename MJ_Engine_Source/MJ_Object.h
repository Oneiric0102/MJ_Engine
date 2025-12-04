#pragma once
#include "MJ_Component.h"
#include "MJ_GameObject.h"
#include "MJ_Layer.h"
#include "MJ_Scene.h"
#include "MJ_SceneManager.h"
#include "MJ_Transform.h"

namespace MJ::object {
	template <typename T>
	static T* Instantiate(enums::eLayerType type) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(enums::eLayerType type, math::Vector2 position) {
		static T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* obj)
	{
		obj->Death();
	}

}
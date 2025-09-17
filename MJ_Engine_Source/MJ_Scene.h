#pragma once
#include "CommonInclude.h"
#include "MJ_Entity.h"
#include "MJ_GameObject.h"

namespace MJ {
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameobject);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}



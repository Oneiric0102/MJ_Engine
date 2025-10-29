#pragma once
#include "CommonInclude.h"
#include "MJ_Entity.h"
#include "MJ_GameObject.h"
#include "MJ_Layer.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		void CreateLayers();

		std::vector<Layer*> mLayers;
	};
}



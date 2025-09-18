#include "MJ_PlayScene.h"
#include "MJ_Player.h"
#include "MJ_Transform.h"
#include "MJ_SpriteRenderer.h"

namespace MJ{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		Player* pl = new Player();
		Transform* tr = pl->AddComponent < Transform>();
		tr->SetPos(800, 450);
		tr->SetName(L"TR");

		SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(pl);

	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
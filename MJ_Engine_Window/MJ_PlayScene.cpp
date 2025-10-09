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
		Player* bg = new Player();
		Transform* tr = bg->AddComponent < Transform>();
		tr->SetPos(Vector2(0, 0));

		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\ndmjl\\source\\repos\\MJEngine\\Resources\\CloudOcean.png");
		AddGameObject(bg);
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
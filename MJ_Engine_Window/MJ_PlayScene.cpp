#include "MJ_PlayScene.h"
#include "MJ_Player.h"
#include "MJ_Transform.h"
#include "MJ_SpriteRenderer.h"
#include "MJ_Input.h"
#include "MJ_TitleScene.h"
#include "MJ_SceneManager.h"
#include "MJ_Object.h"

namespace MJ{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\JEI\\source\\repos\\Oneiric0102\\MJ_Engine\\Resources\\CloudOcean.png");

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"PlayScene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter() {

	}
	void PlayScene::OnExit() {
	}
}
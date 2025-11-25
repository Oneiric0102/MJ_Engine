#include "MJ_PlayScene.h"
#include "MJ_GameObject.h"
#include "MJ_Player.h"
#include "MJ_Transform.h"
#include "MJ_SpriteRenderer.h"
#include "MJ_Input.h"
#include "MJ_TitleScene.h"
#include "MJ_SceneManager.h"
#include "MJ_Object.h"
#include "MJ_Texture.h"
#include "MJ_Resources.h"
#include "MJ_PlayerScript.h"
#include "MJ_Camera.h"
#include "MJ_Renderer.h"
#include "MJ_Animator.h"

namespace MJ{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		/*SpriteRenderer* sr = mPlayer->AddComponent <SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));*/
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", catTexture, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);

		animator->PlayAnimation(L"CatFrontMove", true);

		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
		bgSr->SetTexture(bgTexture);

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
	}
	void PlayScene::OnEnter() {

	}
	void PlayScene::OnExit() {
	}
}
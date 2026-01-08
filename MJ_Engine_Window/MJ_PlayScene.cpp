#include "MJ_PlayScene.h"
#include "MJ_GameObject.h"
#include "MJ_Player.h"
#include "MJ_UIManager.h"
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
#include "MJ_Cat.h"
#include "MJ_CatScript.h"
#include "MJ_BoxCollider2D.h"
#include "MJ_CircleCollider2D.h"
#include "MJ_CollisionManager.h"
#include "MJ_Tile.h"
#include "MJ_TilemapRenderer.h"
#include "MJ_Rigidbody.h"
#include "MJ_Floor.h"
#include "MJ_FloorScript.h"
#include "MJ_AudioClip.h"
#include "MJ_AudioListener.h"
#include "MJ_AudioSource.h"

namespace MJ{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		mPlayer->AddComponent<AudioListener>();

		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		BoxCollider2D* playerCollider = mPlayer->AddComponent<BoxCollider2D>();
		playerCollider->SetSize(Vector2(0.5f, 0.5f));
		playerCollider->SetOffset(Vector2(-87.5f, -87.5f));

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTex, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"Idle", false);
		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 250.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(0.5f, 0.5f));

		mPlayer->AddComponent<Rigidbody>();
		
		Floor* floor = object::Instantiate<Floor>(eLayerType::Floor, Vector2(0.0f, 0.0f));
		floor->SetName(L"Floor");
		SpriteRenderer* floorSR = floor->AddComponent<SpriteRenderer>();
		floorSR->SetTexture(Resources::Find<graphics::Texture>(L"PixelMap"));

		AudioSource* as = floor->AddComponent<AudioSource>();

		plScript->SetPixelMapTexture(Resources::Find<graphics::Texture>(L"PixelMap"));

		AudioClip* ac = Resources::Load<AudioClip>(L"BGSound", L"..\\Resources\\Sound\\smw_bonus_game_end.wav");
		as->SetClip(ac);

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
		Scene::OnEnter();

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
		UIManager::Push(eUIType::Button);
	}
	void PlayScene::OnExit() {
		UIManager::Pop(eUIType::Button);
		Scene::OnExit();
	}
}
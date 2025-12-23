#include "MJ_PlayerScript.h"
#include "MJ_Input.h"
#include "MJ_Transform.h"
#include "MJ_Time.h"
#include "MJ_GameObject.h"
#include "MJ_Animator.h"
#include "MJ_Cat.h"
#include "MJ_CatScript.h"
#include "MJ_Object.h"
#include "MJ_Resources.h"
#include "MJ_Rigidbody.h"

namespace MJ {
	PlayerScript::PlayerScript()
		:mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{

	}
	PlayerScript::~PlayerScript() {

	}

	void PlayerScript::Initialize() {
	}

	void PlayerScript::Update() {
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState) {
		case MJ::PlayerScript::eState::Idle:
			idle();
			break;
		case MJ::PlayerScript::eState::Walk:
			move();
			break;
		case MJ::PlayerScript::eState::Sleep:
			break;
		case MJ::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case MJ::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}
	}

	void PlayerScript::LateUpdate() {
	}

	void PlayerScript::Render(HDC hdc) {
	}

	void PlayerScript::AttackEffect() {
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		CatScript* catSrc = cat->AddComponent<CatScript>();

		catSrc->SetPlayer(GetOwner());

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTex, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->PlayAnimation(L"SitDown", false);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());

		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		Vector2 mousePos = Input::GetMousePosition();
		catSrc->mDest = mousePos;
	}

	void PlayerScript::OnCollisionEnter(Collider* other) 
	{
	}
	void PlayerScript::OnCollisionStay(Collider* other) 
	{
	}
	void PlayerScript::OnCollisionExit(Collider* other) {

	}

	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
			CatScript* catSrc = cat->AddComponent<CatScript>();

			catSrc->SetPlayer(GetOwner());

			graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();
			catAnimator->CreateAnimation(L"DownWalk", catTex
				, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"RightWalk", catTex
				, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"UpWalk", catTex
				, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LeftWalk", catTex
				, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"SitDown", catTex
				, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"Grooming", catTex
				, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LayDown", catTex
				, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			catAnimator->PlayAnimation(L"SitDown", false);

			Transform* tr = GetOwner()->GetComponent<Transform>();

			cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

			Vector2 mousePos = Input::GetMousePosition();
			catSrc->mDest = mousePos;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

		if(Input::GetKey(eKeyCode::D))
		{
			rb->AddForce(Vector2(200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::A))
		{
			rb->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::W))
		{
			Vector2 velocity = rb->GetVelocity();
			velocity.y = -500.0f;
			rb->SetVelocity(velocity);
			rb->SetGround(false);
		}
		if (Input::GetKey(eKeyCode::S))
		{
			rb->AddForce(Vector2(0.0f, -200.0f));
		}
	}

	void PlayerScript::move() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

		if (Input::GetKey(eKeyCode::D))
		{
			rb->AddForce(Vector2(200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::A))
		{
			rb->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::W))
		{
			rb->AddForce(Vector2(0.0f, 200.0f));
		}
		if (Input::GetKey(eKeyCode::S))
		{
			rb->AddForce(Vector2(0.0f, -200.0f));
		}

		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A) || Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}	
	}

	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}
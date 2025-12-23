#include "MJ_CameraScript.h"
#include "MJ_Input.h"
#include "MJ_Transform.h"
#include "MJ_Time.h"
#include "MJ_GameObject.h"
#include "MJ_Animator.h"
#include "MJ_Cat.h"
#include "MJ_CatScript.h"
#include "MJ_Object.h"
#include "MJ_Resources.h"

namespace MJ
{
	CameraScript::CameraScript() 
	{
	}
	CameraScript::~CameraScript()
	{
	}

	void CameraScript::Initialize()
	{
	}
	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);
	}

	void CameraScript::LateUpdate()
	{
	}
	void CameraScript::Render(HDC hdc)
	{
	}
}
#include "MJ_Player.h"
#include "MJ_Input.h"
#include "MJ_Transform.h"
#include "MJ_Time.h"

namespace MJ
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

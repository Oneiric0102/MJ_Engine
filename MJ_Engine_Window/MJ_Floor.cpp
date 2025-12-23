#include "MJ_Floor.h"
#include "MJ_Cat.h"
#include "MJ_Input.h"
#include "MJ_Transform.h"
#include "MJ_Time.h"

namespace MJ
{
	Floor::Floor() 
	{
	}
	Floor::~Floor()
	{
	}

	void Floor::Initialize()
	{
		GameObject::Initialize();
	}
	void Floor::Update()
	{
		GameObject::Update();
	}
	void Floor::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Floor::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
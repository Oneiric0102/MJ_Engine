#include "MJ_Collider.h"
#include "MJ_GameObject.h"
#include "MJ_Script.h"

namespace MJ
{
	UINT Collider::CollisionID = 1;

	Collider::Collider(eColliderType type)
		: Component(enums::eComponentType::Colider)
		, mType(type)
		, mID(CollisionID++)
		, mSize(Vector2::One)
	{

	}

	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
	}

	void Collider::Update()
	{
	}

	void Collider::LateUpdate()
	{
	}

	void Collider::Render(HDC hdc)
	{
	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}
	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(other);
	}
	void Collider::OnCollisionExit(Collider * other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(other);
	}
}
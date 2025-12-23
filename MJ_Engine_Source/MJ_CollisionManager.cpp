#include "MJ_CollisionManager.h"
#include "MJ_Scene.h"
#include "MJ_SceneManager.h"
#include "MJ_GameObject.h"
#include "MJ_Collider.h"
#include "MJ_Transform.h"

namespace MJ {
	std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
		int a = 1;
		int b = a << 1;
	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0;row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{

	}

	void CollisionManager::Render(HDC hdc)
	{

	}

	void CollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
	}

	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = SceneManager::GetGameObjects(left);
		const std::vector<GameObject*>& rights = SceneManager::GetGameObjects(right);

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;
				Collider* rightCol = right->GetComponent<Collider>();

				if (rightCol == nullptr)
					continue;
				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}

	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		if (Intersect(left, right))
		{
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset() + leftSize / 2.0f;
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset() + rightSize / 2.0f;

		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Rect2D)
		{
			if (
				fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f)
				)
			{
				return true;
			}
		}
		if (leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Circle2D)
		{
			float distance = (leftPos - rightPos).length();

			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		if (
			leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D
			|| leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D
			)
		{
			Vector2 circlePos;
			Vector2 circleSize;
			Vector2 boxPos;
			Vector2 boxSize;

			if (leftType == enums::eColliderType::Circle2D)
			{
				circlePos = leftPos;
				circleSize = leftSize;
				boxPos = rightPos;
				boxSize = rightSize;
			}
			else
			{
				circlePos = rightPos;
				circleSize = rightSize;
				boxPos = leftPos;
				boxSize = leftSize;
			}

			float minX = boxPos.x - boxSize.x / 2.0f;
			float maxX = boxPos.x + boxSize.x / 2.0f;
			float minY = boxPos.y - boxSize.y / 2.0f;
			float maxY = boxPos.y + boxSize.y / 2.0f;

			Vector2 closestPoint = Vector2(max(minX, min(maxX, circlePos.x))
					, max(minY, min(maxY, circlePos.y)));

			float distance = (circlePos - closestPoint).length();
			if (distance <= circleSize.x / 2.0f)
			{
				return true;
			}
		}

		
		return false;
	}
}

#include "MJ_SpriteRenderer.h"
#include "MJ_Transform.h"
#include "MJ_GameObject.h"

namespace MJ {
	SpriteRenderer::SpriteRenderer()
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		HBRUSH purpleBrush = CreateSolidBrush(RGB(255, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, purpleBrush);

		HPEN randPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, randPen);

		Transform* tr = GetOwner()->GetComponent <Transform>();
		Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(purpleBrush);
		DeleteObject(randPen);
	}

}


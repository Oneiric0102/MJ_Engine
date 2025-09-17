#include "MJ_Bullet.h"
#include "MJ_Input.h"
#include "MJ_Time.h"
namespace MJ{
	Bullet::Bullet() {

	}
	Bullet::~Bullet() {

	}

	void Bullet::Update() {
		const int speed = 500.0f;
		mY -= speed * Time::DeltaTime();
	}

	void Bullet::LateUpdate() {

	}

	void Bullet::Render(HDC hdc) {
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		HPEN bluePen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

		Ellipse(hdc, 140 + mX, 80 + mY, 160 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(redBrush);
		DeleteObject(bluePen);
	}
}
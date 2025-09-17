#include "MJ_GameObject.h"
#include "MJ_Input.h"
#include "MJ_Time.h"
namespace MJ {
	GameObject::GameObject()
	: mX(0),mY(0)
	{
	}
	GameObject::~GameObject() {
	}

	void GameObject::Update() {
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A)) {
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D)) {
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W)) {
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S)) {
			mY += speed * Time::DeltaTime();
		}

		//위쪽 방향키 누르면 총알 추가
		if (Input::GetKeyDown(eKeyCode::Up)) {
			Bullet createdBullet = Bullet();
			createdBullet.SetPosition(mX, mY);
			mBullets.push_back(createdBullet);
		}

		//총알 위치 업데이트
		for (Bullet& bullet : mBullets) {
			bullet.Update();
		}

		//화면 밖으로 나간 총알 제거
		auto it = std::remove_if(mBullets.begin(), mBullets.end(), [](const Bullet& b) {
			return b.GetPositionY() < -100;
			});
		if (it != mBullets.end()) {
			mBullets.erase(it, mBullets.end());
		}		
	}
	void GameObject::LateUpdate() {

	}
	void GameObject::Render(HDC hdc) {
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(blueBrush);
		DeleteObject(redPen);

		for (Bullet& bullet : mBullets) {
			bullet.Render(hdc);
		}
	}
}
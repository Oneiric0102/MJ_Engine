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

		//���� ����Ű ������ �Ѿ� �߰�
		if (Input::GetKeyDown(eKeyCode::Up)) {
			Bullet createdBullet = Bullet();
			createdBullet.SetPosition(mX, mY);
			mBullets.push_back(createdBullet);
		}

		//�Ѿ� ��ġ ������Ʈ
		for (Bullet& bullet : mBullets) {
			bullet.Update();
		}

		//ȭ�� ������ ���� �Ѿ� ����
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
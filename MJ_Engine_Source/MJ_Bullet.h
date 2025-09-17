#pragma once
#include "CommonInclude.h"
namespace MJ {
	class Bullet
	{
	public:
		Bullet();
		~Bullet();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y) {
			mX = x;
			mY = y;
		}

		float GetPositionX() const {
			return mX;
		}

		float GetPositionY() const {
			return mY;
		}

	private:
		float mX;
		float mY;
	};
}


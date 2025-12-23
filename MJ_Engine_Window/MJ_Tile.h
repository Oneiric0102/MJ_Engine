#pragma once
#include "..\\MJ_Engine_Source\\MJ_GameObject.h"

namespace MJ
{
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetIndexPosition(int x, int y);
	private:

	};
}

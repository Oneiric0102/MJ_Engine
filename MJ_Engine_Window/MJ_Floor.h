#pragma once
#include "..\\MJ_Engine_Source\\MJ_GameObject.h"

namespace MJ {
	class Floor : public GameObject
	{
	public:
		Floor();
		~Floor();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
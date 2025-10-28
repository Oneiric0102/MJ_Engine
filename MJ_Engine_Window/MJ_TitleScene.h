#pragma once
#include "..\\MJ_Engine_Source\\\MJ_Scene.h"

namespace MJ {
	class TitleScene : public Scene {
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}



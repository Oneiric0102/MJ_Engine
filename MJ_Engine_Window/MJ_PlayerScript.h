#pragma once
#include "..\\MJ_Engine_Source\\MJ_Script.h"

namespace MJ
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}
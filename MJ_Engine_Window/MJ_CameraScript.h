#pragma once
#include "..\\MJ_Engine_Source\\\MJ_Script.h"
#include "..\\MJ_Engine_Source\\MJ_Transform.h"

namespace MJ
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
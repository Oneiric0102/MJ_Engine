#pragma once
#include "..\\MJ_Engine_Source\\MJ_Resources.h"
#include "..\\MJ_Engine_Source\\MJ_Texture.h"

namespace MJ {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\CatAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}
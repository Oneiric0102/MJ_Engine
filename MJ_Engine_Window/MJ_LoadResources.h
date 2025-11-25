#pragma once
#include "..\\MJ_Engine_Source\\MJ_Resources.h"
#include "..\\MJ_Engine_Source\\MJ_Texture.h"

namespace MJ {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PacMan", L"..\\Resources\\img\\pacman\\0.png");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
	}
}
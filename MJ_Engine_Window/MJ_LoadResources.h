#pragma once
#include "..\\MJ_Engine_Source\\MJ_Resources.h"
#include "..\\MJ_Engine_Source\\MJ_Texture.h"

namespace MJ {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\JEI\\source\\repos\\Oneiric0102\\MJ_Engine\\Resources\\CloudOcean.png");
	}
}
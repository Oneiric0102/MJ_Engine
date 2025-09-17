#pragma once
#include "..\\MJ_Engine_Source\MJ_SceneManager.h"
#include "MJ_PlayScene.h"

namespace MJ {
	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
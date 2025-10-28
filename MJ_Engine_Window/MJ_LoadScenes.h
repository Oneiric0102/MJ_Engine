#pragma once
#include "..\\MJ_Engine_Source\MJ_SceneManager.h"
#include "MJ_PlayScene.h"
#include "MJ_TitleScene.h"

namespace MJ {
	void LoadScenes() {
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
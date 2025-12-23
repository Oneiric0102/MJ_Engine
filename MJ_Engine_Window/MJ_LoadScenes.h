#pragma once
#include "..\\MJ_Engine_Source\MJ_SceneManager.h"
#include "MJ_PlayScene.h"
#include "MJ_TitleScene.h"
#include "MJ_ToolScene.h"

namespace MJ {
	void LoadScenes() {
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<ToolScene>(L"ToolScene");

		//SceneManager::LoadScene(L"ToolScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}
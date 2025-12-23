#include "MJ_TitleScene.h"
#include "MJ_Input.h"
#include "MJ_PlayScene.h"
#include "MJ_SceneManager.h"

namespace MJ {
	TitleScene::TitleScene() {

	}
	TitleScene::~TitleScene() {

	}
	void TitleScene::Initialize() {
		Scene::Initialize();
	}
	void TitleScene::Update() {
		Scene::Update();
	}
	void TitleScene::LateUpdate() {
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC hdc) {
		Scene::Render(hdc);
		wchar_t str[50] = L"TitleScene";
		TextOut(hdc, 0, 0, str, 11);
	}

	void TitleScene::OnEnter() {
		Scene::OnEnter();
	}
	void TitleScene::OnExit() {
		Scene::OnExit();
	}
}
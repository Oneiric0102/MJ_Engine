#pragma once
#include "MJ_Entity.h"
#include "MJ_Component.h"

namespace MJ {
	class SpriteRenderer : public Component {
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:


	};
}
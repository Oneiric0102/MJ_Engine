#pragma once
#include "CommonInclude.h"
using namespace MJ::math;

namespace MJ {
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	}; 
}



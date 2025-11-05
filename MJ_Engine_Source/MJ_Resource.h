#pragma once
#include "MJ_Entity.h"
namespace MJ {
	class Resource abstract : public Entity {
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource() override;

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring GetPath(const std::wstring& path) { return mPath; };
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}


#pragma once

#include <Geode/Geode.hpp>

namespace DeltaruneProphecy {
	class ProphecyPanel : public cocos2d::CCNode {
	private:
		bool init(const std::string& text);
	public:
		static ProphecyPanel* create(const std::string& text);
	};
}
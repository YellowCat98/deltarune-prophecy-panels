#pragma once

#include <Geode/Geode.hpp>

namespace DeltaruneProphecy {
	class ProphecyPanel : public cocos2d::CCNode {
	private:
		bool init(cocos2d::CCSprite* sprite, const std::string& text);
	public:
		static ProphecyPanel* create(cocos2d::CCSprite* sprite, const std::string& text);
	};
}
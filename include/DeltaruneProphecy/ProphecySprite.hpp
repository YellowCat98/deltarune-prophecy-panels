#pragma once

#include <Geode/Geode.hpp>
#include <DeltaruneProphecy/ProphecyPanelReal.hpp>

namespace DeltaruneProphecy {
	// this one floats btw
	class ProphecySprite : public cocos2d::CCClippingNode {
	private:
		bool init(cocos2d::CCNode* sprite, bool text);
		ProphecyPanelReal* panel;
	public:
		static ProphecySprite* create(CCNode* sprite, bool text);

		ProphecyPanelReal* getPanel();
	};
}
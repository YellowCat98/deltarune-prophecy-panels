#pragma once

#include <Geode/Geode.hpp>
#include <DeltaruneProphecy/ProphecyPanelReal.hpp>

namespace DeltaruneProphecy {
	class ProphecySprite : public cocos2d::CCClippingNode { // we need dat ccrgbaprotocol so its affected by colore
	private:
		bool init(cocos2d::CCNode* sprite, bool text);
		ProphecyPanelReal* panel;
	public:
		static ProphecySprite* create(CCNode* sprite, bool text);

		ProphecyPanelReal* getPanel();
	};
}
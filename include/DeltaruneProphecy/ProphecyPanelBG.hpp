#pragma once

#include <Geode/Geode.hpp>

namespace DeltaruneProphecy {
	class ProphecyPanelBG : public cocos2d::CCSprite {
	private:
		bool init() override;
		void update(float dt) override;
		float scrollX;
		float scrollY;
	public:
		static ProphecyPanelBG* create();
	};
}
#pragma once

#include <Geode/Geode.hpp>

namespace DeltaruneProphecy {
	// same thing as ProphecyPanelBG just that the effect is reversed and applies different modifications to the sprite
	class ProphecyPanelReal : public cocos2d::CCSprite {
	private:
		bool init(bool text);
		void update(float dt) override;
		void draw() override;
		float scrollX;
		float scrollY;
		bool text;
	public:
		static ProphecyPanelReal* create(bool text = false);
	};
}
#pragma once

#include <Geode/Geode.hpp>

class DogLayer : public cocos2d::CCLayerColor {
private:
	bool init() override;

	void loadProphecy();
	geode::LazySprite* sprite;
	cocos2d::CCLayerColor* opaqueLayer; // this only exists because i want to chang ProphecyPanel's opacity and unfortunately i am not gonna deal with it
	bool isIn;

	bool ccTouchBegan(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	void registerWithTouchDispatcher() override;
public:
	static DogLayer* create();

	void comeInVro();
	void GETOUT();
};
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <DeltaruneProphecy/ProphecyPanel.hpp>

using namespace geode::prelude;

class $modify(MyLoadingLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		return true;
	}

	void onMoreGames(CCObject* sender) {
		auto scene = CCScene::create();
		auto prophecy = DeltaruneProphecy::ProphecyPanel::create(CCSprite::create("test_spr.png"_spr), "THE FLOWER MAN,\nTRAPPED IN ASYLUM.");
		prophecy->setScale(4.0f);
		prophecy->setPosition(CCDirector::get()->getWinSize()/2);

		scene->addChild(prophecy);

		CCDirector::get()->replaceScene(scene);
	}
};
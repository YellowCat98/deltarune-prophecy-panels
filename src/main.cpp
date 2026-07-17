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
		auto sprite = LazySprite::create({0.0f, 0.0f}); // lazysprite handles it
		sprite->loadFromFile(Mod::get()->getSettingValue<std::filesystem::path>("sprite"));

		sprite->setLoadCallback([sprite](Result<> res) {
			if (res.isErr()) return;
			sprite->removeFromParentAndCleanup(true);

			auto scene = CCScene::create();
			auto prophecy = DeltaruneProphecy::ProphecyPanel::create(sprite, "THE FLOWER MAN,\nTRAPPED IN ASYLUM.");
			prophecy->setScale(4.0f);
			prophecy->setPosition(CCDirector::get()->getWinSize()/2);

			scene->addChild(prophecy);

			CCDirector::get()->replaceScene(scene);
		});

		this->addChild(sprite); // only go to the prophecy panel once its loaded and the only way to do that is by adding this somewhere (gets removes on load tho)

	}
};
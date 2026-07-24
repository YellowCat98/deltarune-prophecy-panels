#include "Geode/cocos/touch_dispatcher/CCTouch.h"
#include "Geode/cocos/touch_dispatcher/CCTouchDispatcher.h"
#include <DogLayer.hpp>
#include <DeltaruneProphecy/ProphecyPanel.hpp>
#include <globals.hpp>

using namespace geode::prelude;

bool DogLayer::init() {
	if (!CCLayerColor::init()) return false;
	this->setTouchPriority(CCTouchDispatcher::get()->getTargetPrio() - 1);
	this->setID("DogLayer");
	this->setColor({0, 0, 0});
	this->setOpacity(255);

	sprite = LazySprite::create({0.0f, 0.0f}); // lazysprite handles le size
	sprite->loadFromFile(Mod::get()->getSettingValue<std::filesystem::path>("sprite"));

	sprite->setLoadCallback([this](Result<> res) {
		if (res.isErr()) {
			log::info("Error creating Prophecy: {}", res.unwrapErr());
			return;
		}
		sprite->removeFromParentAndCleanup(true);

		this->loadProphecy();
		this->comeInVro();
	});

	this->addChild(sprite); // only go to the prophecy panel once its loaded and the only way to do that is by adding this somewhere (gets removes on load tho)

	opaqueLayer = CCLayerColor::create();
	opaqueLayer->setZOrder(1);
	opaqueLayer->setColor({0, 0, 0});
	opaqueLayer->setOpacity(255);
	this->addChild(opaqueLayer);
	return true;
}

void DogLayer::loadProphecy() {
	auto prophecy = DeltaruneProphecy::ProphecyPanel::create(sprite, Mod::get()->getSettingValue<std::string>("text"));
	prophecy->setScale(6.7f);
	prophecy->setPosition(CCDirector::get()->getWinSize()/2);

	this->addChild(prophecy);
}

void DogLayer::comeInVro() {
	if (isIn) return;
	this->setTouchEnabled(true);
	opaqueLayer->setOpacity(255);
	opaqueLayer->runAction(CCFadeOut::create(0.25f));
	this->setVisible(true);
	isIn = true;
}

void DogLayer::GETOUT() {
	if (!isIn) return;
	this->setTouchEnabled(false);
	globals::transitionLayer->runAction(CCSequence::create(
		CCFadeIn::create(0.25f),
		CallFuncExt::create([] { globals::dog->setVisible(false); }),
		CCFadeOut::create(0.25f),
		CallFuncExt::create([this] { isIn = false; }),
		nullptr
	));
}

bool DogLayer::ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
	this->GETOUT();
	return true;
}

void DogLayer::registerWithTouchDispatcher() {
	CCTouchDispatcher::get()->addTargetedDelegate(this, this->getTouchPriority(), true);
}

DogLayer* DogLayer::create() {
	auto ret = new DogLayer();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}
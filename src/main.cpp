#include "Geode/loader/SettingV3.hpp"
#include <Geode/Geode.hpp>
#include <DogLayer.hpp>
#include <globals.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
	ButtonSettingPressedEventV3(Mod::get(), "buttons").listen([](auto buttonKey) {
		if (buttonKey == "reload-btn") { // this is always gonna be true but just in case i decide to add a new button in the future
			globals::recreateDog();
		}
	}).leak();
}

// globals are set and defined here

void globals::recreateDog() {
	if (globals::dog && globals::modBullshit) {
		globals::dog->removeFromParentAndCleanup(true);
		globals::dog = DogLayer::create();
		globals::modBullshit->addChild(globals::dog);
	}
}

std::string globals::createProphecyText(const std::string& text) {
	std::string ret = text;
	std::ranges::replace(ret, '#', '\n');
	return ret;
}

$on_game(Loaded) {
	auto overlay = OverlayManager::get();
	globals::modBullshit = CCNode::create();
	globals::modBullshit->setID(""_spr);
	overlay->addChild(globals::modBullshit);

	globals::dog = DogLayer::create();
	globals::modBullshit->addChild(globals::dog);

	globals::transitionLayer = CCLayerColor::create();
	globals::transitionLayer->setColor({0,0,0});
	globals::transitionLayer->setID("transition-layer");
	globals::modBullshit->addChild(globals::transitionLayer);
}
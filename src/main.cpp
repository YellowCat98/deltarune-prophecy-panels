#include <Geode/Geode.hpp>
#include <DogLayer.hpp>
#include <globals.hpp>

using namespace geode::prelude;

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
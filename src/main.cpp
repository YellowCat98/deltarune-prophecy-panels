#include <Geode/Geode.hpp>
#include <DogLayer.hpp>
#include <globals.hpp>

using namespace geode::prelude;

$on_game(Loaded) {
    auto overlay = OverlayManager::get();
    auto dog = DogLayer::create();
    overlay->addChild(dog);
    globals::dog = dog;
}
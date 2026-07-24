#include <DogLayer.hpp>
#include <DeltaruneProphecy/ProphecyPanel.hpp>
#include <globals.hpp>

using namespace geode::prelude;

bool DogLayer::init() {
    if (!CCLayerColor::init()) return false;
    this->setKeypadEnabled(true);
    this->setID("DogLayer"_spr);
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
	});

	this->addChild(sprite); // only go to the prophecy panel once its loaded and the only way to do that is by adding this somewhere (gets removes on load tho)

    return true;
}

void DogLayer::loadProphecy() {
	auto prophecy = DeltaruneProphecy::ProphecyPanel::create(sprite, Mod::get()->getSettingValue<std::string>("text"));
	prophecy->setScale(6.7f);
	prophecy->setPosition(CCDirector::get()->getWinSize()/2);

	this->addChild(prophecy);
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
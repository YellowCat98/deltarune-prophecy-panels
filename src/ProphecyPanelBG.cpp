#include <DeltaruneProphecy/ProphecyPanelBG.hpp>

using namespace geode::prelude;
using namespace DeltaruneProphecy;

bool ProphecyPanelBG::init() {
	if (!CCSprite::initWithFile("IMAGE_DEPTH_EXTEND_SEAMLESS.png"_spr)) return false;
	this->setOpacity(125.0f);
	this->getTexture()->setAliasTexParameters();

	auto texture = this->getTexture();
	ccTexParams params = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
	texture->setTexParameters(&params);

	auto tint1 = CCTintTo::create(0.5f, 139, 233, 239);
	auto tint2 = CCTintTo::create(0.5f, 23, 237, 255);

	auto sequence = CCSequence::create(tint1, tint2, nullptr);
	auto loop = CCRepeatForever::create(sequence);

	this->runAction(loop);

	this->scheduleUpdate();
	return true;
}

void ProphecyPanelBG::update(float dt) {
	CCSprite::update(dt);

    scrollX += 5.0f * dt;
    scrollY += 5.0f * dt;

	auto rect = this->getTextureRect();

	rect.origin.x = scrollX;
	rect.origin.y = scrollY;

	this->setTextureRect(rect);
}

ProphecyPanelBG* ProphecyPanelBG::create() {
	auto ret = new ProphecyPanelBG();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}
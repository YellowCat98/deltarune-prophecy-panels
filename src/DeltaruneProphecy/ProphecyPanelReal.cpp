#include <DeltaruneProphecy/ProphecyPanelReal.hpp>

using namespace geode::prelude;
using namespace DeltaruneProphecy;

bool ProphecyPanelReal::init(bool text) {
	if (!CCSprite::initWithFile("IMAGE_DEPTH_EXTEND_MONO_SEAMLESS_POW2.png"_spr)) return false;
	this->getTexture()->setAliasTexParameters();
	this->text = text;
	if (text) this->setColor({0x00, 0xFF, 0x96});
	else this->setColor({0x00, 0xD0, 0xFF});
	this->setScale(text ? 5.0f : 1.5f);

	auto texture = this->getTexture();

	ccTexParams params = { static_cast<GLuint>(text ? GL_NEAREST : GL_NEAREST), static_cast<GLuint>(text ? GL_NEAREST : GL_NEAREST), GL_REPEAT, GL_REPEAT };
	texture->setTexParameters(&params);

	if (text) scrollX = 20.0f;

	this->scheduleUpdate();
	return true;
}

void ProphecyPanelReal::update(float dt) {
	CCSprite::update(dt);

    scrollX += 3.0f * dt;
    if (!text) scrollY += 3.0f * dt;

	auto rect = this->getTextureRect();

	rect.origin.x = -scrollX;
	rect.origin.y = -scrollY;

	this->setTextureRect(rect);
}

void ProphecyPanelReal::draw() {
	text ? this->setBlendFunc({GL_ONE, GL_ONE_MINUS_SRC_COLOR}) : this->setBlendFunc({GL_ONE, GL_ONE});
	for (int i = 0; i < (text ? 5 : 3); ++i) {
		CCSprite::draw();
	}
}

ProphecyPanelReal* ProphecyPanelReal::create(bool text) {
	auto ret = new ProphecyPanelReal();
	if (ret && ret->init(text)) {
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}
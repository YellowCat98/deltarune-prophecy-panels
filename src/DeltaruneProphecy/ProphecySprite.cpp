#include <DeltaruneProphecy/ProphecySprite.hpp>
#include <DeltaruneProphecy/ProphecyPanelBG.hpp>
#include <DeltaruneProphecy/ProphecyPanelReal.hpp>

using namespace geode::prelude;
using namespace DeltaruneProphecy;

bool ProphecySprite::init(CCNode* sprite, bool text) {
	if (!CCClippingNode::init(sprite)) return false;
	this->setAnchorPoint({0.5f, 0.5f});
	this->setAlphaThreshold(0.5f);

	auto prophecyReal = ProphecyPanelReal::create(text);
	this->addChild(prophecyReal);
	this->panel = prophecyReal;

	return true;
}

ProphecyPanelReal* ProphecySprite::getPanel() {
	return panel;
}

ProphecySprite* ProphecySprite::create(CCNode* sprite, bool text) {
	auto ret = new ProphecySprite();
	if (ret && ret->init(sprite, text)) {
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}
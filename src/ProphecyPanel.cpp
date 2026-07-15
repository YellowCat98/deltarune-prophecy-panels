#include <DeltaruneProphecy/ProphecyPanel.hpp>
#include <DeltaruneProphecy/ProphecyPanelBG.hpp>
#include <DeltaruneProphecy/ProphecyPanelReal.hpp>
#include <DeltaruneProphecy/ProphecySprite.hpp>

using namespace geode::prelude;
using namespace DeltaruneProphecy;

bool ProphecyPanel::init(const std::string& text) {
	if (!CCNode::init()) return false;
	this->setAnchorPoint({0.5f, 0.5f});
	float animationDuration = 1.25f;

	auto animated = CCNode::create();
	animated->setID("animated");

	auto evenMoreAnimatedInsideAnimated = CCNode::create();
	evenMoreAnimatedInsideAnimated->setID("more-animaeted");

	auto spr = CCSprite::create("test_spr.png"_spr);
	auto params = ccTexParams{GL_NEAREST, GL_NEAREST, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE};
	spr->getTexture()->setTexParameters(&params);
	auto sprRect = spr->getTextureRect();

	auto fancySpr = ProphecySprite::create(spr, false);
	fancySpr->setID("fancy-sprite");

	auto shadow1 = ProphecySprite::create(spr, false);
	shadow1->setID("shadow-1");
	shadow1->getPanel()->setOpacity(30);

	auto start1 = shadow1->getPosition();

	auto up1 = CCEaseSineInOut::create(CCMoveTo::create(animationDuration, start1 + CCPoint(2.0f, -2.0f)));
	auto down1 = CCEaseSineInOut::create(CCMoveTo::create(animationDuration, start1 + CCPoint(-2.0f, 2.0f)));
	auto sequence1 = CCSequence::create(up1, down1, nullptr);

	shadow1->runAction(CCRepeatForever::create(sequence1));

	auto shadow2 = ProphecySprite::create(spr, false);
	shadow2->setID("shadow-2");
	shadow2->getPanel()->setOpacity(30);

	auto start2 = shadow2->getPosition();

	auto up2 = CCEaseSineInOut::create(CCMoveTo::create(animationDuration, start2 + CCPoint(1.0f, -1.0f)));
	auto down2 = CCEaseSineInOut::create(CCMoveTo::create(animationDuration, start2 + CCPoint(-1.0f, 1.0f)));
	auto sequence2 = CCSequence::create(up2, down2, nullptr);

	shadow2->runAction(CCRepeatForever::create(sequence2));

	evenMoreAnimatedInsideAnimated->addChild(fancySpr);
	evenMoreAnimatedInsideAnimated->addChild(shadow1);
	evenMoreAnimatedInsideAnimated->addChild(shadow2);

	// @geode-ignore(unknown-resource)
	auto label = CCLabelBMFont::create("", "prophecyFont.fnt"_spr);
	label->getTexture()->setTexParameters(&params);
	label->setScale(0.35f);
	label->setAnchorPoint({0.5f, 0.0f});
	label->setAlignment(CCTextAlignment::kCCTextAlignmentCenter);
	label->setExtraKerning(5);
	label->setString(text.c_str()); // i need to set string after setting kerning

	auto fancyLabel = ProphecySprite::create(label, true);
	fancyLabel->setPositionY(spr->getContentHeight() - 5.0f); // CCClippingNode doesnt have a size so were using the sprite's
	fancyLabel->setID("fancy-label");

	animated->addChild(evenMoreAnimatedInsideAnimated);
	animated->addChild(fancyLabel);

	auto up = CCEaseSineInOut::create(CCMoveBy::create(animationDuration, {0, 1.5f}));
	auto down = CCEaseSineInOut::create(CCMoveBy::create(animationDuration, {0, -1.5f}));

	auto sequence = CCSequence::create(up, down, nullptr);

	animated->runAction(CCRepeatForever::create(sequence));

	auto prophecy = ProphecyPanelBG::create();
	prophecy->setID("bg");

	auto prophecyRect = prophecy->getTextureRect();
	prophecyRect.size = CCSize{sprRect.size.width + 5.0f, sprRect.size.height + 5.0f};
	prophecy->setTextureRect(prophecyRect);

	auto fade = CCSprite::create("FADE.png"_spr);
	fade->setPosition(prophecy->getContentSize()/2);
	fade->setScaleX(prophecy->getContentSize().width / fade->getContentSize().width);
	fade->setScaleY(prophecy->getContentSize().height / fade->getContentSize().height);
	fade->setBlendFunc({ GL_ZERO, GL_SRC_ALPHA });
	prophecy->addChild(fade);

	this->addChild(prophecy);
	this->addChild(animated);

	return true;
}

ProphecyPanel* ProphecyPanel::create(const std::string& text) {
	auto ret = new ProphecyPanel();
	if (ret && ret->init(text)) {
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}
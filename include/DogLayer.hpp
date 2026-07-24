#pragma once

#include <Geode/Geode.hpp>

class DogLayer : public cocos2d::CCLayerColor {
private:
    bool init() override;

    void loadProphecy();
    geode::LazySprite* sprite;
    cocos2d::CCLayerColor* opaqueLayer; // this only exists because i want to chang ProphecyPanel's opacity and unfortunately i am not gonna deal with it
public:
    static DogLayer* create();

    void fancierSetVisible(bool visible); // fancy!
};
#pragma once

#include <Geode/Geode.hpp>

class DogLayer : public cocos2d::CCLayerColor {
private:
    bool init() override;
    void loadProphecy();
    geode::LazySprite* sprite;
public:
    static DogLayer* create();
};
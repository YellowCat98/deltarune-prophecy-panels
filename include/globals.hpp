#pragma once

#include <DogLayer.hpp>

struct globals {
	inline static bool passNextScene;
	inline static cocos2d::CCNode* modBullshit; // where i place everything related to the mod
	inline static DogLayer* dog;
	inline static cocos2d::CCLayerColor* transitionLayer; // a desperate attempt at not wanting to handle color bs (the finale)
	static std::string createProphecyText(const std::string& text); // just turns "hello#world" into "hello\nworld"
	static void recreateDog();
};
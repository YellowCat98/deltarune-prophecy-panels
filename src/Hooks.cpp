#include <DogLayer.hpp>
#include <globals.hpp>
#include <arc/prelude.hpp>
#include <Geode/modify/AppDelegate.hpp>
#include <Geode/modify/LoadingLayer.hpp>

using namespace geode::prelude;

class $modify(LoadingLayer) {
	bool init(bool withRefresh) {
		if (!LoadingLayer::init(withRefresh)) return false;
		if (withRefresh) {

		}
		return true;
	}
};

class $modify(DogDelegate, AppDelegate) {
	// the ultimate technique
	// not touching the scene stack or hooking replaceScene and all that stuff!
	void willSwitchToScene(CCScene* pScene) {
		AppDelegate::willSwitchToScene(pScene);
		if (pScene && pScene->getChildByID("LoadingLayer")) return; // i have absolutely no idea why willSwitchToScene is called with nullptr
		if (globals::dog) globals::dog->comeInVro();
		async::spawn(arc::sleep(asp::Duration::fromSecs(120)), [this]() {
			if (globals::dog) globals::dog->GETOUT();
		});
	}
};
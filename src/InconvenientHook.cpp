#include <DogLayer.hpp>
#include <Geode/binding/AppDelegate.hpp>
#include <globals.hpp>
#include <arc/prelude.hpp>
#include <Geode/modify/AppDelegate.hpp>

using namespace geode::prelude;

class $modify(AppDelegate) {
	// the ultimate technique
	// not touching the scene stack or hooking replaceScene and all that stuff!
	void willSwitchToScene(CCScene* pScene) {
		AppDelegate::willSwitchToScene(pScene);
		if (globals::dog) globals::dog->fancierSetVisible(true);
		async::spawn(arc::sleep(asp::Duration::fromSecs(5)), []() {
			if (globals::dog) globals::dog->fancierSetVisible(false);
		});
	}
};
#include <DogLayer.hpp>
#include <Geode/binding/AppDelegate.hpp>
#include <globals.hpp>
#include <arc/prelude.hpp>
#include <Geode/modify/AppDelegate.hpp>

using namespace geode::prelude;

class $modify(AppDelegate) {
	void willSwitchToScene(CCScene* pScene) {
		AppDelegate::willSwitchToScene(pScene);
		if (globals::dog) globals::dog->setVisible(true);
		async::spawn(arc::sleep(asp::Duration::fromSecs(5)), []() {
			log::info("dog");
			if (globals::dog) globals::dog->setVisible(false);
		});
	}
};
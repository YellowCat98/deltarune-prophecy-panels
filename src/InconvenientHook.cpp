#include <DogLayer.hpp>
#include <Geode/binding/AppDelegate.hpp>
#include <globals.hpp>
#include <arc/prelude.hpp>
#include <Geode/modify/AppDelegate.hpp>

using namespace geode::prelude;

class $modify(DogDelegate, AppDelegate) {
	// the ultimate technique
	// not touching the scene stack or hooking replaceScene and all that stuff!
	void willSwitchToScene(CCScene* pScene) {
		AppDelegate::willSwitchToScene(pScene);
		if (globals::dog) globals::dog->fancierSetVisible(true);
		async::spawn(arc::sleep(asp::Duration::fromMillis(2500)), [this]() {
			if (globals::dog) {
				globals::transitionLayer->runAction(CCSequence::create(
					CCFadeIn::create(0.25f),
					CallFuncExt::create([]() {
						globals::dog->setVisible(false);
					}),
					CCFadeOut::create(0.25f),
					nullptr
				));
			}
		});
	}
};
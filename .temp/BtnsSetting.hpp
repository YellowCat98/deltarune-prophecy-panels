#pragma once

// based off SerpentLua https://github.com/YellowCat98/SerpentLua/blob/main/src/internal/SettingsIdk.cpp

#include <Geode/Geode.hpp>

class BtnsSettingV3 : public geode::SettingV3 {
public:
	static geode::Result<std::shared_ptr<geode::SettingV3>> parse(std::string const& key, std::string const& modID, matjson::Value const& json);
	bool load(matjson::Value const& json) override;
	bool save(matjson::Value& json) const override;
	bool isDefaultValue() const override;
	void reset() override;
	geode::SettingNodeV3* createNode(float width) override;
};

class BtnsSettingNodeV3 : public geode::SettingNodeV3 {
protected:
	bool init(std::shared_ptr<BtnsSettingV3> setting, float width);
	void updateState(cocos2d::CCNode* invoker) override;
	void onCommit() override;
	void onResetToDefault() override;

	geode::async::TaskHolder<geode::utils::web::WebResponse> listener;

public:
	static BtnsSettingNodeV3* create(std::shared_ptr<BtnsSettingV3> setting, float width);
	bool hasUncommittedChanges() const override;
	bool hasNonDefaultValue() const override;
};
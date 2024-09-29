#include <Geode/binding/FLAlertLayer.hpp>
#include "Geode/binding/BoomScrollLayer.hpp"
#include "Geode/binding/CCMenuItemSpriteExtra.hpp"
#include "Geode/binding/GJGameLevel.hpp"
#include "Geode/binding/LevelPage.hpp"
#include "Geode/binding/LevelSelectLayer.hpp"
#include "Geode/c++stl/string.hpp"
#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/cocoa/CCObject.h"
#include "Geode/cocos/sprite_nodes/CCSprite.h"
#include "Geode/cocos/tilemap_parallax_nodes/CCTMXObjectGroup.h"
#include "Geode/loader/Log.hpp"
#include "Geode/modify/Modify.hpp"
#include "Geode/ui/Notification.hpp"
#include "Geode/utils/cocos.hpp"
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelPage.hpp>

using namespace geode::prelude;

class $modify(APLevelPage, LevelPage) {   
    //thank you uproxide
    static void onModify(auto& self) {
        if (!self.setHookPriority("LevelPage::updateDynamicPage", 1000002)) {
            log::warn("uh oh");
        }
    }

    void onPlay(CCObject* sender) {
        // here we also check for button-menu because only the tower's levelpage has that so we can not lock it by accident
        if (bool canPlay = !Mod::get()->getSavedValue<bool>(this->m_level->m_levelName + ": Unlock", false) and !getChildByIDRecursive("button-menu")) {
            FLAlertLayer::create("Locked", "You have not recieved this level yet.", "OK")->show();
        }
        else {
            LevelPage::onPlay(nullptr);
        }
    }

    void updateDynamicPage(GJGameLevel* p0) {
        if (bool canPlay = !Mod::get()->getSavedValue<bool>(p0->m_levelName + ": Unlock", false)) {
            LevelPage::updateDynamicPage(p0);

            auto lockSprite = CCSprite::createWithSpriteFrameName("GJ_lockGray_001.png");
            auto button = static_cast<CCMenuItemSpriteExtra*>(this->getChildByIDRecursive("level-button"));

            if (auto lSprite = this->getChildByIDRecursive("ap-lock-sprite"_spr)) {
                lSprite->removeMeAndCleanup();
            }
            button->addChild(lockSprite);
            lockSprite->setID("ap-lock-sprite"_spr);

        }
        else {
            LevelPage::updateDynamicPage(p0);

            if (auto lSprite = this->getChildByIDRecursive("ap-lock-sprite"_spr)) {
                lSprite->removeMeAndCleanup();
            }
        }
    }
};





/*
void onPlay(CCObject* sender) {
        if (this->m_level->m_levelName != "Clubstep")
        FLAlertLayer::create("Locked", "You have not recieved this level yet.", "OK")->show();
        else
        LevelPage::onPlay(nullptr);
    }
*/
#include "APUtils.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "Geode/loader/Loader.hpp"
#include "Geode/loader/Log.hpp"

using namespace geode::prelude;

std::vector<std::string> items = {
    "Stereo Madness: Unlock",
    "Back On Track: Unlock",
    "Polargeist: Unlock",
    "Dry Out: Unlock",
    "Base After Base: Unlock",
    "Can't Let Go: Unlock",
    "Jumper: Unlock",
    "Time Machine: Unlock",
    "Cycles: Unlock",
    "xStep: Unlock",
    "Clutterfunk: Unlock",
    "Theory of Everything: Unlock",
    "Electroman Adventures: Unlock",
    "Clubstep: Unlock",
    "Electrodynamix: Unlock",
    "Hexagon Force: Unlock",
    "Blast Processing: Unlock",
    "Theory of Everything 2: Unlock",
    "Geometrical Dominator: Unlock",
    "Deadlocked: Unlock",
    "Fingerdash: Unlock",
    "Dash: Unlock",
    "The Tower: Unlock",
    "The Sewers: Unlock",
    "The Cellar: Unlock",
    "The Secret Hollow: Unlock",
    "Ship Portal",
    "Ball Portal",
    "UFO Portal",
    "Wave Portal",
    "Robot Portal",
    "Spider Portal",
    "Swing Portal",
    "100 Mana Orbs",
    "Secret Coin"
};

int gdBaseID = 130820130;
    // note to index staff: this is due to the way Archipelago itself works 
    // fun fact, this is the GD release date in DD/MM/YYYY and a 0

void APUtils::recieveItem(int64_t id, bool notify) {
    std::string itemToRecieve = items[id - gdBaseID];
    if (itemToRecieve == "100 Mana Orbs") {
        AchievementNotifier::sharedState()->notifyAchievement("100 mana orvs", "mana orb", "GJ_lockGray_001.png", true);
    }
    else if (itemToRecieve == "Secret Coin") {
        AchievementNotifier::sharedState()->notifyAchievement("secret coin", "coiner", "GJ_lockGray_001.png", true);
    }
    // adding a specific override for can't let go because rob didn't add the apostrophe in the game but my apworld has it. god damn it rob
    else if (itemToRecieve == "Can't Let Go: Unlock") {
        Mod::get()->setSavedValue<bool>("Cant Let Go: Unlock", true);
        if (notify) {
            Loader::get()->queueInMainThread(
                [itemToRecieve]{APUtils::createNotification(itemToRecieve, false);}
            );
        }
    }
    else {
        Mod::get()->setSavedValue<bool>(itemToRecieve, true);
        if (notify) {
                Loader::get()->queueInMainThread(
                    [itemToRecieve]{APUtils::createNotification(itemToRecieve, false);}
                );
        }
    }
}

void APUtils::clearItemState() {
    std::size_t itemAmount = items.size();
    for (std::size_t index = 0; index < itemAmount; ++index) {
        std::string itemToClear = items[index];
        Mod::get()->setSavedValue<bool>(itemToClear, false);
    }
    Mod::get()->setSavedValue<bool>("Cant Let Go: Unlock", false);
}

void APUtils::checkLocation(int64_t id) {
    Loader::get()->queueInMainThread(
        []{APUtils::createNotification("ligma balls", true);}
    );
}

void APUtils::createNotification(std::string name, bool location) {
    const char* title;
    std::string desc;
    if (location) {
        title = "Location checked!";
        desc = "You checked <cg>" + name + " </c>and sent an item.";
    } else {
        title = "Item recieved!";
        desc = "You have recieved <cg>" + name + "</c>.";
    }
    geode::log::info("{}", title);
    geode::log::info("{}", desc);
    geode::log::info("{}", name);
    geode::log::info("location = {}", location);
    AchievementNotifier::sharedState()->notifyAchievement(title, desc.c_str(), "APLogo.png"_spr, true);
}

void APUtils::deathLinkRecieved() {
    Loader::get()->queueInMainThread(
        []{if (PlayLayer* playLayer = PlayLayer::get()) playLayer->destroyPlayer(playLayer->m_player1, nullptr);}
    );
    geode::log::info("deathlink received. time to die");
}

bool APUtils::checkPortal(int id) {
    switch (id) {
        default:
        return true;
        case 13:
        if (Mod::get()->getSavedValue<bool>("Ship Portal", false)) {
            return true;
        } else {
            return false;
        }
        case 47:
        if (Mod::get()->getSavedValue<bool>("Ball Portal", false)) {
            return true;
        } else {
            return false;
        }
        case 111:
        if (Mod::get()->getSavedValue<bool>("UFO Portal", false)) {
            return true;
        } else {
            return false;
        }
        case 660:
        if (Mod::get()->getSavedValue<bool>("Wave Portal", false)) {
            return true;
        } else {
            return false;
        }
        case 745:
        if (Mod::get()->getSavedValue<bool>("Robot Portal", false)) {
            return true;
        } else {
            return false;
        }
        case 1331:
        if (Mod::get()->getSavedValue<bool>("Spider Portal", false)) {
            return true;
        } else {
            return false;
        }
        case 1933:
        if (Mod::get()->getSavedValue<bool>("Swing Portal", false)) {
            return true;
        } else {
            return false;
        }
    }
}
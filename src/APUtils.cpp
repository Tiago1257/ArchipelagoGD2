#include "APUtils.hpp"

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
        /*
        std::string title = "Item recieved!";
        std::string desc = "You have been sent <cg>" + itemToRecieve + "</c>.";
        */
        AchievementNotifier::sharedState()->notifyAchievement("test", "test", "GJ_lockGray_001.png", true);
    }
    else {
        Mod::get()->setSavedValue<bool>(itemToRecieve, true);
        /*
        std::string title = "Item recieved!";
        std::string desc = "You have been sent <cg>" + itemToRecieve + "</c>.";
        */
        AchievementNotifier::sharedState()->notifyAchievement("test", "test", "GJ_lockGray_001.png", true);
    };
}

void APUtils::clearItemState() {
    std::size_t itemAmount = items.size();
    for (std::size_t index = 0; index < itemAmount; ++index) {
        std::string itemToClear = items[index];
        Mod::get()->setSavedValue<bool>(itemToClear, false);
    }
}

void APUtils::checkLocation(int64_t id) {
    // i really don't have anything huge to put here as i really don't need it for gd
}
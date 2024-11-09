#include "Geode/binding/GJGameLevel.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(APPlayLayer, PlayLayer) {
    void levelComplete() {
        PlayLayer::levelComplete();
        geode::log::info("completed level ID {}", this->m_level->m_levelID.value());
    };

    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        geode::log::info("PlayLayer::init called with level ID of {}", level->m_levelID.value());

        return true;
    };
};
#pragma once

namespace APUtils {
    void recieveItem(int64_t id, bool notify);

    void clearItemState();

    void checkLocation(int64_t id);

    void createNotification(std::string name, bool location);

    void deathLinkRecieved();

    bool checkPortal(int id);
}
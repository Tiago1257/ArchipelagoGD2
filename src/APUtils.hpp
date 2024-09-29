#pragma once

#include <vector>
#include <string>

namespace APUtils {
    void recieveItem(int64_t id, bool notify);

    void clearItemState();

    void checkLocation(int64_t id);
}
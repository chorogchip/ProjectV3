#pragma once

#include <Windows.h>
#include "includes/IncludeContents.h"

namespace v3::win {
    bool Init(i64 win_x, i64 win_y, bool is_fullscreen, HINSTANCE h_instance, int n_cmd_show);
    WPARAM Run();
}

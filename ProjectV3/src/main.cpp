#include<iostream>

#include "Win32App.h"
#include "includes/IncludeContents.h"

static constexpr i64 WINDOW_X = 1280;
static constexpr i64 WINDOW_Y = 720;

int APIENTRY WinMain(_In_ HINSTANCE h_instance, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int n_cmd_show) {
    using namespace v3;

    const auto result_win_init = win::Init(WINDOW_X, WINDOW_Y, false, h_instance, n_cmd_show);
    const auto result_ren_init = ren::Init(WINDOW_X, WINDOW_Y, false);
    const auto result_run = win::Run();
}
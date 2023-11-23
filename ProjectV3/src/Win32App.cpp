#include "Win32App.h"

#include "includes/IncludeContents.h"

namespace v3::win {

    static HWND g_h_wnd = nullptr;

    static LRESULT CALLBACK WinProc(HWND h_wnd, UINT message, WPARAM w_param, LPARAM l_param);

    bool Init(i64 win_x, i64 win_y, bool is_fullscreen, HINSTANCE h_instance, int n_cmd_show) {

        WNDCLASSEX window_class{};
        window_class.cbSize = sizeof(WNDCLASSEX);
        window_class.style = CS_HREDRAW | CS_VREDRAW;
        window_class.lpfnWndProc = WinProc;
        window_class.hInstance = h_instance;
        window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
        window_class.lpszClassName = L"Project V3";
        RegisterClassEx(&window_class);

        RECT window_rect{ 0, 0, stc<LONG>(win_x), stc<LONG>(win_y) };
        AdjustWindowRect(&window_rect, WS_OVERLAPPEDWINDOW, FALSE);

        g_h_wnd = CreateWindow(
            window_class.lpszClassName,
            L"Project V3",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            window_rect.right - window_rect.left,
            window_rect.bottom - window_rect.top,
            nullptr, nullptr, h_instance, nullptr
        );

        ShowWindow(g_h_wnd, n_cmd_show);
        
        return true;
    }


    WPARAM Run() {
        
        MSG message{};
        while (message.message != WM_QUIT) {
            if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
                TranslateMessage(&message);
                DispatchMessage(&message);
            }
        }

        return message.wParam;
    }



    static LRESULT CALLBACK WinProc(HWND h_wnd, UINT message, WPARAM w_param, LPARAM l_param) {
        switch (message) {

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        }
        
        return DefWindowProc(h_wnd, message, w_param, l_param);
    }
}

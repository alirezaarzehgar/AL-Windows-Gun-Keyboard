#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void Enter();
void print(char* a);

int main(int argc, char** argv)
{
        system("cls");
        system("color 0a");

        printf(
                          "    _    _     ____             _  __          \n"
            "   / \\  | |   / ___|_   _ _ __ | |/ /___ _   _ \n"
            "  / _ \\ | |  | |  _| | | | '_ \\| ' // _ \\ | | |\n"
            " / ___ \\| |__| |_| | |_| | | | | . \\  __/ |_| |\n"
            "/_/   \\_\\_____\\____|\\__,_|_| |_|_|\\_\\___|\\__, |\n"
            "                                         |___/ \n\n\n\n\n"
              );

        if(argc < 3)
        {
            printf("argument not found!");
            exit(1);
        }

        HWND GameWindow = FindWindow(0, "C:\\Users\\Pishro\\Desktop\\LAKERDAR\\vir.exe");
        SetForegroundWindow(GameWindow);

        SetCursorPos(550, 740);
        mouse_event(MOUSEEVENTF_LEFTDOWN, 700, 710, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP  , 700, 710, 0, 0);

        Sleep(1000);

        int num = atoi(argv[2]);

        for(int i = 0; i < num; i++)
        {
            FILE* f = fopen(argv[1], "r");
            while(!feof(f))
            {
                char str[1024];
                fscanf(f, "%s", str);
                print(str);
                Enter();
            }
            fclose(f);
        }

        return 0;
}

void Enter()
{
        int a = '-';
        int b = (a - 'a') + 0x41;
        keybd_event(b, 0, 0, 0);
        keybd_event(b, 0, KEYEVENTF_KEYUP, 0);

}

void print(char* a)
{
    for(int i = 0; i < strlen(a); i++)
    {
        int b = (a[i] - 'a') + 0x41;
        keybd_event(b, 0, 0, 0);
        keybd_event(b, 0, KEYEVENTF_KEYUP, 0);
    }
}

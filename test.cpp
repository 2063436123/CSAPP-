#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "winmm.lib")
int main() {
    //注意settings.json中编译选项 -lwinmm
    /*puts("播放声音...");
    BOOL flag = PlaySound("home.wav", NULL, SND_FILENAME | SND_ASYNC);
    puts("按任意键退出！");
    int a;
    scanf("%d", &a);
    if (a == 1)
            PlaySound(0, NULL, 0);
    system("pause>nul");*/
    int a;
    mciSendString("play home.mp3", NULL, 0, NULL);
    scanf("%d", &a);
    mciSendString("stop home.mp3", NULL, 0, NULL);
    mciSendString("close home.mp3", NULL, 0, NULL);
    mciSendString("open home.wav", NULL, 0, NULL);
    mciSendString("play home.wav", NULL, 0, NULL);
    Sleep(500000);
    printf("hello world");
}

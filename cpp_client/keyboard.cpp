#include <termio.h>
#include <stdio.h>
 
 //暂时先使用键盘监听控制状态，后续需要切换到Qt中
int scanKeyboard()
{
    int input;
    struct termios new_settings;
    struct termios stored_settings;
    tcgetattr(0,&stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
    tcgetattr(0,&stored_settings);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&new_settings);
      
    input = getchar();
    printf("123\n");
      
    tcsetattr(0,TCSANOW,&stored_settings);
    return input;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
///    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, :, '空', '/' 13个点阵字体
static const char* num_fonts[] = {
    "111101101101111B", "110010010010111B", "111001111100111B", "111001111001111B",
    "101101111001001B", "111100111001111B", "111100111101111B", "111001010010010B",
    "111101111101111B", "111101111001111B", "000010000010000B", "000000000000000B",
    "000001010100000B"
};


// 把单个数字转成点阵字符
char* num2fonts(int n, char ch, char* num_f)
{
    char* np = num_f;
    int cnt = 0;

    if (n > 11 || n < -1)  // '空' 字符
        n = 11;
    if (n == -1)         //   '/' 字符
        n = 12;

    for (int i = 0 ; i != 15; i++) {

        if (num_fonts[n][i] == '0')
            *np++ = ' ';
        else
            *np++ = ch ;

        if (++cnt % 3 == 0)
            *np++ = '\n';
    }
    *np = '\0';

    return num_f;
}


// 把20个以内数字字符串转成点阵字符
char* str2fonts(char* str, char ch, char* str_fonts)
{
    int len = strlen(str);   //控制在20个以内
    char ft_line[5][128];   // 5行字符
    char num_f[64];

    for (int i = 0 ; i != 5; i++) {
        ft_line[i][0] = '\0';         // 5行置0
    }
    for (int i = 0 ; i != len; i++) {
        int n = str[i] - '0';
        num2fonts(n, ch, num_f);
        //   printf("%s\n", num_f);  // 调试用
        char* pch;
        int cnt = 0;
        pch = strtok(num_f, "\n");             // 把数字切割成5行
        while (pch != NULL) {
            strcat((char*)ft_line[cnt], pch);  // 分别追加到5行的末尾
            strcat((char*)ft_line[cnt++], " ");
            pch = strtok(NULL, "\n");
        }
    }

    len = strlen(ft_line[0]) + 1;
    for (int i = 0 ; i != 5; i++) {     //把5行字符写到输入参数里
        sprintf(str_fonts + (i * len), "%s\n", ft_line[i]);
    }

    return str_fonts;
}

// 执行命令行
void execute_command(char* cmdline)
{
    system(cmdline);
}

int main(int argc, char* argv[])
{
    char time_str [80];      // 存储时间  2017/11/10 11:40
    char buf[2048];

    time_t rawtime;
    struct tm* timeinfo;

    int cnt = 10; // 运行10秒左右结束，默认参数
    if (argc > 1) {
        int s = atoi(argv[1]);    // 自定义秒数
        cnt = s;
    }

    while (1) {
        time(&rawtime);                             // 获得时间，格式化时间为字符串
        timeinfo = localtime(&rawtime);
        strftime(time_str, 80, " %H:%M:%S", timeinfo);

        str2fonts(time_str, '@', buf);             // 时间字符串转换成5行字体

        printf("%s\n\tCountdown:%d秒\n", buf, cnt);

        if (cnt-- == 0) {
            if (argc > 2) {
                execute_command(argv[2]);      //  闹钟功能: 去执行其他程序，比如调用 foobar2000 播放音乐
            }
            break;
        }

        sleep(1);

        if (cnt < 10) {            // 10秒倒计时 嘀。嘀。嘀
            printf("\a");
        }

        system("clear");
    }
    return 0;
}


#include <stdio.h>
#include <string.h>

///    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, :, '空', '/' 13个点阵字体
static char* num_fonts[] = {
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

int main(int argc, char* argv[])
{
    int n = 7;
    char buf[2048];
    num2fonts(n, '@', buf);
    printf("%s", buf);

    return 0;
}

#include <stdio.h>
#include <string.h>

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

// 把一行数字字符串转成点阵字符
void str2fonts(char* str, char ch)
{
    int len = strlen(str);   //控制在20个以内
    char ft_line[5][128];   // 5行字符
    char num_f[64];

    for (int i = 0 ; i != 5; i++) {
        ft_line[i][0] = '\0';
    }

    for (int i = 0 ; i != len; i++) {
        int n = str[i] - '0';
        num2fonts(n, ch, num_f);
           printf("%s\n", num_f);    // 调试代码
        char* pch;
        int cnt = 0;
        pch = strtok(num_f, "\n");
        while (pch != NULL) {
            strcat((char*)ft_line[cnt], pch);
            strcat((char*)ft_line[cnt++], " ");
            pch = strtok(NULL, "\n");
        }
    }
    for (int i = 0 ; i != 5; i++) {    // 调试用，最终要修改
        printf("%s\n", ft_line[i]);
    }
}

int main(int argc, char* argv[])
{
    char str[] = "2017";
    str2fonts(str, '@');
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 20
void countWord(char* a);
void countChar(char* a);

int main(int argc, char* argv[])
{
    //int number = 0;
    char* cc = argv[1];
    if (argc != 3) {
        printf("未找到输入命令01");
        return -1;
    }
    if (cc[1] == 'w') { countWord(argv[2]); }
    else if (cc[1] == 'c') { countChar(argv[2]); }
    else {
        printf("未找到输入命令02");
        return -1;
    }
   //printf("%d", number);


}
void countWord(char* a) {
    int len = 0;
    int num = 0;
    int total = 0;
    int i = 0;
    char c;
    int lastBlack = 0;
    char buf[MAX_NUM];
    FILE* file = fopen(a, "rb");
    if (file == NULL)
    {
        printf("文件打开失败!\n");

    }
    while (fgets(buf, MAX_NUM, file) != NULL) {

        len = strlen(buf);
        for (i = 0; i < len; i++) {
            c = buf[i];
            if (c == ' ' || c == '\n') {
                if (lastBlack == 0) {
                    num++;
                    lastBlack = 1;
                }
            }
            else if (c != '\n' && c != ' ') { lastBlack = 0; }
        }
        !lastBlack && num++;
        lastBlack = 1;
        total += num;
        num = 0;
    }
    printf("单词个数为%d", total-1);
    fclose(file);				//关闭文件
    getchar();
}
void countChar(char* a) {
    int len = 0;
    int num = 0;
    char buf[MAX_NUM];
    char ch;
    FILE* file = fopen(a, "rb");
    if (file == NULL)
    {
        printf("文件打开失败!\n");

    }
    ch = fgetc(file);
    while (fgets(buf, MAX_NUM, file) != NULL) {

        len = strlen(buf);
        //printf("%d", len);
        num += len;
    }
    printf("字符个数为%d", num);
    fclose(file);				//关闭文件
    getchar();

}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#define ADD_DAYS 300

VOID FactrFib(VOID);
DWORD WINAPI SetTime(LPVOID param);
DWORD WINAPI TreadFib(LPVOID param);



int main(int argc, char* argv[])
{
    system("chcp 1251>nul");
    
    for(; ; )
    {
        FactrFib();
        //getchar();
        system("cls");
    }
    
    
    return 0;
}

VOID FactrFib(VOID)
{
    HANDLE t;
    t = CreateThread(NULL, 0, SetTime, NULL, 0, 0);
}

DWORD WINAPI SetTime(LPVOID param)
{
    struct tm* u;
    char s1[40] = { 0 }, s2[40] = { 0 };
    const time_t timer = time(NULL);
    u = localtime(&timer);
    strftime(s1, 80, "Дата: %d.%m.%Y \nВремя: %H:%M:%S ", u);
    printf("%s\n", s1);
    u->tm_mday += ADD_DAYS;
    

    ExitThread(0);
}
//DWORD WINAPI TreadFib(LPVOID param)
//{
//    int f = 0;
//    int f1 = 1;
//    int f2 = 1;
//    for (int i = 0; i <= n; i++)
//    {
//        if (i < 2)
//        {
//            f = f1;
//            f1 = f2;
//            f2 += f;
//        }
//        printf("%d element Fibonachi rave %d\n", i, f2);
//    }
//    ExitThread(0);
//}
#include<stdio.h>
#include<string.h>
#include"Menu.h"
#include"function.h"
#include"windows.h"
void password()
{
    FILE *fp;
    char co[20];
    char co1[20];
    int i,sign=0;
    sign=checkcode();
    if(sign==1)
    {
        printf("\n\n\n\n\n\n\n\t\t\t  密码错误！请关闭窗口重新进入系统！");
        getch();
        system("cls");
        exit(0);
    }
    else
        system("cls");
        printf("\n\n\n\n\n\t\t\t\n");
        Menu();
        return;
}
int checkcode()
{
    FILE *fp;
    char co[20];
    char co1[20];
    int i;
    if((fp=fopen("stu_code","rb"))==NULL)
    {
        system("cls");
        printf("请设置密码：");
        scanf("%s",co);
        fp=fopen("stu_code","wb+");
        for(i=0;i<20;i++)
            fwrite(&co[i],sizeof(char),1,fp);
        fclose(fp);
        return 0;
    }
    else
    {
        system("cls");
        for(i=0;i<20;i++)
            fread(&co[i],sizeof(char),1,fp);
        fclose(fp);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("         \t\t\t------------\n");
        printf("        \t\t\t|请输入密码|\n");
        printf("         \t\t\t------------\n");
        printf("         \t\t\t");
        scanf("%s",co1);
        if(strcmp(co,co1)!=0)
        {
            return 1;
        }
    }
}
int main()
{
    password();
}

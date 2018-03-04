#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<stdio.h>
#include"windows.h"
#include"function.h"
int Menu()
{
    int ch;
    printf("              >>>>>>>>>>>>欢迎使用学生成绩管理系统<<<<<<<<<<<<<<<<      \n");
    printf("                                                                          \n");
    printf("     *************      数据维护           数据查询              ***********            \n");
    printf("     *************        1-数据初始化        6-按学号           ***********            \n");
    printf("     *************        2-录入              7-按姓名           ***********            \n");
    printf("     *************        3-添加              8-按成绩           ***********            \n");
    printf("     *************        4-修改              9-组合查询         ***********            \n");
    printf("     *************        5-删除                                 ***********            \n");
    printf("     *************                                               ***********            \n");
    printf("                                                                                       \n");
    printf("     *************      系统维护              13-排序            ***********            \n");
    printf("     *************       10-数据备份          14-统计            ***********            \n");
    printf("     *************       11-数据恢复          15-输出            ***********            \n");
    printf("     *************       12-口令维护          16-帮助            ***********            \n");
    printf("     *************                            17-退出            ***********            \n");
    printf("                                                                                       \n");
    printf ("请输入您要选择的选项: ");
    scanf("%d",&ch);
      switch (ch)
    {
        case 1:system("cls");
            printf("\n\n\t\t\t\t执行数据初始化功能\n\n\n");
            initialise();
        break;
        case 2:system("cls");
               printf("\n\n\t\t\t\t执行信息录入功能\n");
               Creat();
               turn();
        break;
        case 3:system("cls");
            printf("\n\n\t\t\t\t执行添加功能\n");
            add();
            printf("\n\n\n添加完毕！\n\n");
            turn();
        break;
        case 4:system("cls");
            printf("\n\n\t\t\t\t执行修改功能\n");
           change();
            turn();
        break;
        case 5:system("cls");
            printf("\n\n\t\t\t\t执行删除功能\n");
            Delete();
            turn();
        break;
        case 6:system("cls");
            printf("\n\n\t\t\t\t根据学号查询\n");
            searchbynum();
            turn();
        break;
        case 7:system("cls");
            printf("\n\n\t\t\t\t根据姓名查询\n");
            searchbyname();
            turn();
        break;
        case 8:system("cls");
            printf("\n\n\t\t\t\t根据成绩查询\n\n");
            searchbyscore();
            turn();
        break;
        case 9:system("cls");
            printf("\n\n\t\t\t\t组合查询");
            searchbyall();
            turn();
        break;
        case 10:system("cls");
            printf("\n\n\t\t\t\t数据备份\n\n\n");
         back_up();
            turn();
        break;
        case 11:system("cls");
            printf("\n\n\t\t\t\t数据恢复\n\n\n");
        recover();
            turn();
        break;
        case 12:system("cls");
            printf("\n\n\t\t\t\t口令维护\n\n\n");
        ggmm();
            turn();
        break;
        case 13:system("cls");
printf("\n\n\t\t\t\t学生成绩信息排名（降序）\n\n\n");
          scoredown();
            turn();
        break;
        case 14:system("cls");
            printf("\n\n\t\t\t\t信息统计\n\n\n");
        score_count();
            turn();
        break;
        case 15:system("cls");
            printf("\n\n\t\t\t\t信息输出\n\n\n");
        output();
            turn();
        break;
        case 16:system("cls");
           help();
            turn();
        break;
        case 17:system("cls");
                MessageBox(NULL,"您已退出学生成绩管理系统！再见!","WinMain",MB_OK);
        break;
        exit(0);
    }
}
#endif // MENU_H_INCLUDED

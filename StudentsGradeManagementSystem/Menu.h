#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<stdio.h>
#include"windows.h"
#include"function.h"
int Menu()
{
    int ch;
    printf("              >>>>>>>>>>>>��ӭʹ��ѧ���ɼ�����ϵͳ<<<<<<<<<<<<<<<<      \n");
    printf("                                                                          \n");
    printf("     *************      ����ά��           ���ݲ�ѯ              ***********            \n");
    printf("     *************        1-���ݳ�ʼ��        6-��ѧ��           ***********            \n");
    printf("     *************        2-¼��              7-������           ***********            \n");
    printf("     *************        3-���              8-���ɼ�           ***********            \n");
    printf("     *************        4-�޸�              9-��ϲ�ѯ         ***********            \n");
    printf("     *************        5-ɾ��                                 ***********            \n");
    printf("     *************                                               ***********            \n");
    printf("                                                                                       \n");
    printf("     *************      ϵͳά��              13-����            ***********            \n");
    printf("     *************       10-���ݱ���          14-ͳ��            ***********            \n");
    printf("     *************       11-���ݻָ�          15-���            ***********            \n");
    printf("     *************       12-����ά��          16-����            ***********            \n");
    printf("     *************                            17-�˳�            ***********            \n");
    printf("                                                                                       \n");
    printf ("��������Ҫѡ���ѡ��: ");
    scanf("%d",&ch);
      switch (ch)
    {
        case 1:system("cls");
            printf("\n\n\t\t\t\tִ�����ݳ�ʼ������\n\n\n");
            initialise();
        break;
        case 2:system("cls");
               printf("\n\n\t\t\t\tִ����Ϣ¼�빦��\n");
               Creat();
               turn();
        break;
        case 3:system("cls");
            printf("\n\n\t\t\t\tִ����ӹ���\n");
            add();
            printf("\n\n\n�����ϣ�\n\n");
            turn();
        break;
        case 4:system("cls");
            printf("\n\n\t\t\t\tִ���޸Ĺ���\n");
           change();
            turn();
        break;
        case 5:system("cls");
            printf("\n\n\t\t\t\tִ��ɾ������\n");
            Delete();
            turn();
        break;
        case 6:system("cls");
            printf("\n\n\t\t\t\t����ѧ�Ų�ѯ\n");
            searchbynum();
            turn();
        break;
        case 7:system("cls");
            printf("\n\n\t\t\t\t����������ѯ\n");
            searchbyname();
            turn();
        break;
        case 8:system("cls");
            printf("\n\n\t\t\t\t���ݳɼ���ѯ\n\n");
            searchbyscore();
            turn();
        break;
        case 9:system("cls");
            printf("\n\n\t\t\t\t��ϲ�ѯ");
            searchbyall();
            turn();
        break;
        case 10:system("cls");
            printf("\n\n\t\t\t\t���ݱ���\n\n\n");
         back_up();
            turn();
        break;
        case 11:system("cls");
            printf("\n\n\t\t\t\t���ݻָ�\n\n\n");
        recover();
            turn();
        break;
        case 12:system("cls");
            printf("\n\n\t\t\t\t����ά��\n\n\n");
        ggmm();
            turn();
        break;
        case 13:system("cls");
printf("\n\n\t\t\t\tѧ���ɼ���Ϣ����������\n\n\n");
          scoredown();
            turn();
        break;
        case 14:system("cls");
            printf("\n\n\t\t\t\t��Ϣͳ��\n\n\n");
        score_count();
            turn();
        break;
        case 15:system("cls");
            printf("\n\n\t\t\t\t��Ϣ���\n\n\n");
        output();
            turn();
        break;
        case 16:system("cls");
           help();
            turn();
        break;
        case 17:system("cls");
                MessageBox(NULL,"�����˳�ѧ���ɼ�����ϵͳ���ټ�!","WinMain",MB_OK);
        break;
        exit(0);
    }
}
#endif // MENU_H_INCLUDED

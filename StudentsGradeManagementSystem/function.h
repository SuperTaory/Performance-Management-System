#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include"windows.h"
#define LEN sizeof(struct student)
struct student
{
    int num;
    int age;
    char name[20];
    char sex[5];
    char nat[10];
    char adress[30];
    float score1;
    float score2;
    float score3;
    float score4;
    float score5;
    float score6;
    float average;
    float sum;
    struct student *next;
};
int n,N;
struct student *head;
struct student *p1, *p2;
void Creat()
{

    FILE *fp = fopen ("entering.txt", "w");
    p1=p2=(struct student*)malloc(LEN);
    printf("请输入要录入的学生的人数：\n");
    scanf("%d",&N);
    printf("*******************************************************************************\n");
    printf("*学号、姓名、性别、年龄、民族、住址、高数、英语、大物、C语言、离散、体育(以空格作为间隔,以回车作为结束)*\n");
    printf("*******************************************************************************\n");
    head=NULL;
     for(n=1;n<=N;++n)
  {
    printf("\n请输入第%d个学生的信息：\n\n",n);
    if(n==1)
       {head=p1;}
        p2->next=p1;
        p2=p1;
        p1=(struct student*)malloc(LEN);
         scanf("%d %s %s %d %s %s %f %f %f %f %f %f",&p1->num,&p1->name,&p1->sex,&p1->age,&p1->nat,&p1->adress,&p1->score1,&p1->score2,&p1->score3,&p1->score4,&p1->score5,&p1->score6);
         p1->sum=p1->score1+p1->score2+p1->score3+p1->score4+p1->score5+p1->score6;
         p1->average=p1->sum/6;
        fprintf (fp, "%d %s %s %d %s %s %5.2f %5.2f %5.2f %5.2f %5.2f %.2f %5.2f %5.2f\n", p1->num,p1->name,p1->sex,p1->age,p1->nat,p1->adress,p1->score1,p1->score2,p1->score3,p1->score4,p1->score5,p1->score6,p1->average,p1->sum);
  }
    p2->next=NULL;

        fclose (fp);
        printf("已录入人数为：%d\n\n",n-1);

}

void turn()
{
  int t;
  printf("\n\n\n\t\t\t");
  printf("*******************************\n");
  printf("\t\t\t*返回主菜单输入0/退出系统输入1*\n");
  printf("\t\t\t*******************************\n");
  printf("\n\n输入:");
  scanf("%d",&t);
  switch(t)
  {
      case 0:system("cls");
      printf("\n\n\n\n\n");
             Menu();
             break;
      case 1:system("cls");
       MessageBox(NULL,"您已退出学生成绩管理系统！再见!","see you!!",MB_OK);
       exit(0);
      break;
  }
}


void initialise()
{
    int t;
   printf("\t    (执行初始化功能会清空已存储的学生信息!)是否要执行初始化功能？\n\n\n");
   printf("\t\t   输入1执行初始化功能            输入0返回主菜单\n");
   scanf("%d",&t);
   if(t==1)
   {
       system("cls");
    FILE *fp;
    fp=fopen("entering.txt","w");
    fclose(fp);
    printf("\n\n\t\t\t 数据初始化成功！\n\n\n\n");
    turn();
   }
   else
    system("cls");
   Menu();

}


void searchbynum()
{
int id,j=0;
struct student *p,*q,*head,*en;
FILE *fp;
fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{

    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);
printf("输入您要查询的学号：");
scanf("%d",&id);
printf("\n\n");

while(q!=NULL)
{
    if(q->num==id)

        {
            printf(" 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");

        printf("%d %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
        j++;}
    q=q->next;
}
if(j==0)
    printf("没有查到您需要的信息！\n");

}

void searchbyname()
{
    int j=0;
    char str[100];
struct student *p,*q,*head,*en;
FILE *fp;
fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{

    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);
    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);
printf("输入您要查询的名字：");
scanf("%s",str);
printf("\n\n");
while(q!=NULL)
{
    if(strcmp(q->name,str)==0)
    {
        printf(" 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
}
if(j==0)
        printf("没有查到您需要的信息！\n");

}


void searchbyscore()
{
    int t,j=0;
    float score;
    struct student *p,*q,*head,*en;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{

    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);
    printf("\t\t\t1-按高数成绩查询\n\n");
    printf("\t\t\t2-按大物成绩查询\n\n");
    printf("\t\t\t3-按英语成绩查询\n\n");
    printf("\t\t\t4-按C语言成绩查询\n\n");
    printf("\t\t\t5-按离散成绩查询\n\n");
    printf("\t\t\t6-按体育成绩查询\n\n");
    printf("\t\t\t7-返回主菜单");
    printf("\n\n\n\t\t\t输入您的选择序号：");
    scanf("%d",&t);
    switch(t)
{
case 1:system("cls");
    printf("\n\n\n\t\t\t输入高数成绩：");
    scanf("%f",&score);
            printf("\n\n 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");

    while(q!=NULL)
   {
    if(q->score1==score)
    {
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
   }
   if(j==0)
        printf("没有查到您需要的信息！\n");

    break;
case 2:system("cls");
    printf("\n\n\n\t\t\t输入大物成绩：");
    scanf("%f",&score);
            printf("\n\n 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");

    while(q!=NULL)
   {
    if(q->score2==score)
    {
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
   }
   if(j==0)
        printf("没有查到您需要的信息！\n");

    break;
case 3:system("cls");
    printf("\n\n\n\t\t\t输入英语成绩：");
    scanf("%f",&score);
            printf("\n\n 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");

    while(q!=NULL)
   {
    if(q->score3==score)
    {
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
   }
   if(j==0)
        printf("没有查到您需要的信息！\n");

    break;
case 4:system("cls");
    printf("\n\n\n\t\t\t输入C语言成绩：");
    scanf("%f",&score);
            printf("\n\n 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");

    while(q!=NULL)
   {
    if(q->score4==score)
    {
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
   }
   if(j==0)
        printf("没有查到您需要的信息！\n");

    break;
case 5:system("cls");
    printf("\n\n\n\t\t\t输入离散成绩：");
    scanf("%f",&score);
            printf("\n\n 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");

    while(q!=NULL)
   {
    if(q->score5==score)
    {
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
   }
   if(j==0)
        printf("没有查到您需要的信息！\n");

    break;
case 6:system("cls");
    printf("\n\n\n\t\t\t输入体育成绩：");
    scanf("%f",&score);
            printf("\n\n 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");

    while(q!=NULL)
   {
    if(q->score6==score)
    {
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
   }
   if(j==0)
        printf("没有查到您需要的信息！\n");

    break;
case 7:system("cls");
    Menu();
       break;
}
}

void searchbyall()
{
    int num,age,j=0;
    char name[20],sex[5],nat[10],adress[30];
    struct student *p,*q,*head,*en;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{
    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);
    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);
    printf("\n\n\n\t\t 输入学号  姓名 性别 年龄 民族 住址 :\n\n\t\t ");
    scanf("%d %s %s %d %s %s",&num,&name,&sex,&age,&nat,&adress);
    while(q!=NULL)
   {
    if(q->num==num&&q->age==age&&(strcmp(q->name,name)==0)&&(strcmp(q->sex,sex)==0)&&(strcmp(q->nat,nat)==0)&&(strcmp(q->adress,adress)==0))
    {
        printf("\n\n 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
   }
   if(j==0)
        printf("\n\n\n\t\t 没有查到您需要的信息！\n");
}

void output()
{
    struct student *p,*q,*head,*en;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{
    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);
    printf("\n\n 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");
    while(q->next!=NULL)
   {
    printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    q=q->next;
   }
}

void help()
{
    printf("\t\t\t\t功能介绍：\n");
    printf("1-数据初始化：此功能会将已保存的学生成绩信息清空，并且清空后不会恢复，请慎重使用此功能！\n\n");
    printf("2-录入：此功能即存储学生成绩信息！\n\n");
    printf("3-添加：此功能即增添学生成绩信息！\n\n");
    printf("4-修改: 此功能即修改学生成绩信息！\n\n");
    printf("5-删除：此功能即删除学生成绩信息！\n\n");
    printf("6-按学号查询：输入要查询的学号，点击回车键进行查询！\n\n");
    printf("7-按姓名查询：输入要查询的姓名，点击回车键进行查询！\n\n");
    printf("8-按成绩查询：根据子菜单项输入单科成绩即可查询详细成绩信息！\n\n");
    printf("9-综合查询：要求输入学号，姓名，性别，年龄，民族，住址等信息进行查询！\n\n");
    printf("10-数据备份:此功能将已存储的成绩信息进行复制另存，避免数据丢失！\n\n");
    printf("11-数据恢复：如果学生成绩信息丢失，可以通过此功能找回！\n\n");
    printf("12-口令维护:此功能可以修改系统登陆口令，增加系统安全性！\n\n");
    printf("13-排序：将学生成绩按照降序排序，便于学生查询名次！\n\n");
    printf("14-统计：查找总成绩高于某个分数线的学生信息！\n\n");
    printf("15-输出：将学生的成绩信息打印到屏幕上！\n\n");

}

void scoredown()
{
    int n=0,i,j;
    struct student *p,*q,*head,*en;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{

    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);
struct student
{
    int num;
    int age;
    char name[20];
    char sex[5];
    char nat[10];
    char adress[30];
    float score1;
    float score2;
    float score3;
    float score4;
    float score5;
    float score6;
    float average;
    float sum;
};
struct student str[100];
struct student temp;

while(q->next!=NULL)
{
    str[n].num=q->num;
    strcpy(str[n].name,q->name);
    str[n].age=q->age;
    strcpy(str[n].sex,q->sex);
    strcpy(str[n].nat,q->nat);
    strcpy(str[n].adress,q->adress);
    str[n].score1=q->score1;
    str[n].score2=q->score2;
    str[n].score3=q->score3;
    str[n].score4=q->score4;
    str[n].score5=q->score5;
    str[n].score6=q->score6;
    str[n].average=q->average;
    str[n].sum=q->sum;
   q=q->next;
    n++;
}
for(j=0;j<n;j++)
   for(i=0;i<n-j;i++)
   {
    if(str[i].sum<str[i+1].sum)
       {
        temp=str[i];
        str[i]=str[i+1];
        str[i+1]=temp;
       }
   }

   printf("\n\n排名 学号  姓名 性别 年龄 民族 住址  高数  大物  英语  C语言  离散  体育 平均分 总分\n\n");
   for(i=0;i<n;i++)
   {
       printf("%d %d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n",i+1,str[i].num,str[i].name,str[i].sex,str[i].age,str[i].nat,str[i].adress,str[i].score1,str[i].score2,str[i].score3,str[i].score4,str[i].score5,str[i].score6,str[i].average,str[i].sum);
   }
}

void  score_count()
{
    int i=0,j=0,k=0;
    struct student *p,*q,*head,*en;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{
    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);
while(q->next!=NULL)
{
    if(q->sum>=480)
       {
           i++;
       }
       else if(q->sum>=360)
       {
           j++;
       }
       else
       {
           k++;
       }
    q=q->next;
}
printf("经过统计：\n\n");
printf("\t\t\t优秀学生人数为：%d.\n\n",i);
printf("\t\t\t良好学生人数为：%d.\n\n",j);
printf("\t\t\t不合格学生人数为：%d.\n\n",k);

}

void Delete()
{
    struct student *p,*q,*head,*en,*t;
    int i,s;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{

    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);

printf("您要删除几个人的信息：");
scanf("%d",&s);
  long o;
  for(i=0;i<s;i++)
  {
  printf("\n\n请输入您要删除的第%d个学生的学号：",i+1);
  scanf("%ld",&o);
  p=head;
   if(p==NULL)
    printf("链表为空！\n");
   while(p->num!=o&&p->next!=NULL)
   {
       q=p;
       p=p->next;
   }
   if(p->num==o)
   {
      q->next=p->next;//跳过欲删除结点，将下一结点的首地址赋给上一结点
      free(p);
      printf("\n删除成功！");
   }
   else
    printf("\n删除失败！（输入学号错误！如要删除请返回主菜单重新输入正确学号删除）");
        fp=fopen("entering.txt","w");
        t=head->next;
        while(t->next!=NULL)
        {
        fprintf (fp, "%d %s %s %d %s %s %5.2f %5.2f %5.2f %5.2f %5.2f %.2f %5.2f %5.2f\n", t->num,t->name,t->sex,t->age,t->nat,t->adress,t->score1,t->score2,t->score3,t->score4,t->score5,t->score6,t->average,t->sum);
         t=t->next;
        }
        fclose(fp);
}
}

void change()
{
   int id,j=0,s,i;
struct student *p,*q,*head,*en,*t;
FILE *fp;
fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{

    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);

printf("请输入您要修改的学生人数：");
scanf("%d",&s);
for(i=0;i<s;i++)
{
system("cls");
printf("\n\n请输入要修改第%d个学生的学号:",i+1);
scanf("%d",&id);
while(q!=NULL)
{
    if(q->num==id)
    {
        printf("\n\n此学生的原始信息为:\n\n");
printf("**********************************************************************************\n");
printf("*学号、姓名、性别、年龄、民族、住址、高数、英语、大物、C语言、离散、体育(以空格作为间隔,以回车作为结束)*\n");
printf("**********************************************************************************\n\n");
printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
printf("请输入修改后的信息：\n\n");
scanf("%d %s %s %d %s %s %f %f %f %f %f %f",&q->num,&q->name,&q->sex,&q->age,&q->nat,&q->adress,&q->score1,&q->score2,&q->score3,&q->score4,&q->score5,&q->score6);
      q->sum=q->score1+q->score2+q->score3+q->score4+q->score5+q->score6;
      q->average=q->sum/6;
    j++;
    break;
    }
    q=q->next;
}
if(j==0)
    printf("没有该学生的信息");


        fp=fopen("entering.txt","w");
        t=head->next;
        while(t->next!=NULL)
        {
        fprintf (fp, "%d %s %s %d %s %s %5.2f %5.2f %5.2f %5.2f %5.2f %.2f %5.2f %5.2f\n", t->num,t->name,t->sex,t->age,t->nat,t->adress,t->score1,t->score2,t->score3,t->score4,t->score5,t->score6,t->average,t->sum);
         t=t->next;
        }
        fclose(fp);
        q=head->next;

}
system("cls");
printf("\t\t\t修改完毕！\n\n\n");
}

void add()
{

    int i,s;
    struct student *p,*q,*head,*en,*t,*p1,*p2;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{
    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);


printf("输入您要添加的学生人数：");
scanf("%d",&s);

for(i=0;i<s;i++)
{
    system("cls");
    printf("\n请输入添加的第%d个学生的信息:\n\n",i+1);
    printf("**********************************************************************************\n");
    printf("*学号、姓名、性别、年龄、民族、住址、高数、英语、大物、C语言、离散、体育(以空格作为间隔,以回车作为结束)*\n");
    printf("**********************************************************************************\n");
    p1=p2=(struct student*)malloc(LEN);
    p1->next=head->next;
    head->next=p2;
   scanf("%d %s %s %d %s %s %f %f %f %f %f %f",&p1->num,&p1->name,&p1->sex,&p1->age,&p1->nat,&p1->adress,&p1->score1,&p1->score2,&p1->score3,&p1->score4,&p1->score5,&p1->score6);
      p1->sum=p1->score1+p1->score2+p1->score3+p1->score4+p1->score5+p1->score6;
    p1->average=p1->sum/6;


        fp=fopen("entering.txt","w");
        t=head->next;
        while(t->next!=NULL)
        {
        fprintf (fp, "%d %s %s %d %s %s %5.2f %5.2f %5.2f %5.2f %5.2f %.2f %5.2f %5.2f\n", t->num,t->name,t->sex,t->age,t->nat,t->adress,t->score1,t->score2,t->score3,t->score4,t->score5,t->score6,t->average,t->sum);
         t=t->next;
        }
        fclose(fp);
}
}
void back_up()
{
   FILE *gp;
   gp=fopen("beifen.txt","w");
   fclose(gp);
   struct student *p,*q,*head,*en;
   FILE *fp;
   fp=fopen("entering.txt","a+");
   if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{

    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);
FILE *pp;
pp=fopen("beifen.txt","a+");
while(q->next!=NULL){
fprintf (pp, "%d %s %s %d %s %s %5.2f %5.2f %5.2f %5.2f %5.2f %.2f %5.2f %5.2f\n", q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
q=q->next;}
fclose(pp);
printf("\t\t\t\t备份完毕！\n");
}
void ggmm()
{
FILE *fp;
int i;
char col[20];
system("cls");
if((fp=fopen("stu_code","wb"))==NULL)
{
printf("文件打开失败！");
}
else
{
printf("\n\n请输入新密码:");
scanf("%s",col);
for(i=0;i<20;i++)
fwrite(&col[i],sizeof(char),1,fp);
fclose(fp);
printf("\n\n\n更改密码成功！");
}
}

void recover()
{
  struct student *p,*q,*head,*en;
FILE *fp;
fp=fopen("beifen.txt","a+");
if((fp=fopen("beifen.txt","a+"))==NULL)
{
    printf("打开文件失败！\n");
    exit(0);
}
head=(struct student*)malloc(LEN);
 en=head;
   en->next=NULL;
while(!feof(fp))
{

    p=(struct student*)malloc(LEN);
    fscanf(fp,"%d %s %s %d %s %s %f %f %f %f %f %f %f %f",&p->num,&p->name,&p->sex,&p->age,&p->nat,&p->adress,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5,&p->score6,&p->average,&p->sum);

    en->next=p;
    en=p;
    en->next=NULL;
}
q=head->next;
fclose(fp);

FILE *pp;
pp=fopen("entering.txt","a+");
while(q->next!=NULL){
fprintf (pp, "%d %s %s %d %s %s %5.2f %5.2f %5.2f %5.2f %5.2f %.2f %5.2f %5.2f\n", q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
q=q->next;}
fclose(pp);
printf("\t\t\t数据恢复完毕！\n\n\n");

}
#endif // ENTERING_H_INCLUDED

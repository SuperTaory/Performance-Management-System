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
    printf("������Ҫ¼���ѧ����������\n");
    scanf("%d",&N);
    printf("*******************************************************************************\n");
    printf("*ѧ�š��������Ա����䡢���塢סַ��������Ӣ����C���ԡ���ɢ������(�Կո���Ϊ���,�Իس���Ϊ����)*\n");
    printf("*******************************************************************************\n");
    head=NULL;
     for(n=1;n<=N;++n)
  {
    printf("\n�������%d��ѧ������Ϣ��\n\n",n);
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
        printf("��¼������Ϊ��%d\n\n",n-1);

}

void turn()
{
  int t;
  printf("\n\n\n\t\t\t");
  printf("*******************************\n");
  printf("\t\t\t*�������˵�����0/�˳�ϵͳ����1*\n");
  printf("\t\t\t*******************************\n");
  printf("\n\n����:");
  scanf("%d",&t);
  switch(t)
  {
      case 0:system("cls");
      printf("\n\n\n\n\n");
             Menu();
             break;
      case 1:system("cls");
       MessageBox(NULL,"�����˳�ѧ���ɼ�����ϵͳ���ټ�!","see you!!",MB_OK);
       exit(0);
      break;
  }
}


void initialise()
{
    int t;
   printf("\t    (ִ�г�ʼ�����ܻ�����Ѵ洢��ѧ����Ϣ!)�Ƿ�Ҫִ�г�ʼ�����ܣ�\n\n\n");
   printf("\t\t   ����1ִ�г�ʼ������            ����0�������˵�\n");
   scanf("%d",&t);
   if(t==1)
   {
       system("cls");
    FILE *fp;
    fp=fopen("entering.txt","w");
    fclose(fp);
    printf("\n\n\t\t\t ���ݳ�ʼ���ɹ���\n\n\n\n");
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
    printf("���ļ�ʧ�ܣ�\n");
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
printf("������Ҫ��ѯ��ѧ�ţ�");
scanf("%d",&id);
printf("\n\n");

while(q!=NULL)
{
    if(q->num==id)

        {
            printf(" ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");

        printf("%d %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
        j++;}
    q=q->next;
}
if(j==0)
    printf("û�в鵽����Ҫ����Ϣ��\n");

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
    printf("���ļ�ʧ�ܣ�\n");
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
printf("������Ҫ��ѯ�����֣�");
scanf("%s",str);
printf("\n\n");
while(q!=NULL)
{
    if(strcmp(q->name,str)==0)
    {
        printf(" ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
}
if(j==0)
        printf("û�в鵽����Ҫ����Ϣ��\n");

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
    printf("���ļ�ʧ�ܣ�\n");
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
    printf("\t\t\t1-�������ɼ���ѯ\n\n");
    printf("\t\t\t2-������ɼ���ѯ\n\n");
    printf("\t\t\t3-��Ӣ��ɼ���ѯ\n\n");
    printf("\t\t\t4-��C���Գɼ���ѯ\n\n");
    printf("\t\t\t5-����ɢ�ɼ���ѯ\n\n");
    printf("\t\t\t6-�������ɼ���ѯ\n\n");
    printf("\t\t\t7-�������˵�");
    printf("\n\n\n\t\t\t��������ѡ����ţ�");
    scanf("%d",&t);
    switch(t)
{
case 1:system("cls");
    printf("\n\n\n\t\t\t��������ɼ���");
    scanf("%f",&score);
            printf("\n\n ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");

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
        printf("û�в鵽����Ҫ����Ϣ��\n");

    break;
case 2:system("cls");
    printf("\n\n\n\t\t\t�������ɼ���");
    scanf("%f",&score);
            printf("\n\n ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");

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
        printf("û�в鵽����Ҫ����Ϣ��\n");

    break;
case 3:system("cls");
    printf("\n\n\n\t\t\t����Ӣ��ɼ���");
    scanf("%f",&score);
            printf("\n\n ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");

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
        printf("û�в鵽����Ҫ����Ϣ��\n");

    break;
case 4:system("cls");
    printf("\n\n\n\t\t\t����C���Գɼ���");
    scanf("%f",&score);
            printf("\n\n ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");

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
        printf("û�в鵽����Ҫ����Ϣ��\n");

    break;
case 5:system("cls");
    printf("\n\n\n\t\t\t������ɢ�ɼ���");
    scanf("%f",&score);
            printf("\n\n ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");

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
        printf("û�в鵽����Ҫ����Ϣ��\n");

    break;
case 6:system("cls");
    printf("\n\n\n\t\t\t���������ɼ���");
    scanf("%f",&score);
            printf("\n\n ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");

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
        printf("û�в鵽����Ҫ����Ϣ��\n");

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
    printf("���ļ�ʧ�ܣ�\n");
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
    printf("\n\n\n\t\t ����ѧ��  ���� �Ա� ���� ���� סַ :\n\n\t\t ");
    scanf("%d %s %s %d %s %s",&num,&name,&sex,&age,&nat,&adress);
    while(q!=NULL)
   {
    if(q->num==num&&q->age==age&&(strcmp(q->name,name)==0)&&(strcmp(q->sex,sex)==0)&&(strcmp(q->nat,nat)==0)&&(strcmp(q->adress,adress)==0))
    {
        printf("\n\n ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");
        printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    j++;
    }
    q=q->next;
   }
   if(j==0)
        printf("\n\n\n\t\t û�в鵽����Ҫ����Ϣ��\n");
}

void output()
{
    struct student *p,*q,*head,*en;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("���ļ�ʧ�ܣ�\n");
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
    printf("\n\n ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");
    while(q->next!=NULL)
   {
    printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
    q=q->next;
   }
}

void help()
{
    printf("\t\t\t\t���ܽ��ܣ�\n");
    printf("1-���ݳ�ʼ�����˹��ܻὫ�ѱ����ѧ���ɼ���Ϣ��գ�������պ󲻻�ָ���������ʹ�ô˹��ܣ�\n\n");
    printf("2-¼�룺�˹��ܼ��洢ѧ���ɼ���Ϣ��\n\n");
    printf("3-��ӣ��˹��ܼ�����ѧ���ɼ���Ϣ��\n\n");
    printf("4-�޸�: �˹��ܼ��޸�ѧ���ɼ���Ϣ��\n\n");
    printf("5-ɾ�����˹��ܼ�ɾ��ѧ���ɼ���Ϣ��\n\n");
    printf("6-��ѧ�Ų�ѯ������Ҫ��ѯ��ѧ�ţ�����س������в�ѯ��\n\n");
    printf("7-��������ѯ������Ҫ��ѯ������������س������в�ѯ��\n\n");
    printf("8-���ɼ���ѯ�������Ӳ˵������뵥�Ƴɼ����ɲ�ѯ��ϸ�ɼ���Ϣ��\n\n");
    printf("9-�ۺϲ�ѯ��Ҫ������ѧ�ţ��������Ա����䣬���壬סַ����Ϣ���в�ѯ��\n\n");
    printf("10-���ݱ���:�˹��ܽ��Ѵ洢�ĳɼ���Ϣ���и�����棬�������ݶ�ʧ��\n\n");
    printf("11-���ݻָ������ѧ���ɼ���Ϣ��ʧ������ͨ���˹����һأ�\n\n");
    printf("12-����ά��:�˹��ܿ����޸�ϵͳ��½�������ϵͳ��ȫ�ԣ�\n\n");
    printf("13-���򣺽�ѧ���ɼ����ս������򣬱���ѧ����ѯ���Σ�\n\n");
    printf("14-ͳ�ƣ������ܳɼ�����ĳ�������ߵ�ѧ����Ϣ��\n\n");
    printf("15-�������ѧ���ĳɼ���Ϣ��ӡ����Ļ�ϣ�\n\n");

}

void scoredown()
{
    int n=0,i,j;
    struct student *p,*q,*head,*en;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("���ļ�ʧ�ܣ�\n");
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

   printf("\n\n���� ѧ��  ���� �Ա� ���� ���� סַ  ����  ����  Ӣ��  C����  ��ɢ  ���� ƽ���� �ܷ�\n\n");
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
    printf("���ļ�ʧ�ܣ�\n");
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
printf("����ͳ�ƣ�\n\n");
printf("\t\t\t����ѧ������Ϊ��%d.\n\n",i);
printf("\t\t\t����ѧ������Ϊ��%d.\n\n",j);
printf("\t\t\t���ϸ�ѧ������Ϊ��%d.\n\n",k);

}

void Delete()
{
    struct student *p,*q,*head,*en,*t;
    int i,s;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("���ļ�ʧ�ܣ�\n");
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

printf("��Ҫɾ�������˵���Ϣ��");
scanf("%d",&s);
  long o;
  for(i=0;i<s;i++)
  {
  printf("\n\n��������Ҫɾ���ĵ�%d��ѧ����ѧ�ţ�",i+1);
  scanf("%ld",&o);
  p=head;
   if(p==NULL)
    printf("����Ϊ�գ�\n");
   while(p->num!=o&&p->next!=NULL)
   {
       q=p;
       p=p->next;
   }
   if(p->num==o)
   {
      q->next=p->next;//������ɾ����㣬����һ�����׵�ַ������һ���
      free(p);
      printf("\nɾ���ɹ���");
   }
   else
    printf("\nɾ��ʧ�ܣ�������ѧ�Ŵ�����Ҫɾ���뷵�����˵�����������ȷѧ��ɾ����");
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
    printf("���ļ�ʧ�ܣ�\n");
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

printf("��������Ҫ�޸ĵ�ѧ��������");
scanf("%d",&s);
for(i=0;i<s;i++)
{
system("cls");
printf("\n\n������Ҫ�޸ĵ�%d��ѧ����ѧ��:",i+1);
scanf("%d",&id);
while(q!=NULL)
{
    if(q->num==id)
    {
        printf("\n\n��ѧ����ԭʼ��ϢΪ:\n\n");
printf("**********************************************************************************\n");
printf("*ѧ�š��������Ա����䡢���塢סַ��������Ӣ����C���ԡ���ɢ������(�Կո���Ϊ���,�Իس���Ϊ����)*\n");
printf("**********************************************************************************\n\n");
printf("%d  %s  %s  %d  %s  %s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n\n\n",q->num,q->name,q->sex,q->age,q->nat,q->adress,q->score1,q->score2,q->score3,q->score4,q->score5,q->score6,q->average,q->sum);
printf("�������޸ĺ����Ϣ��\n\n");
scanf("%d %s %s %d %s %s %f %f %f %f %f %f",&q->num,&q->name,&q->sex,&q->age,&q->nat,&q->adress,&q->score1,&q->score2,&q->score3,&q->score4,&q->score5,&q->score6);
      q->sum=q->score1+q->score2+q->score3+q->score4+q->score5+q->score6;
      q->average=q->sum/6;
    j++;
    break;
    }
    q=q->next;
}
if(j==0)
    printf("û�и�ѧ������Ϣ");


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
printf("\t\t\t�޸���ϣ�\n\n\n");
}

void add()
{

    int i,s;
    struct student *p,*q,*head,*en,*t,*p1,*p2;
    FILE *fp;
    fp=fopen("entering.txt","a+");
if((fp=fopen("entering.txt","a+"))==NULL)
{
    printf("���ļ�ʧ�ܣ�\n");
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


printf("������Ҫ��ӵ�ѧ��������");
scanf("%d",&s);

for(i=0;i<s;i++)
{
    system("cls");
    printf("\n��������ӵĵ�%d��ѧ������Ϣ:\n\n",i+1);
    printf("**********************************************************************************\n");
    printf("*ѧ�š��������Ա����䡢���塢סַ��������Ӣ����C���ԡ���ɢ������(�Կո���Ϊ���,�Իس���Ϊ����)*\n");
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
    printf("���ļ�ʧ�ܣ�\n");
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
printf("\t\t\t\t������ϣ�\n");
}
void ggmm()
{
FILE *fp;
int i;
char col[20];
system("cls");
if((fp=fopen("stu_code","wb"))==NULL)
{
printf("�ļ���ʧ�ܣ�");
}
else
{
printf("\n\n������������:");
scanf("%s",col);
for(i=0;i<20;i++)
fwrite(&col[i],sizeof(char),1,fp);
fclose(fp);
printf("\n\n\n��������ɹ���");
}
}

void recover()
{
  struct student *p,*q,*head,*en;
FILE *fp;
fp=fopen("beifen.txt","a+");
if((fp=fopen("beifen.txt","a+"))==NULL)
{
    printf("���ļ�ʧ�ܣ�\n");
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
printf("\t\t\t���ݻָ���ϣ�\n\n\n");

}
#endif // ENTERING_H_INCLUDED

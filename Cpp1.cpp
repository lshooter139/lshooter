#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

 

 


typedef  struct salary//нˮ�ṹ��
{
int      month;//�·�
float    reward;//����
float    deduct;//�۳�
float    base;//��������
float    pay;//нˮ
struct  salary  *next;//�¸��ṹ��
}sa;

 


typedef  struct employee
{
char    num[10];//����
char    name[20];//����
char    career[20];//ְ��ͬ�����ʲ�ͬ


struct  salary *shead;//������ָ��
struct  salary *si;//���ʻָ��

struct employee *next;//�¸��ṹ��  
}em;

 

 

 

em *phead=NULL;//���нṹ��ͷָ��
em *pi=NULL;//���ָ��,��ʱָ���ڴ������һ���ṹ�塣

 


//��ʼ�ļ�
void read()
{
FILE *fp;//�ļ�ָ��
fp=fopen("employee.txt","r");
if(fp==NULL){printf("/n/n�ļ������ڣ�");return;}
fseek(fp,0,SEEK_END);
int n;
n=ftell(fp)/sizeof(em);//����ļ��нṹ��ĸ���
             

rewind(fp);//ʹ�ļ�ָ��ָ��ͷ

em *p;
     
int i;


for(i=0;i<n;i++)
{
p=(em*)malloc(sizeof(em));
fread(p,sizeof(em),1,fp);//����NEXTҲд�ŵ��ļ��У�����û�ã���Ϊ��һ�εĵ�ַ
                        //����������

p->next=NULL;
p->shead=NULL;
p->si=NULL;

if(phead==NULL)phead=pi=p;//����ǵ�һ���͸�ͷָ��
else { pi->next=p;  pi=p;}//����PI����ָ�����һ��


//�����ʼ���ù��ŵĹ���

FILE *fp1;
fp1=fopen(p->num,"r");

if(fp1==NULL){printf("�޹���ѶϢ��");goto loop;}
fseek(fp1,0,SEEK_END);
int n1;
n1=ftell(fp1)/sizeof(sa);//����ļ��нṹ��ĸ���

rewind(fp1);

sa *p1;
int j;
for(j=0;j<n1;j++)
{

p1=(sa*)malloc(sizeof(sa));
fread(p1,sizeof(sa),1,fp1);//����NEXTҲ�ŵ��ļ���
p1->next=NULL;

if(p->shead==NULL)p->shead=p->si=p1;
else  {p->si->next=p1;p->si=p1;}//����si����ָ�����һ��
}
fclose(fp1);
//��ʼ���ù��ŵĹ���

loop:;


}//for�Ľ�β

fclose(fp);

//printf("/n/n�ļ���ʼ�ɹ���");

}

 

 


//�½�Ա������
void  add()
{
em *p;

p=(em*)malloc(sizeof(em));


printf("\n  ���� �� Ա ��������");

loop:
printf("\n ���ţ�");
scanf("%s",p->num);
em *pj=phead;

while(pj)//�����Ƿ�����ǰ�Ĺ����ظ�
{
 if(strcmp(pj->num,p->num)==0)
{printf("\n�����ظ������������룡");goto loop;}
pj=pj->next;
}

 
printf("  \n   ������ ");
scanf("%s",p->name);
loop1:
printf("  \n   ְ��(�� manager��employee��cleaner)");
scanf("%s",p->career);
if((strcmp(p->career,"manager")!=0)&&(strcmp(p->career,"employee")!=0)&&(strcmp(p->career,"cleaner")!=0))
{ printf("\n��������������ְ��");goto loop1;}//���������

p->next=NULL;
p->shead=NULL;//û���κ�һ���µĹ���
p->si=NULL;
if(phead==NULL) phead=pi=p;
else    {pi->next=p;pi=pi->next;}//pi���������е����һ��

printf("\nԱ����Ϣ�½��ɹ�!\n");

}

 


//�޸�Ա������
void modify()
{

printf(" \n ���� �� Ա ��������");

loop4:
char num[20];
em *p=phead;
printf(" \n���ţ�");
scanf("%s",num);
int y=1;

//��һ��while
while(p)
{
 if(strcmp(p->num,num)==0)//��һ��if
 {
 y=0;
printf("\n ���޸������� ");
scanf("%s",p->name);

loop1:
printf("\n ���޸�ְ��(�� manager��employee��cleaner)");
scanf("%s",p->career);
 

 if((strcmp(p->career,"manager")!=0)&&(strcmp(p->career,"employee")!=0)&&(strcmp(p->career,"cleaner")!=0))
   { printf("\n��������������ְ��");goto loop1;    }//���������

 

if(p->shead)//֤���й�����Ϣ
{         printf("\n�Ƿ��޸Ĺ�����Ϣ����(y),�˳�(q)!");
          char k;
           k=getch();
  
         if(k=='y')//�޸Ĺ�����Ϣ
    {
         loop3:
   
         int m,y3=1;     
         printf("\n �������·ݣ� ");
         scanf("%d",&m);

             if(m>12||m<1)
    {   printf("\n���������������·ݣ�");goto loop3;    }
         
  
   sa  *p1=p->shead;
   while(p1)
         {            
    
    
    if(p1->month==m)
    {y3=0;
           printf(" \n���޸�ҵ��������");
           scanf("%f",&p1->reward);
     printf(" \n���޸�ҵ���۳���");
           scanf("%f",&p1->deduct);

    }


       p1=p1->next;

   }
    if(y3) printf("\n�����޸��·ݹ��ʣ�");  
         
 printf("\n�Ƿ�����޸Ĺ�����Ϣ����(y),�˳�(q)!");
          char kk;
           kk=getch();  
   if(kk=='y')goto  loop3;
   
   
 
   }


       

 

}//���ʵ�if������
else  printf("\n�޹��ʺ�����Ϣ!");

 


 }//��һ��if
p=p->next;

}//��һ��while

 

 

   if(y)
   {     printf("\n���Ŵ���,���������밴n,�˳��밴q!");
      char k;
      k=getch();
      if(k=='n')goto  loop4;
      if(k=='q')printf("\nԱ����Ϣ�޸�ʧ�ܣ�");   
   }
   else printf("\nԱ����Ϣ�޸ĳɹ���/n");

 

 

}

 

 

 

 

//ɾ��Ա������
void del()
{

printf("\n  ��ɾ �� Ա ��������");

loop:

char num[20]; 
char k;//����ѡ��

int y=1;//�ж��Ƿ��иù���
int y1=0;//��Ϊ��һ��ָ�뿪ʼ�ı�ʶ


em *p=phead;
em *p2=phead;//��һ��ָ��

printf("\n������Ҫɾ���Ĺ��ţ�");
scanf("%s",num);

while(p)//��һ��while
{
 
 
 
 if(strcmp(p->num,num)==0)//��һ��if//�иù���
 {
        y=0;
       
       
      printf("\n�Ƿ�Ҫɾ����Ա��(����������Ϣ�빤����Ϣ),��(y),��(n)!"); 
  k=getch();

        if(k=='y')//ɾ����Ա��(����������Ϣ�빤����Ϣ)��ʼ����
  {
  if(p==phead)phead=phead->next;
  else p2->next=p->next;//�Ѿ������˸�Ա��
         
      


       if(p->shead)//֤���й�����Ϣ����Ҫ�ͷſռ�
  { 
    sa *p3=p->shead;
          sa  *temp;
          while(p3)

    {
           temp=p3->next;//�ȴ����һ��
           free(p3); //�ͷ��ڴ�
           p3=temp;      }//���ʿռ�ȫ���ͷ�

    }

 

          
  free(p);//�ͷ�Ա�������ռ�
     goto  end;

  }    //ɾ����Ա��(����������Ϣ�빤����Ϣ)������

 

 


 if(p->shead)//֤���й�����Ϣ
{     
        printf("\n�Ƿ�ɾ��Ա���·ݹ�����Ϣ����(y),��(n)!"); 
  k=getch();
        if(k!='y')goto  end;  


printf("          [ɾ���˵�]");
//printf("/n|-----------------------------------|"); 
printf("/n|       ��ѡ����ɾ����ʽ:         |"); 
//printf("/n|-----------------------------------|"); 
printf("/n|          A[ ɾ�������·� ]        |"); 
//printf("/n|-----------------------------------|"); 
printf("/n|          B[ ɾ�������·� ]        |");    
//printf("/n|-----------------------------------|"); 
printf("/n|          C[    �˳�     ]         |");    
//printf("/n|-----------------------------------|");

   
  
         
           k=getch();
  
         if(k=='a'||k=='A')
    {//a��if
         loop1:

          int m,y2=1;//�ж��Ƿ��и��·� 
    int y3=0;//��Ϊ��һ��ָ�뿪ʼ�ı�ʶ
    
         printf("\n ������Ҫɾ�����·ݣ� ");
         scanf("%d",&m);

             if(m>12||m<1)
    {   printf("\n���������������·ݣ�");goto loop1;    }
        

  
   sa  *p3=p->shead;//ǰһ��ָ��
   sa  *p4=p->shead;//��һ��ָ��


   while(p3)
         {  //while  2          
    
     if(p3->month==m)
    {
    
               if(p3==p->shead) p->shead=p->shead->next;
      else  p4->next=p3->next ;  //�Ѿ�����
      y2=0;
    }
              
     y3++;
              p3=p3->next;//ǰһ��ָ��
          if(y3>1)p4=p4->next;//��һ��ָ��

   }  //while  2   

       if(y2) printf("\n�����޸��·ݹ��ʣ�");  
       else {
     free(p3);  //���ʿռ�ȫ���ͷ� 
    printf("%d�·ݹ�����Ϣɾ���ɹ�!",m);
    }


 printf("�Ƿ����ɾ���·ݹ�����Ϣ����(y),��(N)!");
      
           k=getch();
     if(k=='y')goto  loop1;  
     else goto  end; 
   }//a��if

 


       if(k=='b'||k=='B')
    {//b��if
          sa  *p5=p->shead;
          sa  *temp;
          while(p5)
    {
     temp=p5->next;  
     free(p5);
     p5=temp;
    }//�ռ�ȫ���ͷ�

           p->shead=p->si=NULL;//ʹ֮��ΪNULL
           printf("\n��Ա���·ݹ���ȫ��ɾ����");  
           
   }//b��if

 

}//���ʵ�if������

else  printf("\n�޹��ʺ�����Ϣ!");//���Ƿ��й�����Ϣif����

 

 }//��һ��if

 

 

 y1++;//��Ϊ��һ��ָ�뿪ʼ�ı�ʶ
p=p->next;
if(y1>1)p2=p2->next;//��һ��ָ��

 

 

}//��һ��while


end:


   if(y)   printf("\n���Ŵ���Ա����Ϣɾ��ʧ�ܣ�!");
   else    printf("\nԱ����Ϣɾ���ɹ�!");


 printf("\n�Ƿ����ɾ��Ա����Ϣ����(y),��(n)!");   
       k=getch();
      if(k=='y')goto  loop;
 


}

 

 

 

 

 

 

 

 

 

 

//���Ź���ģ��
void  check()
{

printf(" \n ���� �� �� �㨀����");
char  n[30];
int y1=1;
loop:
printf(" \n���ţ�");//���빤�ţ����·ݹ��ʵ�����
scanf("%s",n);

em *p=phead;

while(p)
{
      if(strcmp(p->num,n)==0)//��鹤�ţ������������Ϣ

 {
  printf(" \n ��˶�Ա����Ϣ��");
        printf("    /t������%s      ",p->name);  
  
       printf("  \n ְ��");
     if(strcmp(p->career,"manager")==0) printf(" \n����");
     if(strcmp(p->career,"employee")==0)printf(" \nԱ��");
     if(strcmp(p->career,"cleaner")==0) printf(" \n�����Ա");
  
     printf("\n�Ƿ�����,���������밴n,�����밴y,�˳��밴q!");//����Ǿ����£�������������
     char y;
     y=getch();
      if(y=='n')goto  loop;
      if(y=='q'){printf("\nԱ�����ʺ���ʧ�ܣ�");return;  }

       loop1:
       printf(" \n�·ݣ�");


//����salary�Ŀ��ռ䣬���·ݹ��ʵ�ѶϢ��������ַ��p��p->sshead
         sa *p1;
         p1=(sa*)malloc(sizeof(sa));//����salary�Ŀ��ռ�
         p1->next=NULL;
          scanf("%d",&p1->month);
      if(p1->month>12||p1->month<1)
   { printf("\n���������������·ݣ�");goto loop1;}

          sa *p2=p->shead;//�����Ƿ��Ѿ����˸��·ݵĹ��ʼ�¼
    while(p2)
    {if(p1->month==p2->month){printf("\n���󣬸����Ѿ��˲�,�����������·ݣ�");    goto loop1;}
    p2=p2->next;
    }

 

        printf(" \n��Ա���Ļ�������Ϊ�� ");
       if(strcmp(p->career,"manager")==0)p1->base=10000;
        if(strcmp(p->career,"employee")==0)p1->base=6000;
        if(strcmp(p->career,"cleaner")==0)p1->base=500;
         printf("    %.2f/n",p1->base);


          printf("\n ������ҵ��������");
        scanf("%f",&p1->reward);

        printf(" \n������ҵ���۳���");
          scanf("%f",&p1->deduct);
            
      p1->pay=p1->reward-p1->deduct+p1->base;
        
     if(p->shead==NULL)p->shead=p->si=p1;
         else{p->si->next=p1;  p->si=p->si->next;}


         printf("\n �ܹ���Ϊ%.2f",p1->pay);

         printf("\nԱ��%s  %d�·ݹ�����Ϣ������ϣ�.",p->name,p1->month);

 

        
              y1=0;


   }//if�Ļ�����


        p=p->next;
}

 

if(y1)printf("\nԱ�����ʺ���ʧ�ܣ�");

}

 

 

 

 


void showe()
{
em *p=phead;

if(p==NULL){printf("\nԱ��������ϢΪ��,���½����� ����   ");return;}


printf("        \n����������Ա��������Ϣ���ݿ⨀��������������   ");
//printf("/n/n/n|-------------------------------------------------------------|");


while(p)
{

printf(" \n���ţ�%s           \n ������%s       ",p->num,p->name);  
  
printf(" \nְ��");

if(strcmp(p->career,"manager")==0) printf(" ����");
if(strcmp(p->career,"employee")==0)printf(" Ա��");
if(strcmp(p->career,"cleaner")==0) printf(" �����Ա");
printf(" �������ʣ� ");
float base;
if(strcmp(p->career,"manager")==0)base=10000;
if(strcmp(p->career,"employee")==0)base=6000;
if(strcmp(p->career,"cleaner")==0)base=500;
printf("    %.2f/n",base);
//printf("|-------------------------------------------------------------|/n");

p=p->next;

}

 

}

 

 

 

 

void shows()
{
int y=1;
char n[20];
printf("\n������Ҫ���ҵĹ���:");
   scanf("%s",n);

em *p=phead;  

 while(p)
{
  
  
  if(strcmp(p->num,n)==0)
  {
   y=0;
printf(" \n���ţ�%s            \n������%s       ",p->num,p->name);  
  
printf(" ְ��");
if(strcmp(p->career,"manager")==0) printf(" ����");
if(strcmp(p->career,"employee")==0)printf(" Ա��");
if(strcmp(p->career,"cleaner")==0) printf(" �����Ա");


if(p->shead==NULL){printf("\n�޷���ѯ�������ǹ���δ�������� ��");return;}

sa *p1=p->shead;

 

//printf("/n|-------------------------------------------------------------|/n"); 
while(p1)
{
if(strcmp(p->career,"manager")==0) p1->base=10000;
if(strcmp(p->career,"employee")==0)p1->base=6000;
if(strcmp(p->career,"cleaner")==0) p1->base=500;


printf("�·ݣ�%d     �������ʣ� %.2f\n",p1->month,p1->base);
printf("     ҵ��������  %.2f",p1->reward);
printf("/t/tҵ���۳���%.2f\n",p1->deduct); 
printf("   \n��Ա�����չ��ʣ�  %.2fԪ\n",p1->pay=p1->base+p1->reward-p1->deduct);
//printf("|-------------------------------------------------------------|/n");    

p1=p1->next;

}
  
}//if�Ļ�����

 

p=p->next;

}

if(y)
printf("\nʧ�ܣ���Ҫ���ҵĹ��Ų����ڣ�");


 }


void release()
{

em  *p=phead;
em  *temp;

while(p)
{
temp=p->next;//�ͷ�Ա�������ռ�

 

 

//�ͷŹ�����Ϣ�ռ�

     if(p->shead)//֤���й�����Ϣ����Ҫ�ͷſռ�
  { 
    sa *p1=p->shead;
          sa  *temp;
          while(p1)

    {
           temp=p1->next;//�ȴ����һ��
           free(p1); //�ͷ��ڴ�
           p1=temp;      }//���ʿռ�ȫ���ͷ�
  }

//�ͷŹ�����Ϣ�ռ�

 


free(p);//�ͷ�Ա�������ռ�
p=temp;

}

pi=phead=NULL;
printf("\n���ݿ���Ϣȫ����գ�");

}

 

 

 

 

 

 

 

void save()
{

FILE  *fp;

fp=fopen("employee.txt","w");

em *p;
p=phead;

while(p)
{
fwrite(p,sizeof(em),1,fp);//����employee
 

//����salary
     FILE  *fp1 ; 
 fp1=fopen(p->num,"w");//p->num��һ���ַ����׵�ַ���Թ���Ϊ�ļ�����Ź�����Ϣ
 //ʵ����ʽ�� fp1=fopen("�ļ���","�򿪷�ʽ");
   
    sa *p1;
    p1=p->shead;//�׵�ַ
    while(p1)
 {  
      fwrite(p1,sizeof(sa),1,fp1);//����read 
   p1=p1->next;
 }

   fclose(fp1);


p=p->next;
}

 

fclose(fp);

//printf("/n/n�ļ�����ɹ���");

}

 

 

 

 

 

 

 

void show()
{ 


//printf(" |----------------------------------------|");
printf("   \n    �� ��        ��       �� ��        ");              
//printf("/n |----------------------------------------|");
printf("      \n    1  ��   ѯ                         ");  
//printf("/n |----------------------------------------|"); 
printf("      \n    2  ��   ��                         ");  
//printf("/n |----------------------------------------|"); 
printf("      \n    3  ��   ��                         "); 
//printf("/n |----------------------------------------|"); 
printf("      \n    4  ɾ   ��                         "); 
//printf("/n |----------------------------------------|"); 
printf("      \n    5  ��   ��                         ");
//printf("/n |----------------------------------------|");
printf("      \n    6  �   ��                         ");
//printf("/n |----------------------------------------|");
printf("      \n    7  ��   ��                         ");              
//printf("/n |----------------------------------------|");
printf("      \n      ����ѡ��һ������           "); 
//printf("/n |----------------------------------------|/n/n/n");
}

 

 

/*void show1()
{


//printf(" |-----------------------------|");
printf("  \n   ����  ��  ��   ����      ");              
//printf("/n |-----------------------------|");
printf(" \n  A   ɾ  ��  Ա  ��          ");  
//printf("/n |-----------------------------|"); 
printf(" \n  B   ��  ��  Ա  ��         ");  
//printf("/n |-----------------------------|");  
printf(" \n  C   ��  ��  ��  Ϣ          "); 
//printf("/n |-----------------------------|"); 
printf(" \n  D   ��  ��  ��  ��          "); 
//printf("/n |-----------------------------|"); 
printf(" \n     ����ѡ��һ������         "); 
//printf("/n |-----------------------------|/n/n/n");
}*/

 

 

 

void main()
{

read();

char c1;
do {

 

show();

c1=getch();

 

switch ( c1 )
{

case '1':shows();break;
case '2':modify();break;
//case 'a':
case '3':add();break;

case '4':del();break;

case '5':break;
//case 'b':
case '6':showe();break;
//case 'c':
case 'd':
case 'D':check();break;
case '7':
//case 'e':
	
	//{
	
  /*char c3;

 do{
  show1();
 
       c3=getch();

switch ( c3)
 
{
case 'a':
case 'A':del();break;

case 'b':
case 'B':modify();break;

case 'c':
case 'C':release();break;

case 'd':
case 'D':break;
 

 

 }
 
 }while(c3!='D'&&c3!='d');

 }break;
 

}*/

 

save();

}
}while(c1!='F'&&c1!='f');

}
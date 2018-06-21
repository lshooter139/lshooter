#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

 

 


typedef  struct salary//薪水结构体
{
int      month;//月份
float    reward;//奖励
float    deduct;//扣除
float    base;//基本工资
float    pay;//薪水
struct  salary  *next;//下个结构体
}sa;

 


typedef  struct employee
{
char    num[10];//工号
char    name[20];//姓名
char    career[20];//职务不同，工资不同


struct  salary *shead;//工资首指针
struct  salary *si;//工资活动指针

struct employee *next;//下个结构体  
}em;

 

 

 

em *phead=NULL;//所有结构体头指针
em *pi=NULL;//随机指针,随时指向内存中最后一个结构体。

 


//初始文件
void read()
{
FILE *fp;//文件指针
fp=fopen("employee.txt","r");
if(fp==NULL){printf("/n/n文件不存在！");return;}
fseek(fp,0,SEEK_END);
int n;
n=ftell(fp)/sizeof(em);//算出文件中结构体的个数
             

rewind(fp);//使文件指针指向开头

em *p;
     
int i;


for(i=0;i<n;i++)
{
p=(em*)malloc(sizeof(em));
fread(p,sizeof(em),1,fp);//就连NEXT也写放到文件中，但是没用，因为上一次的地址
                        //是随机分配的

p->next=NULL;
p->shead=NULL;
p->si=NULL;

if(phead==NULL)phead=pi=p;//如果是第一个就给头指针
else { pi->next=p;  pi=p;}//利用PI总是指向最后一个


//下面初始化该工号的工资

FILE *fp1;
fp1=fopen(p->num,"r");

if(fp1==NULL){printf("无工资讯息！");goto loop;}
fseek(fp1,0,SEEK_END);
int n1;
n1=ftell(fp1)/sizeof(sa);//算出文件中结构体的个数

rewind(fp1);

sa *p1;
int j;
for(j=0;j<n1;j++)
{

p1=(sa*)malloc(sizeof(sa));
fread(p1,sizeof(sa),1,fp1);//就连NEXT也放到文件中
p1->next=NULL;

if(p->shead==NULL)p->shead=p->si=p1;
else  {p->si->next=p1;p->si=p1;}//利用si总是指向最后一个
}
fclose(fp1);
//初始化该工号的工资

loop:;


}//for的结尾

fclose(fp);

//printf("/n/n文件初始成功！");

}

 

 


//新建员工档案
void  add()
{
em *p;

p=(em*)malloc(sizeof(em));


printf("\n  █增 加 员 工█　：");

loop:
printf("\n 工号：");
scanf("%s",p->num);
em *pj=phead;

while(pj)//检验是否与以前的工号重复
{
 if(strcmp(pj->num,p->num)==0)
{printf("\n工号重复，请重新输入！");goto loop;}
pj=pj->next;
}

 
printf("  \n   姓名： ");
scanf("%s",p->name);
loop1:
printf("  \n   职务：(填 manager或employee或cleaner)");
scanf("%s",p->career);
if((strcmp(p->career,"manager")!=0)&&(strcmp(p->career,"employee")!=0)&&(strcmp(p->career,"cleaner")!=0))
{ printf("\n错误，请重新输入职务！");goto loop1;}//不允许输错

p->next=NULL;
p->shead=NULL;//没有任何一个月的工资
p->si=NULL;
if(phead==NULL) phead=pi=p;
else    {pi->next=p;pi=pi->next;}//pi总是链表中的最后一个

printf("\n员工信息新建成功!\n");

}

 


//修改员工档案
void modify()
{

printf(" \n █修 改 员 工█　：");

loop4:
char num[20];
em *p=phead;
printf(" \n工号：");
scanf("%s",num);
int y=1;

//第一个while
while(p)
{
 if(strcmp(p->num,num)==0)//第一个if
 {
 y=0;
printf("\n 请修改姓名： ");
scanf("%s",p->name);

loop1:
printf("\n 请修改职务：(填 manager或employee或cleaner)");
scanf("%s",p->career);
 

 if((strcmp(p->career,"manager")!=0)&&(strcmp(p->career,"employee")!=0)&&(strcmp(p->career,"cleaner")!=0))
   { printf("\n错误，请重新输入职务！");goto loop1;    }//不允许输错

 

if(p->shead)//证明有工资信息
{         printf("\n是否修改工资信息，是(y),退出(q)!");
          char k;
           k=getch();
  
         if(k=='y')//修改工资信息
    {
         loop3:
   
         int m,y3=1;     
         printf("\n 请输入月份： ");
         scanf("%d",&m);

             if(m>12||m<1)
    {   printf("\n错误，请重新输入月份！");goto loop3;    }
         
  
   sa  *p1=p->shead;
   while(p1)
         {            
    
    
    if(p1->month==m)
    {y3=0;
           printf(" \n请修改业绩奖励：");
           scanf("%f",&p1->reward);
     printf(" \n请修改业绩扣除：");
           scanf("%f",&p1->deduct);

    }


       p1=p1->next;

   }
    if(y3) printf("\n错误，无该月份工资！");  
         
 printf("\n是否继续修改工资信息，是(y),退出(q)!");
          char kk;
           kk=getch();  
   if(kk=='y')goto  loop3;
   
   
 
   }


       

 

}//工资的if回括号
else  printf("\n无工资核算信息!");

 


 }//第一个if
p=p->next;

}//第一个while

 

 

   if(y)
   {     printf("\n工号错误,重新输入请按n,退出请按q!");
      char k;
      k=getch();
      if(k=='n')goto  loop4;
      if(k=='q')printf("\n员工信息修改失败！");   
   }
   else printf("\n员工信息修改成功！/n");

 

 

}

 

 

 

 

//删除员工档案
void del()
{

printf("\n  █删 除 员 工█　：");

loop:

char num[20]; 
char k;//输入选择

int y=1;//判断是否有该工号
int y1=0;//作为后一个指针开始的标识


em *p=phead;
em *p2=phead;//后一个指针

printf("\n请输入要删除的工号：");
scanf("%s",num);

while(p)//第一个while
{
 
 
 
 if(strcmp(p->num,num)==0)//第一个if//有该工号
 {
        y=0;
       
       
      printf("\n是否要删除该员工(包括基本信息与工资信息),是(y),否(n)!"); 
  k=getch();

        if(k=='y')//删除该员工(包括基本信息与工资信息)开始括号
  {
  if(p==phead)phead=phead->next;
  else p2->next=p->next;//已经跳过了该员工
         
      


       if(p->shead)//证明有工资信息，需要释放空间
  { 
    sa *p3=p->shead;
          sa  *temp;
          while(p3)

    {
           temp=p3->next;//先存放下一个
           free(p3); //释放内存
           p3=temp;      }//工资空间全部释放

    }

 

          
  free(p);//释放员工基本空间
     goto  end;

  }    //删除该员工(包括基本信息与工资信息)完括号

 

 


 if(p->shead)//证明有工资信息
{     
        printf("\n是否删除员工月份工资信息，是(y),否(n)!"); 
  k=getch();
        if(k!='y')goto  end;  


printf("          [删除菜单]");
//printf("/n|-----------------------------------|"); 
printf("/n|       请选择工资删除方式:         |"); 
//printf("/n|-----------------------------------|"); 
printf("/n|          A[ 删除单个月份 ]        |"); 
//printf("/n|-----------------------------------|"); 
printf("/n|          B[ 删除所有月份 ]        |");    
//printf("/n|-----------------------------------|"); 
printf("/n|          C[    退出     ]         |");    
//printf("/n|-----------------------------------|");

   
  
         
           k=getch();
  
         if(k=='a'||k=='A')
    {//a的if
         loop1:

          int m,y2=1;//判断是否有该月份 
    int y3=0;//作为后一个指针开始的标识
    
         printf("\n 请输入要删除的月份： ");
         scanf("%d",&m);

             if(m>12||m<1)
    {   printf("\n错误，请重新输入月份！");goto loop1;    }
        

  
   sa  *p3=p->shead;//前一个指针
   sa  *p4=p->shead;//后一个指针


   while(p3)
         {  //while  2          
    
     if(p3->month==m)
    {
    
               if(p3==p->shead) p->shead=p->shead->next;
      else  p4->next=p3->next ;  //已经跳过
      y2=0;
    }
              
     y3++;
              p3=p3->next;//前一个指针
          if(y3>1)p4=p4->next;//后一个指针

   }  //while  2   

       if(y2) printf("\n错误，无该月份工资！");  
       else {
     free(p3);  //工资空间全部释放 
    printf("%d月份工资信息删除成功!",m);
    }


 printf("是否继续删除月份工资信息，是(y),否(N)!");
      
           k=getch();
     if(k=='y')goto  loop1;  
     else goto  end; 
   }//a的if

 


       if(k=='b'||k=='B')
    {//b的if
          sa  *p5=p->shead;
          sa  *temp;
          while(p5)
    {
     temp=p5->next;  
     free(p5);
     p5=temp;
    }//空间全部释放

           p->shead=p->si=NULL;//使之成为NULL
           printf("\n该员工月份工资全部删除！");  
           
   }//b的if

 

}//工资的if回括号

else  printf("\n无工资核算信息!");//与是否有工资信息if相配

 

 }//第一个if

 

 

 y1++;//作为后一个指针开始的标识
p=p->next;
if(y1>1)p2=p2->next;//后一个指针

 

 

}//第一个while


end:


   if(y)   printf("\n工号错误，员工信息删除失败！!");
   else    printf("\n员工信息删除成功!");


 printf("\n是否继续删除员工信息，是(y),否(n)!");   
       k=getch();
      if(k=='y')goto  loop;
 


}

 

 

 

 

 

 

 

 

 

 

//发放工资模块
void  check()
{

printf(" \n █工 资 核 算█　：");
char  n[30];
int y1=1;
loop:
printf(" \n工号：");//输入工号，即月份工资的填入
scanf("%s",n);

em *p=phead;

while(p)
{
      if(strcmp(p->num,n)==0)//检查工号，并输出其它信息

 {
  printf(" \n 请核对员工信息：");
        printf("    /t姓名：%s      ",p->name);  
  
       printf("  \n 职务：");
     if(strcmp(p->career,"manager")==0) printf(" \n经理");
     if(strcmp(p->career,"employee")==0)printf(" \n员工");
     if(strcmp(p->career,"cleaner")==0) printf(" \n清洁人员");
  
     printf("\n是否有误,重新输入请按n,继续请按y,退出请按q!");//如果是就往下，否则重新输入
     char y;
     y=getch();
      if(y=='n')goto  loop;
      if(y=='q'){printf("\n员工工资核算失败！");return;  }

       loop1:
       printf(" \n月份：");


//开辟salary的开空间，放月份工资等讯息，并把首址给p的p->sshead
         sa *p1;
         p1=(sa*)malloc(sizeof(sa));//开辟salary的开空间
         p1->next=NULL;
          scanf("%d",&p1->month);
      if(p1->month>12||p1->month<1)
   { printf("\n错误，请重新输入月份！");goto loop1;}

          sa *p2=p->shead;//检验是否已经有了该月份的工资记录
    while(p2)
    {if(p1->month==p2->month){printf("\n错误，该月已经核查,请重新输入月份！");    goto loop1;}
    p2=p2->next;
    }

 

        printf(" \n该员工的基本工资为： ");
       if(strcmp(p->career,"manager")==0)p1->base=10000;
        if(strcmp(p->career,"employee")==0)p1->base=6000;
        if(strcmp(p->career,"cleaner")==0)p1->base=500;
         printf("    %.2f/n",p1->base);


          printf("\n 请输入业绩奖励：");
        scanf("%f",&p1->reward);

        printf(" \n请输入业绩扣除：");
          scanf("%f",&p1->deduct);
            
      p1->pay=p1->reward-p1->deduct+p1->base;
        
     if(p->shead==NULL)p->shead=p->si=p1;
         else{p->si->next=p1;  p->si=p->si->next;}


         printf("\n 总工资为%.2f",p1->pay);

         printf("\n员工%s  %d月份工资信息核算完毕！.",p->name,p1->month);

 

        
              y1=0;


   }//if的回括号


        p=p->next;
}

 

if(y1)printf("\n员工工资核算失败！");

}

 

 

 

 


void showe()
{
em *p=phead;

if(p==NULL){printf("\n员工基本信息为空,请新建！　 　　   ");return;}


printf("        \n　　　　█员工基本信息数据库█　　　　　　　   ");
//printf("/n/n/n|-------------------------------------------------------------|");


while(p)
{

printf(" \n工号：%s           \n 姓名：%s       ",p->num,p->name);  
  
printf(" \n职务：");

if(strcmp(p->career,"manager")==0) printf(" 经理");
if(strcmp(p->career,"employee")==0)printf(" 员工");
if(strcmp(p->career,"cleaner")==0) printf(" 清洁人员");
printf(" 基本工资： ");
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
printf("\n请输入要查找的工号:");
   scanf("%s",n);

em *p=phead;  

 while(p)
{
  
  
  if(strcmp(p->num,n)==0)
  {
   y=0;
printf(" \n工号：%s            \n姓名：%s       ",p->num,p->name);  
  
printf(" 职务：");
if(strcmp(p->career,"manager")==0) printf(" 经理");
if(strcmp(p->career,"employee")==0)printf(" 员工");
if(strcmp(p->career,"cleaner")==0) printf(" 清洁人员");


if(p->shead==NULL){printf("\n无法查询，可能是工资未经过核算 ！");return;}

sa *p1=p->shead;

 

//printf("/n|-------------------------------------------------------------|/n"); 
while(p1)
{
if(strcmp(p->career,"manager")==0) p1->base=10000;
if(strcmp(p->career,"employee")==0)p1->base=6000;
if(strcmp(p->career,"cleaner")==0) p1->base=500;


printf("月份：%d     基本工资： %.2f\n",p1->month,p1->base);
printf("     业绩奖励：  %.2f",p1->reward);
printf("/t/t业绩扣除：%.2f\n",p1->deduct); 
printf("   \n█员工最终工资：  %.2f元\n",p1->pay=p1->base+p1->reward-p1->deduct);
//printf("|-------------------------------------------------------------|/n");    

p1=p1->next;

}
  
}//if的回括号

 

p=p->next;

}

if(y)
printf("\n失败，您要查找的工号不存在！");


 }


void release()
{

em  *p=phead;
em  *temp;

while(p)
{
temp=p->next;//释放员工基本空间

 

 

//释放工资信息空间

     if(p->shead)//证明有工资信息，需要释放空间
  { 
    sa *p1=p->shead;
          sa  *temp;
          while(p1)

    {
           temp=p1->next;//先存放下一个
           free(p1); //释放内存
           p1=temp;      }//工资空间全部释放
  }

//释放工资信息空间

 


free(p);//释放员工基本空间
p=temp;

}

pi=phead=NULL;
printf("\n数据库信息全部清空！");

}

 

 

 

 

 

 

 

void save()
{

FILE  *fp;

fp=fopen("employee.txt","w");

em *p;
p=phead;

while(p)
{
fwrite(p,sizeof(em),1,fp);//保存employee
 

//保存salary
     FILE  *fp1 ; 
 fp1=fopen(p->num,"w");//p->num是一个字符串首地址，以工号为文件名存放工资信息
 //实际形式是 fp1=fopen("文件名","打开方式");
   
    sa *p1;
    p1=p->shead;//首地址
    while(p1)
 {  
      fwrite(p1,sizeof(sa),1,fp1);//保存read 
   p1=p1->next;
 }

   fclose(fp1);


p=p->next;
}

 

fclose(fp);

//printf("/n/n文件保存成功！");

}

 

 

 

 

 

 

 

void show()
{ 


//printf(" |----------------------------------------|");
printf("   \n    █ 主        菜       单 █        ");              
//printf("/n |----------------------------------------|");
printf("      \n    1  查   询                         ");  
//printf("/n |----------------------------------------|"); 
printf("      \n    2  修   改                         ");  
//printf("/n |----------------------------------------|"); 
printf("      \n    3  添   加                         "); 
//printf("/n |----------------------------------------|"); 
printf("      \n    4  删   除                         "); 
//printf("/n |----------------------------------------|"); 
printf("      \n    5  保   存                         ");
//printf("/n |----------------------------------------|");
printf("      \n    6  浏   览                         ");
//printf("/n |----------------------------------------|");
printf("      \n    7  退   出                         ");              
//printf("/n |----------------------------------------|");
printf("      \n      请您选择一个任务           "); 
//printf("/n |----------------------------------------|/n/n/n");
}

 

 

/*void show1()
{


//printf(" |-----------------------------|");
printf("  \n   █管  理  菜   单█      ");              
//printf("/n |-----------------------------|");
printf(" \n  A   删  除  员  工          ");  
//printf("/n |-----------------------------|"); 
printf(" \n  B   修  改  员  工         ");  
//printf("/n |-----------------------------|");  
printf(" \n  C   清  空  信  息          "); 
//printf("/n |-----------------------------|"); 
printf(" \n  D   退  出  程  序          "); 
//printf("/n |-----------------------------|"); 
printf(" \n     请您选择一个任务         "); 
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
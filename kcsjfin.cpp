#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define NUM 100      //系统容量
void enter();        //输入职工工资数据函数
int read();          //读取职工工资数据函数
void write(int);     //保存职工工资数据函数
void find();         //查询职工工资数据函数
void list();         //浏览职工工资数据函数
void modify();       //修改职工工资数据函数
void del();          //删除职工工资数据函数
void add();          //添加职工工资数据函数
void grsds(int);     //计算个人所得税函数
void menu();         //主页菜单
struct employee      //职工数据结构
{
 char number[11];    //1~10位数字
 char name[11];      //1~10个字母或1~5个汉字
 float gwgz;         //岗位工资                   
 float xjgz;         //薪级工资                   
 float zwjt;         //职务津贴                  
 float jxgz;         //绩效工资                   
 float yfgz;         //应发工资                   
 float sui;          //个人所得税
 float sfgz;         //实发工资                   
}zggz[NUM];
void menu()
{ 


//printf(" |----------------------------------------|");
printf("   \n###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###");              
printf("\n\n请选择<1-7>:");
printf("\n========================================================================");  
printf("\n|                          1.查询职工工资记录                          |");  
printf("\n|                          2.修改职工工资记录                          |"); 
printf("\n|                          3.添加职工工资记录                          |"); 
printf("\n|                          4.删除职工工资记录                          |");
printf("\n|                          5.保存数据到文件                            |");
printf("\n|                          6.浏览职工记录                              |");
printf("\n|                          7.退出系统                                  |");              
printf("\n========================================================================");
printf("      \n      你的选择是:           "); 
}

int main()
{
	int n,flag;
	while(1)
	{
		do
		{
			
			menu();	
			printf("[ ]\b\b");
			scanf("%s",n);
			if(n>=1&&n<=7)
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
				printf("请输入正确选项！");
			}
		}
	while(flag==0);
	switch(n)
	{
		//case 1: enter(); break;
	    case 1: find(); break;
	    case 2: modify(); break;
	    case 3: add(); break;
	    case 4: del(); break;
		//case 5: write();break;	
	    case 6: list(); break; 
        case 7:printf("\n欢迎下次使用\n\n");
        default:exit(0);              //退出系统
	}
	}
	return 0;
}
//输入模块======================完成

void write(int m)
{
	int i;
	FILE *fp;
	if ((fp=fopen("gz.dat","wb"))==NULL) 
	{
		printf("无法打开文件");
		exit(0);
	}
   for (i=0;i<m;i++)                                       /*将内存中职工的信息输出到磁盘文件中去*/
   if (fwrite(&zggz[i],sizeof(struct employee),1,fp)!=1)   //如果没有正确写入
   printf("写入失败");
   fclose(fp);

}
//读取模块======================完成
int read()
{
	FILE *fp;
	int i=0;
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		printf("无法打开文件");
		exit(0);
	}
	else
	{
		do
		{
			fread(&zggz[i],sizeof(struct employee),1,fp);
			i++;
		}
		while(feof(fp)==0);
	}
	fclose(fp);
	return(i-1);
}
//浏览模块======================完成
void list()
{
	int i;
	int m=read();
	printf("--------------------------------------------------------------------------------");
	printf("工号  姓名    岗位工资  薪级工资  职务津贴  绩效工资  应发工资   税率   实付工资");
	for(i=0;i<m;i++)
	{
		cout<<zggz[i].number<<"    "
			<<zggz[i].name<<"      "
			<<zggz[i].gwgz<<"      "
			<<zggz[i].xjgz<<"      "
			<<zggz[i].zwjt<<"      "
			<<zggz[i].jxgz<<"      "
			<<zggz[i].yfgz;
		     grsds(i);
		cout<<endl;
	}
	printf("--------------------------------------------------------------------------------");
	printf("按任意键继续");
	getchar();
	getchar();
	system("cls");
}
//删除模块======================完成
void del()
{
	int m=read();
	int i,j,n,t,flag;
	char gonghao[11];
    printf("当前职工信息：");
	list();
	cout<<endl;
	cout<<"请输入要删除的职工工号：";
	cin>>gonghao;
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(zggz[i].number,gonghao)==0)
		{
			cout<<"--------------------------------------------------------------"<<endl;
			cout<<"要删除的职工信息："<<endl;
			cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资  应发工资"<<endl;
			cout<<zggz[i].number<<" "<<zggz[i].name<<" "<<zggz[i].gwgz<<" "<<zggz[i].xjgz<<" "<<zggz[i].zwjt<<" "<<zggz[i].jxgz<<" "<<zggz[i].yfgz<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
		    cout<<"确认删除请按1，放弃删除请按0"<<endl;
		    cin>>n;
		    if(n==1)                               //从该记录开始每条记录向前移一条记录
		    {
			for(j=i;j<m;j++)
			{
				zggz[j]=zggz[j+1];
			}
		    }
		flag=0;		
	    }
	}
	if(!flag)
	{
		m=m-1;
		cout<<"删除成功"<<endl;;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	cout<<"当前所有职工信息"<<endl;
	write(m);
	list();
	cout<<"继续删除请按1，放弃删除请按2"<<endl;
	cin>>t;
	switch(t)
	{
	    case 1:del(); break;
		case 2:break;
		default:break;
	}
	system("cls");
}
//查询模块======================完成
void find()
{
	int t,i,flag;
	int m=read();
	char gonghao[11];
	cout<<"请输入想要查询的职工工号:"<<endl;
	cin>>gonghao;
	 for(flag=1,i=0;flag&&i<m;i++)
	 {
		 if(strcmp(zggz[i].number,gonghao)==0)
		{
			cout<<"--------------------------------------------------------------"<<endl;
			cout<<"你要查询的是："<<endl;
			cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资  应发工资"<<endl;
			cout<<zggz[i].number<<"   "
			    <<zggz[i].name<<"     "
			    <<zggz[i].gwgz<<"     "
			    <<zggz[i].xjgz<<"     "
			    <<zggz[i].zwjt<<"     "
			    <<zggz[i].jxgz<<"     "
			    <<zggz[i].yfgz<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
	}
	if(i==m)
	{
		cout<<"查无此人"<<endl;
	}
	cout<<"继续查询请按1，返回请按2"<<endl;
	cin>>t;
	switch(t)
	{
	    case 1:find(); break;
		case 2: system("cls"); break;
		default:break;
	}
}
//修改模块======================完成
void modify()
{
	 char num[11];    //1~10位数字
     char nam[11];      //1~10个字母或1~5个汉字
     float Gwgz;         //岗位工资                   
     float Xjgz;         //薪级工资                   
     float Zwjt;         //职务津贴                  
     float Jxgz;         //绩效工资                                    
	 int b,c,i,n,t,flag;
	 int m=read();
	 char gonghao[11];
	 cout<<"当前职工信息："<<endl;
	 list();
	 cout<<"请输入要修改的职工工号：";
	 cin>>gonghao;
	 for(flag=1,i=0;flag&&i<m;i++)
	 {
		 if(strcmp(zggz[i].number,gonghao)==0)
		{
			cout<<"--------------------------------------------------------------"<<endl;
			cout<<"要修改的职工信息："<<endl;
			cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资  应发工资"<<endl;
			cout<<zggz[i].number<<"      "
			    <<zggz[i].name<<"        "
			    <<zggz[i].gwgz<<"        "
			    <<zggz[i].xjgz<<"        "
			    <<zggz[i].zwjt<<"        "
			    <<zggz[i].jxgz<<"        "
			    <<zggz[i].yfgz<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
	 	cout<<"确认要修改这名职工请按1，放弃修改请按0"<<endl;
		cin>>n;
		if(n==1)
		{
			cout<<"请输入要修改的选项：1.工号 2.姓名 3.岗位工资  4.薪级工资 5.职务津贴  6.绩效工资 "<<endl;
			cin>>c;
			if(c>6||c<1)
			{
				cout<<"选择错误请重新输入"<<endl;
			}	
		}
		flag=0;
		}
	 }
	 if(flag==1)
	 {
		 cout<<"查无此人"<<endl;
	 }
		 do
		 {
			 switch(c)                   //当找到第i个职工时,for语句后i自加了1,所以下面的应该把改后的信息赋值给第i-1个人
			 {
			    case 1:
					   cout<<"工号改为：";
					   cin>>num;
					   strcpy(zggz[i-1].number,num);
					   break;
				case 2:
					   cout<<"姓名改为：";
					   cin>>nam;
					   strcpy(zggz[i-1].name,nam);
					   break;
				case 3:
					   cout<<"岗位工资改为：";
					   cin>>Gwgz;
					   zggz[i-1].gwgz=Gwgz;
					   break;
			    case 4:
					   cout<<"薪级工资改为：";
					   cin>>Xjgz;
					   zggz[i-1].xjgz=Xjgz;
					   break;
				case 5:
					   cout<<"职务津贴改为：";
					   cin>>Zwjt;
					   zggz[i-1].zwjt=Zwjt;
					   break;
				case 6:
					   cout<<"绩效工资改为：";
					   cin>>Jxgz;
					   zggz[i-1].jxgz=Jxgz;
					   break;
			 }
			 cout<<endl;
			 cout<<"确认请按1，重新修改请按2"<<endl;
			 cin>>b;
		 }
		 while(b==2);
		 {
			 cout<<"修改后的所有职工信息为："<<endl;
			 write(m);
			 list();
		 }
		 cout<<"继续修改请按1,返回请按任意键";
		 cin>>t;
		 switch(t)
			{
			     case 1:modify(); break;
				 default:break;
			 }
		 system("cls");
}
//添加模块======================完成
void add()
{
	FILE *fp;
	int n,i,j;
	if((fp=fopen("gz.dat","ab+"))==NULL)
	{
		cout<<"无法打开gz文件"<<endl;
		exit(0);
	}
	cout<<"要添加的职工人数：";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"职工号：";
		cin>>zggz[i].number;
		cout<<"姓名：";
		cin>>zggz[i].name;
		cout<<"岗位工资：";
		cin>>zggz[i].gwgz;
		cout<<"薪级工资：";
		cin>>zggz[i].xjgz;
		cout<<"职务津贴：";
		cin>>zggz[i].zwjt;
		cout<<"绩效工资：";
		cin>>zggz[i].jxgz;
		zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;
		fwrite(&zggz[i],sizeof(struct employee),1,fp);
	}
	cout<<"添加成功"<<endl;
	getchar();
	system("cls");
	fclose(fp);
}
void grsds(int i)
{
	float b,t;      //应纳税所得金额－起征点
	b=zggz[i].yfgz-3500;
	t=zggz[i].yfgz;
	if(b<=0)
	{
		cout<<"   0%  "<<zggz[i].sfgz;
	}
	else
	{
		if(b>0&&b<500)
		{
			t=float (t*0.05);
		    cout<<"       0%  "<<t;   //适用税率0.05,速算扣除数0
		}
		if(b>500&&b<2000)
		{
			t=float (t*0.1-25);       //适用税率0.1,速算扣除数25
		    cout<<"       10%    "<<t;
		}
		if(b>2000&&b<5000)
		{
            t=float (t*0.15-125);     //适用税率0.15,速算扣除数125
		    cout<<"       15%    "<<t;
		}
		if(b>5000&&b<20000)
		{
            t=float (t*0.2-375);      //适用税率0.2,速算扣除数375
		    cout<<"       20%    "<<t;
		}
		if(b>20000&&b<40000)
		{
            t=float (t*0.25-1375);    //适用税率0.25,速算扣除数1375
		    cout<<"       25%    "<<t;
		}
		if(b>40000&&b<60000)
		{
            t=float (t*0.3-3375);     //适用税率0.3,速算扣除数3375
		    cout<<"       30%    "<<t;
		}
		if(b>60000&&b<80000)
		{
            t=float (t*0.35-6375);    //适用税率0.35,速算扣除数6375
		    cout<<"       35%    "<<t;
		}
		if(b>80000&&b<100000)
		{
            t=float (t*0.4-10375);    //适用税率0.4,速算扣除数10375
		    cout<<"       40%    "<<t;
		}
		if(b>100000)
		{
            t=float (t*0.45-15375);   //适用税率0.45,速算扣除数15375
		    cout<<"       45%    "<<t;
		}
	}
}



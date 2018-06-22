#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<iostream>
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
void enter()
{
	int i,m;
	cout<<"请输入需要输入的职工人数(1--100)：";
	cin>>m;
	for(i=0;i<m;i++)
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

		zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;  //应发工资
	}
	cout<<"职工信息录入成功！";
	write(m);
    system("cls");
}

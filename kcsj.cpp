#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<iostream>
using namespace std;
#define NUM 100      //ϵͳ����
void enter();        //����ְ���������ݺ���
int read();          //��ȡְ���������ݺ���
void write(int);     //����ְ���������ݺ���
void find();         //��ѯְ���������ݺ���
void list();         //���ְ���������ݺ���
void modify();       //�޸�ְ���������ݺ���
void del();          //ɾ��ְ���������ݺ���
void add();          //���ְ���������ݺ���
void grsds(int);     //�����������˰����
void menu();         //��ҳ�˵�
struct employee      //ְ�����ݽṹ
{
 char number[11];    //1~10λ����
 char name[11];      //1~10����ĸ��1~5������
 float gwgz;         //��λ����                   
 float xjgz;         //н������                   
 float zwjt;         //ְ�����                  
 float jxgz;         //��Ч����                   
 float yfgz;         //Ӧ������                   
 float sui;          //��������˰
 float sfgz;         //ʵ������                   
}zggz[NUM];
void enter()
{
	int i,m;
	cout<<"��������Ҫ�����ְ������(1--100)��";
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"ְ���ţ�";
		cin>>zggz[i].number;
		cout<<"������";
		cin>>zggz[i].name;
		cout<<"��λ���ʣ�";
		cin>>zggz[i].gwgz;
		cout<<"н�����ʣ�";
		cin>>zggz[i].xjgz;
		cout<<"ְ�������";
		cin>>zggz[i].zwjt;
		cout<<"��Ч���ʣ�";
		cin>>zggz[i].jxgz;

		zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;  //Ӧ������
	}
	cout<<"ְ����Ϣ¼��ɹ���";
	write(m);
    system("cls");
}

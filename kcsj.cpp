#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
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
void menu()
{ 


//printf(" |----------------------------------------|");
printf("   \n    �� ��        ��       �� ��        ");              
//printf("/n |----------------------------------------|");
//printf("      \n    1  ��   ��                         ");  
//printf("/n |----------------------------------------|"); 
printf("      \n    1  ��   ѯ                         ");  
//printf("/n |----------------------------------------|"); 
printf("      \n    2  ��   ��                         "); 
//printf("/n |----------------------------------------|"); 
printf("      \n    3  ��   ��                         "); 
//printf("/n |----------------------------------------|"); 
printf("      \n    4  ɾ   ��                         ");
//printf("/n |----------------------------------------|");
printf("      \n    5  �   ��                         ");
//printf("/n |----------------------------------------|");
printf("      \n    6  ��   ��                         ");              
//printf("/n |----------------------------------------|");
printf("      \n      ����ѡ��һ������           "); 
//printf("/n |----------------------------------------|/n/n/n");
}
/*void enter()
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
}*/
int main()
{
	int n,flag;
	while(1)
	{
		do
		{
			//int m=read();
			menu();	
			//cout<<"              ��ǰ����"<<m<<"λְ��"<<endl;
			cout<<"              ��������ѡ��:[ ]\b\b";
			cin>>n;
			if(n>=1&&n<=8)
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
				cout<<"��������ȷѡ�"<<endl;
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
	    case 5: list(); break; 
        case 6:printf("\n��ӭ�´�ʹ��\n\n");
        default:exit(0);              //�˳�ϵͳ
	}
	}
	return 0;
}
//����ģ��======================���

void write(int m)
{
	int i;
	FILE *fp;
	if ((fp=fopen("gz.dat","wb"))==NULL) 
	{
		cout<<"�޷����ļ�"<<endl;
		exit(0);
	}
   for (i=0;i<m;i++)                                       /*���ڴ���ְ������Ϣ����������ļ���ȥ*/
   if (fwrite(&zggz[i],sizeof(struct employee),1,fp)!=1)   //���û����ȷд��
   cout<<"д��ʧ��"<<endl;
   fclose(fp);

}
//��ȡģ��======================���
int read()
{
	FILE *fp;
	int i=0;
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		cout<<"�޷����ļ�"<<endl;
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
//���ģ��======================���
void list()
{
	int i;
	int m=read();
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"����  ����    ��λ����  н������  ְ�����  ��Ч����  Ӧ������   ˰��   ʵ������"<<endl;
	for(i=0;i<m;i++)
	{
		cout<<zggz[i].number<<"      "
			<<zggz[i].name<<"        "
			<<zggz[i].gwgz<<"        "
			<<zggz[i].xjgz<<"        "
			<<zggz[i].zwjt<<"        "
			<<zggz[i].jxgz<<"        "
			<<zggz[i].yfgz;
		     grsds(i);
		cout<<endl;
	}
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"�����������";
	getchar();
	getchar();
	system("cls");
}
//ɾ��ģ��======================���
void del()
{
	int m=read();
	int i,j,n,t,flag;
	char gonghao[11];
	cout<<"��ǰְ����Ϣ��"<<endl;
	list();
	cout<<endl;
	cout<<"������Ҫɾ����ְ�����ţ�";
	cin>>gonghao;
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(zggz[i].number,gonghao)==0)
		{
			cout<<"--------------------------------------------------------------"<<endl;
			cout<<"Ҫɾ����ְ����Ϣ��"<<endl;
			cout<<"����  ����  ��λ����  н������  ְ�����  ��Ч����  Ӧ������"<<endl;
			cout<<zggz[i].number<<" "<<zggz[i].name<<" "<<zggz[i].gwgz<<" "<<zggz[i].xjgz<<" "<<zggz[i].zwjt<<" "<<zggz[i].jxgz<<" "<<zggz[i].yfgz<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
		    cout<<"ȷ��ɾ���밴1������ɾ���밴0"<<endl;
		    cin>>n;
		    if(n==1)                               //�Ӹü�¼��ʼÿ����¼��ǰ��һ����¼
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
		cout<<"ɾ���ɹ�"<<endl;;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	cout<<"��ǰ����ְ����Ϣ"<<endl;
	write(m);
	list();
	cout<<"����ɾ���밴1������ɾ���밴2"<<endl;
	cin>>t;
	switch(t)
	{
	    case 1:del(); break;
		case 2:break;
		default:break;
	}
	system("cls");
}
//��ѯģ��======================���
void find()
{
	int t,i,flag;
	int m=read();
	char gonghao[11];
	cout<<"��������Ҫ��ѯ��ְ������:"<<endl;
	cin>>gonghao;
	 for(flag=1,i=0;flag&&i<m;i++)
	 {
		 if(strcmp(zggz[i].number,gonghao)==0)
		{
			cout<<"--------------------------------------------------------------"<<endl;
			cout<<"��Ҫ��ѯ���ǣ�"<<endl;
			cout<<"����  ����  ��λ����  н������  ְ�����  ��Ч����  Ӧ������"<<endl;
			cout<<zggz[i].number<<"       "
			    <<zggz[i].name<<"         "
			    <<zggz[i].gwgz<<"         "
			    <<zggz[i].xjgz<<"         "
			    <<zggz[i].zwjt<<"         "
			    <<zggz[i].jxgz<<"         "
			    <<zggz[i].yfgz<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
	}
	if(i==m)
	{
		cout<<"���޴���"<<endl;
	}
	cout<<"������ѯ�밴1�������밴2"<<endl;
	cin>>t;
	switch(t)
	{
	    case 1:find(); break;
		case 2: system("cls"); break;
		default:break;
	}
}
//�޸�ģ��======================���
void modify()
{
	 char num[11];    //1~10λ����
     char nam[11];      //1~10����ĸ��1~5������
     float Gwgz;         //��λ����                   
     float Xjgz;         //н������                   
     float Zwjt;         //ְ�����                  
     float Jxgz;         //��Ч����                                    
	 int b,c,i,n,t,flag;
	 int m=read();
	 char gonghao[11];
	 cout<<"��ǰְ����Ϣ��"<<endl;
	 list();
	 cout<<"������Ҫ�޸ĵ�ְ�����ţ�";
	 cin>>gonghao;
	 for(flag=1,i=0;flag&&i<m;i++)
	 {
		 if(strcmp(zggz[i].number,gonghao)==0)
		{
			cout<<"--------------------------------------------------------------"<<endl;
			cout<<"Ҫ�޸ĵ�ְ����Ϣ��"<<endl;
			cout<<"����  ����  ��λ����  н������  ְ�����  ��Ч����  Ӧ������"<<endl;
			cout<<zggz[i].number<<"      "
			    <<zggz[i].name<<"        "
			    <<zggz[i].gwgz<<"        "
			    <<zggz[i].xjgz<<"        "
			    <<zggz[i].zwjt<<"        "
			    <<zggz[i].jxgz<<"        "
			    <<zggz[i].yfgz<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
	 	cout<<"ȷ��Ҫ�޸�����ְ���밴1�������޸��밴0"<<endl;
		cin>>n;
		if(n==1)
		{
			cout<<"������Ҫ�޸ĵ�ѡ�1.���� 2.���� 3.��λ����  4.н������ 5.ְ�����  6.��Ч���� "<<endl;
			cin>>c;
			if(c>6||c<1)
			{
				cout<<"ѡ���������������"<<endl;
			}	
		}
		flag=0;
		}
	 }
	 if(flag==1)
	 {
		 cout<<"���޴���"<<endl;
	 }
		 do
		 {
			 switch(c)                   //���ҵ���i��ְ��ʱ,for����i�Լ���1,���������Ӧ�ðѸĺ����Ϣ��ֵ����i-1����
			 {
			    case 1:
					   cout<<"���Ÿ�Ϊ��";
					   cin>>num;
					   strcpy(zggz[i-1].number,num);
					   break;
				case 2:
					   cout<<"������Ϊ��";
					   cin>>nam;
					   strcpy(zggz[i-1].name,nam);
					   break;
				case 3:
					   cout<<"��λ���ʸ�Ϊ��";
					   cin>>Gwgz;
					   zggz[i-1].gwgz=Gwgz;
					   break;
			    case 4:
					   cout<<"н�����ʸ�Ϊ��";
					   cin>>Xjgz;
					   zggz[i-1].xjgz=Xjgz;
					   break;
				case 5:
					   cout<<"ְ�������Ϊ��";
					   cin>>Zwjt;
					   zggz[i-1].zwjt=Zwjt;
					   break;
				case 6:
					   cout<<"��Ч���ʸ�Ϊ��";
					   cin>>Jxgz;
					   zggz[i-1].jxgz=Jxgz;
					   break;
			 }
			 cout<<endl;
			 cout<<"ȷ���밴1�������޸��밴2"<<endl;
			 cin>>b;
		 }
		 while(b==2);
		 {
			 cout<<"�޸ĺ������ְ����ϢΪ��"<<endl;
			 write(m);
			 list();
		 }
		 cout<<"�����޸��밴1,�����밴�����";
		 cin>>t;
		 switch(t)
			{
			     case 1:modify(); break;
				 default:break;
			 }
		 system("cls");
}
//���ģ��======================���
void add()
{
	FILE *fp;
	int n,i,j;
	if((fp=fopen("gz.dat","ab+"))==NULL)
	{
		cout<<"�޷���gz�ļ�"<<endl;
		exit(0);
	}
	cout<<"Ҫ��ӵ�ְ��������";
	cin>>n;
	for(i=0;i<n;i++)
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
		zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;
		fwrite(&zggz[i],sizeof(struct employee),1,fp);
	}
	cout<<"��ӳɹ�"<<endl;
	getchar();
	system("cls");
	fclose(fp);
}
void grsds(int i)
{
	float b,t;      //Ӧ��˰���ý�������
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
			t=float (t*0.5);
		    cout<<"       0%  "<<t;
		}
		if(b>500&&b<2000)
		{
			t=float (t*0.1-25);
		    cout<<"       10%    "<<t;
		}
		if(b>2000&&b<5000)
		{
            t=float (t*0.15-125);
		    cout<<"       15%    "<<t;
		}
		if(b>5000&&b<20000)
		{
            t=float (t*0.2-375);
		    cout<<"       20%    "<<t;
		}
		if(b>20000&&b<40000)
		{
            t=float (t*0.25-1375);
		    cout<<"       25%    "<<t;
		}
		if(b>40000&&b<60000)
		{
            t=float (t*0.3-3375);
		    cout<<"       30%    "<<t;
		}
		if(b>60000&&b<80000)
		{
            t=float (t*0.35-6375);
		    cout<<"       35%    "<<t;
		}
		if(b>80000&&b<100000)
		{
            t=float (t*0.4-10375);
		    cout<<"       40%    "<<t;
		}
		if(b>100000)
		{
            t=float (t*0.45-15375);
		    cout<<"       45%    "<<t;
		}
	}
}
/*void grsds(int i)      
{
	int i;
	for(i=0;i<count;i++)
	{
		if
			(zggz[i].Deserved<500)																															
			zggz[i].Individual_income_tax=zggz[i].Deserved*0.05;
		else if
			(zggz[i].Deserved<2000)					
			zggz[i].Individual_income_tax=(zggz[i].Deserved-500)*0.1+500*0.05;
		else if
			(zggz[i].Deserved<5000)					
			zggz[i].Individual_income_tax=(zggz[i].Deserved-2000)*0.15+1500*0.1+500*0.05;	
		else if
			(zggz[i].Deserved<20000)					
			zggz[i].Individual_income_tax=(zggz[i].Deserved-5000)*0.2+3000*0.15+1500*0.1+500*0.05;															     			
		else if
			(zggz[i].Deserved<40000)			
			zggz[i].Individual_income_tax=(zggz[i].Deserved-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;															    
		else if
			(zggz[i].Deserved<60000)	
			zggz[i].Individual_income_tax=(zggz[i].Deserved-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;											     
		else if
			(zggz[i].Deserved<80000)	
			zggz[i].Individual_income_tax=(zggz[i].Deserved-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;								     					
		else if
			(zggz[i].Deserved<100000)			
			zggz[i].Individual_income_tax=(zggz[i].Deserved-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;				
		else							
			zggz[i].Individual_income_tax=(zggz[i].Deserved-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		
	}
}*/



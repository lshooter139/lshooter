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
printf("   \n###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###");              
printf("\n\n��ѡ��<1-7>:");
printf("\n========================================================================");  
printf("\n|                          1.��ѯְ�����ʼ�¼                          |");  
printf("\n|                          2.�޸�ְ�����ʼ�¼                          |"); 
printf("\n|                          3.���ְ�����ʼ�¼                          |"); 
printf("\n|                          4.ɾ��ְ�����ʼ�¼                          |");
printf("\n|                          5.�������ݵ��ļ�                            |");
printf("\n|                          6.���ְ����¼                              |");
printf("\n|                          7.�˳�ϵͳ                                  |");              
printf("\n========================================================================");
printf("      \n      ���ѡ����:           "); 
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
				printf("��������ȷѡ�");
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
        case 7:printf("\n��ӭ�´�ʹ��\n\n");
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
		printf("�޷����ļ�");
		exit(0);
	}
   for (i=0;i<m;i++)                                       /*���ڴ���ְ������Ϣ����������ļ���ȥ*/
   if (fwrite(&zggz[i],sizeof(struct employee),1,fp)!=1)   //���û����ȷд��
   printf("д��ʧ��");
   fclose(fp);

}
//��ȡģ��======================���
int read()
{
	FILE *fp;
	int i=0;
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		printf("�޷����ļ�");
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
	printf("--------------------------------------------------------------------------------");
	printf("����  ����    ��λ����  н������  ְ�����  ��Ч����  Ӧ������   ˰��   ʵ������");
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
	printf("�����������");
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
    printf("��ǰְ����Ϣ��");
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
			t=float (t*0.05);
		    cout<<"       0%  "<<t;   //����˰��0.05,����۳���0
		}
		if(b>500&&b<2000)
		{
			t=float (t*0.1-25);       //����˰��0.1,����۳���25
		    cout<<"       10%    "<<t;
		}
		if(b>2000&&b<5000)
		{
            t=float (t*0.15-125);     //����˰��0.15,����۳���125
		    cout<<"       15%    "<<t;
		}
		if(b>5000&&b<20000)
		{
            t=float (t*0.2-375);      //����˰��0.2,����۳���375
		    cout<<"       20%    "<<t;
		}
		if(b>20000&&b<40000)
		{
            t=float (t*0.25-1375);    //����˰��0.25,����۳���1375
		    cout<<"       25%    "<<t;
		}
		if(b>40000&&b<60000)
		{
            t=float (t*0.3-3375);     //����˰��0.3,����۳���3375
		    cout<<"       30%    "<<t;
		}
		if(b>60000&&b<80000)
		{
            t=float (t*0.35-6375);    //����˰��0.35,����۳���6375
		    cout<<"       35%    "<<t;
		}
		if(b>80000&&b<100000)
		{
            t=float (t*0.4-10375);    //����˰��0.4,����۳���10375
		    cout<<"       40%    "<<t;
		}
		if(b>100000)
		{
            t=float (t*0.45-15375);   //����˰��0.45,����۳���15375
		    cout<<"       45%    "<<t;
		}
	}
}



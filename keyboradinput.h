#ifndef KEYBORADINPUT_CPP
#define KEYBORADINPUT_CPP
#include"zzy.h"
void keyboradinput()
{

    cout<<"������������ֵ��"<<endl;
	int flag;
	cin>>flag;
	while(flag)
	{
		vector<int> path;//�洢·��
		int i,j,row1,k=0;
		int count=0;
		int contact[NUM][NUM];//�����ά����
		int nears[NUM];//�洢���n����ׯ���ڴ��Ӹ���  

		for(i =0;i<NUM;i++)//��ʼ��
		{
			for(j=0;j<NUM;j++)
			{
				contact[i][j]=0;
			}
		}
	
		cout<<"\n***************************��ӭ��������β�ʿ����׷��ϵͳ*******************************"<<endl;
		cout<<"\n\n�����ͼ�Ĵ��Ӹ�����"<<endl;
		Matrix A;
	  cin>>row1;
		A.init(row1);//��ʼ�����Ӹ���

		cout<<"\n������������:"<<endl;//��������
		int days;
		cin>>days;

		cout<<"\n��������ص㣺 "<<endl;//�����ص�
		int prison;
		cin>>prison;
		path.push_back(prison);
	
		cout<<"\n������ӵľ����ϵ:"<<endl;//���ӹ�ϵ�ľ���ͼ
		A.input();
	
		cout<<"\n����Ҫ����Ĵ��Ӹ���:"<<endl;//Ҫ����Ĵ��Ӹ���
		int numbers;
		cin>>numbers;

		for(i=0;i<A.output();i++)//��Matrix����contact
		{
			for(j=0;j<A.output();j++)
			{
				contact[i][j]=A.arr[k];
				k++;	
			}
		}
	
		k=0;//��ʼ��
		for(i=0;i<A.output();i++)
		{//����nears[]
			count=0;
			for(j=0;j<A.output();j++)
			{
				if(contact[i][j]==1)
				{
					count++;
					nears[k]=count;	
				}
			}
			k++;
		}

		cout<<"\n������Ҫ����Ĵ��ӵĺ���:"<<endl;
		while(numbers)
		{
		
			int end;
			cin>>end;
			/*
			����1���ݹ飺
			*/
			cout<<"P ("<<end<<" ):"<<setprecision(8)<<dg_chance(end,days,prison,contact,nears,A)<<endl;

			/*
			����2��������
			*/
			//cout<<"P("<<end<<" ):"<<setprecision(8)<<chance( nears,days,end,contact,A,path)<<endl;

			
			numbers--;
		}

		char select;
		cout<<"\n�鿴������ͼ����y(���������):"<<endl;
		cin>>select;
		if(select=='y')
		{
			draw(contact,A);
		}
		flag--;
	}//������
}
#endif
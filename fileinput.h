#ifndef INPUTFILE_CPP
#define INPUTFILE_CPP
#include"zzy.h"

void fileInput()
{
	int flag,days;
	int row1, prison,numbers;
	int contact[NUM][NUM];
	int end;
	char select;
	Matrix A;
	

	ifstream infile(fileName,ios::out);

	if(!infile)
	{
		cerr<<"open error!"<<endl;
	}
	
	
	cout<<"������������ֵ��"<<endl;
	infile>>flag;
	cout<<flag;

	while(flag)
	{
		
		vector<int> path;//�洢·��
		int i,j,k=0;
		int count=0;
		//int contact[NUM][NUM];//�����ά����
		int nears[NUM];//�洢���n����ׯ���ڴ��Ӹ���  

		for(i =0;i<NUM;i++)//��ʼ��
		{
			for(j=0;j<NUM;j++)
			{
				contact[i][j]=0;
			}
		}
		int a[20];
		for(int i = 0;i<3;i++)
		{
			infile>>a[i];
		}
		row1 = a[0];
		days = a[1];
		prison = a[2];
		cout<<"\n***************************��ӭ��������β�ʿ����׷��ϵͳ*******************************"<<endl;
		cout<<"\n\n�����ͼ�Ĵ��Ӹ�����"<<endl;
		
	   
		cout<<row1;
		A.init(row1);//��ʼ�����Ӹ���

		cout<<"\n������������:"<<endl;//��������
		
		
		cout<<days;

		cout<<"\n��������ص㣺 "<<endl;//�����ص�
		
		
		cout<<prison;
		path.push_back(prison);
	
		cout<<"\n������ӵľ����ϵ:"<<endl;//���ӹ�ϵ�ľ���ͼ
		//A.input();
		for(int i=0;i<row1;i++)
		{
			for(int j =0;j<row1;j++)
			{
				infile>>contact[i][j];	
		
			}
	
		}

		for(int i=0;i<row1;i++)
		{
			for(int j =0;j<row1;j++)
			{
				cout<<contact[i][j]<<" ";	
		
			}
			cout<<endl;
	
		}
		
		infile>>numbers;
		for(int i =0;i<numbers;i++)
		{
			infile>>a[i];
	
		}
		
	
		cout<<"\n����Ҫ����Ĵ��Ӹ���:"<<endl;//Ҫ����Ĵ��Ӹ���
		cout<<numbers;

		
	
		k=0;//��ʼ��
		for(i=0;i<row1;i++)
		{//����nears[]
			count=0;
			for(j=0;j<row1;j++)
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
		for(int i=0;i<numbers;i++)
		{
			cout<<a[i]<<" ";
				
		}
		cout<<endl;
		while(numbers)
		{
		
			
			for(int i=0;i<numbers;i++)
			{
				end=a[i];
				
			}
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

		
		cout<<"\n�鿴������ͼ����y(���������):"<<endl;
		infile>>select;
		cout<<select;
		getchar();
		if(select=='y')
		{
			draw(contact,A);
		}
		flag--;
		
	}
}//������	

#endif

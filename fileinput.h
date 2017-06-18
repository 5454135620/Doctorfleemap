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
	
	
	cout<<"多样例里输入值："<<endl;
	infile>>flag;
	cout<<flag;

	while(flag)
	{
		
		vector<int> path;//存储路径
		int i,j,k=0;
		int count=0;
		//int contact[NUM][NUM];//矩阵二维数组
		int nears[NUM];//存储与第n个村庄相邻村子个数  

		for(i =0;i<NUM;i++)//初始化
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
		cout<<"\n***************************欢迎来到汉尼拔博士逃亡追查系统*******************************"<<endl;
		cout<<"\n\n输入地图的村子个数："<<endl;
		
	   
		cout<<row1;
		A.init(row1);//初始化村子个数

		cout<<"\n输入逃亡天数:"<<endl;//逃亡天数
		
		
		cout<<days;

		cout<<"\n输入监狱地点： "<<endl;//监狱地点
		
		
		cout<<prison;
		path.push_back(prison);
	
		cout<<"\n输入村子的矩阵关系:"<<endl;//村子关系的矩阵图
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
		
	
		cout<<"\n输入要计算的村子个数:"<<endl;//要计算的村子个数
		cout<<numbers;

		
	
		k=0;//初始化
		for(i=0;i<row1;i++)
		{//计算nears[]
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

		cout<<"\n输入你要计算的村子的号码:"<<endl;
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
			方法1：递归：
			*/
			cout<<"P ("<<end<<" ):"<<setprecision(8)<<dg_chance(end,days,prison,contact,nears,A)<<endl;

			/*
			方法2：蛮力法
			*/
			//cout<<"P("<<end<<" ):"<<setprecision(8)<<chance( nears,days,end,contact,A,path)<<endl;

			
			numbers--;
		}

		
		cout<<"\n查看逃亡地图输入y(任意键忽略):"<<endl;
		infile>>select;
		cout<<select;
		getchar();
		if(select=='y')
		{
			draw(contact,A);
		}
		flag--;
		
	}
}//多样例	

#endif

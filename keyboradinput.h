#ifndef KEYBORADINPUT_CPP
#define KEYBORADINPUT_CPP
#include"zzy.h"
void keyboradinput()
{

    cout<<"多样例里输入值："<<endl;
	int flag;
	cin>>flag;
	while(flag)
	{
		vector<int> path;//存储路径
		int i,j,row1,k=0;
		int count=0;
		int contact[NUM][NUM];//矩阵二维数组
		int nears[NUM];//存储与第n个村庄相邻村子个数  

		for(i =0;i<NUM;i++)//初始化
		{
			for(j=0;j<NUM;j++)
			{
				contact[i][j]=0;
			}
		}
	
		cout<<"\n***************************欢迎来到汉尼拔博士逃亡追查系统*******************************"<<endl;
		cout<<"\n\n输入地图的村子个数："<<endl;
		Matrix A;
	  cin>>row1;
		A.init(row1);//初始化村子个数

		cout<<"\n输入逃亡天数:"<<endl;//逃亡天数
		int days;
		cin>>days;

		cout<<"\n输入监狱地点： "<<endl;//监狱地点
		int prison;
		cin>>prison;
		path.push_back(prison);
	
		cout<<"\n输入村子的矩阵关系:"<<endl;//村子关系的矩阵图
		A.input();
	
		cout<<"\n输入要计算的村子个数:"<<endl;//要计算的村子个数
		int numbers;
		cin>>numbers;

		for(i=0;i<A.output();i++)//将Matrix导入contact
		{
			for(j=0;j<A.output();j++)
			{
				contact[i][j]=A.arr[k];
				k++;	
			}
		}
	
		k=0;//初始化
		for(i=0;i<A.output();i++)
		{//计算nears[]
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

		cout<<"\n输入你要计算的村子的号码:"<<endl;
		while(numbers)
		{
		
			int end;
			cin>>end;
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

		char select;
		cout<<"\n查看逃亡地图输入y(任意键忽略):"<<endl;
		cin>>select;
		if(select=='y')
		{
			draw(contact,A);
		}
		flag--;
	}//多样例
}
#endif
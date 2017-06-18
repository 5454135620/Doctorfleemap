#ifndef MATRIX_CPP
#define MATRIX_CPP

#include"zzy.h"

class  Matrix
{
public:
	void init(int a);//矩阵初始化
	void input();//输入矩阵
	void display();//矩阵打印输出
	int output();//输出长宽
	int *arr;//指针指向建立数组
	
private:
	int row;//行
	int col;//列
};


//初始化 row col
void Matrix::init(int a)
{
	
	//cin>>row;
	row=a;
	col=row;//村子矩阵图始终为方阵
	arr=new int [col*row];//开辟动态空间
	for(int i=0;i<row*col;i++)
	{
		arr[i]=0;
	
	}
	
}
//键盘输入
void Matrix::input()
{
	for(int i=0;i<row*col;i++)
	{
		cin>>arr[i];
     }
}

//输出矩阵长度
int Matrix::output()
{
	return row;
}
//显示
void Matrix::display()
{
	for(int i=0;i<row*col;i++)  
	{
		cout<<arr[i]<<" ";
		if((i+1)%row==0)
		{
			cout<<"\n";
		}

	}
   cout<<endl;
}



#endif
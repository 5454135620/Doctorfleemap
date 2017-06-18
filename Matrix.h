#ifndef MATRIX_CPP
#define MATRIX_CPP

#include"zzy.h"

class  Matrix
{
public:
	void init(int a);//�����ʼ��
	void input();//�������
	void display();//�����ӡ���
	int output();//�������
	int *arr;//ָ��ָ��������
	
private:
	int row;//��
	int col;//��
};


//��ʼ�� row col
void Matrix::init(int a)
{
	
	//cin>>row;
	row=a;
	col=row;//���Ӿ���ͼʼ��Ϊ����
	arr=new int [col*row];//���ٶ�̬�ռ�
	for(int i=0;i<row*col;i++)
	{
		arr[i]=0;
	
	}
	
}
//��������
void Matrix::input()
{
	for(int i=0;i<row*col;i++)
	{
		cin>>arr[i];
     }
}

//������󳤶�
int Matrix::output()
{
	return row;
}
//��ʾ
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
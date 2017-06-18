#ifndef CR_DIGUI_H
#define CR_DIGUI_H

#include"zzy.h"

/*
�ݹ�˼·��
���д�ׯ�ĸ��ʼ��㶼�ǻ������νṹ
�����ӷ�������ĳ�Ŵ�ׯ�ĸ���������˼·��
�����򣺴Ӽ�����ʼ ����days����� ������������Ŀ�ĵ�end��·�� ������
�ڷ��򣺴�Ҫ�����end�ص� ������û����ͨstart��·�� ������  ���Ӹ�Ч
*/

double dg_chance(int end,int days,int prison,int contact[][NUM],int nears[],Matrix A)//�ӷ���ends�� �Ѿ�����days��
{
	if(days == 0 )
	{//�����㲻�Ǽ������ڵ� ������Ҫ�� P=0
		if(end == prison)
		{
			return(1.0);
		}
		else
		{
			return(0.0);
		}
	}
	double result=0.0;
	
	for(int i = 0;i<A.output();++i)
	{
		if(contact[end][i])
		{
			result =result+ dg_chance(i,days-1,prison,contact,nears,A)/nears[i];
		}

	}

	return result;
	
	
}
#endif
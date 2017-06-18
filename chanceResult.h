#ifndef CHANCERESULT_CPP
#define CHANCERESULT_CPP

#include"zzy.h"

double chance(int nears[],int days,int end,int contact[][NUM],Matrix A,vector<int>&path)
{
	
	double result;

	if(path.size()==days+1)//·��������Ԫ�ش洢���� ����n�� ����Ϊn+1
	{
		if(path.back()!=end)//�����յ�����
			return(0.0); 
	
		result=1.0;	
		
		for(unsigned int  i = 0;i+1<path.size();i++)
			result=result/nears[path[i]] ;
			
		return result;
	}

		 result = 0;
		
		for(int i=0;i<A.output();++i)
		{
			
			if(contact[path.back()][i])//���һ��·��Ԫ���������ڴ�ׯ
			{
				
				path.push_back(i);
				
				result=result+chance( nears,days,end,contact,A,path);

				path.pop_back();//ѹ��path��Ԫ��ȥ�� 
			}
			
		}
		

			
		return result;
	
}


#endif
#ifndef CHANCERESULT_CPP
#define CHANCERESULT_CPP

#include"zzy.h"

double chance(int nears[],int days,int end,int contact[][NUM],Matrix A,vector<int>&path)
{
	
	double result;

	if(path.size()==days+1)//路径数组首元素存储监狱 经历n天 长度为n+1
	{
		if(path.back()!=end)//满足终点设置
			return(0.0); 
	
		result=1.0;	
		
		for(unsigned int  i = 0;i+1<path.size();i++)
			result=result/nears[path[i]] ;
			
		return result;
	}

		 result = 0;
		
		for(int i=0;i<A.output();++i)
		{
			
			if(contact[path.back()][i])//最后一个路径元素有无相邻村庄
			{
				
				path.push_back(i);
				
				result=result+chance( nears,days,end,contact,A,path);

				path.pop_back();//压入path的元素去除 
			}
			
		}
		

			
		return result;
	
}


#endif
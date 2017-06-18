#ifndef CR_DIGUI_H
#define CR_DIGUI_H

#include"zzy.h"

/*
递归思路：
所有村庄的概率计算都是基于树形结构
计算逃犯出现在某号村庄的概率有两种思路：
①正向：从监狱开始 经过days天查找 遍历所有满足目的地end的路径 计算结果
②反向：从要计算的end地点 遍历有没有联通start的路径 计算结果  更加高效
*/

double dg_chance(int end,int days,int prison,int contact[][NUM],int nears[],Matrix A)//逃犯在ends村 已经逃亡days天
{
	if(days == 0 )
	{//如果起点不是监狱所在地 不满足要求 P=0
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
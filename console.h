#ifndef CONSOLE_CPP
#define CONSOLE_CPP

#include"zzy.h"


//�洢�������Բ������Ľṹ��
struct line
{
	int lx;
	int ly;
};
struct line node[100];

void draw(int contact[][100],Matrix A)
{
	
	/*���������*/
	srand ((unsigned)time(NULL));


	

	char str[100]="0123456789";
	initgraph(800, 460);
	settextcolor(RED);
	settextstyle(40,0,_T("����"));
	TCHAR s[] =_T( "ɱ�˿�ħ����β�ʿ������ͼ");
	outtextxy(120,0,s);


	setbkcolor(BLUE);
	
	int ch;
	ch = A.output();
	int x = 100;
	int y = 100;
	int r =35;
	int i,count=0;


	for( i = 0;i<ch;i++)
	{   
		node[i].lx=x;
		node[i].ly=y;
		settextstyle(30,0,_T("����"));
		outtextxy(node[i].lx,node[i].ly,str[i]);//��ǰλ������ַ�
		
		circle(x,y,r);//��Բ
		setbkcolor(BLUE);
		/*
		//��ֹ��������
		if(i==ch/2)
		{   x= 0;
			y=y+200;
		}
		*/
		//x=x+100;

		x=0;
		y=0;
		x=random(100,700);
		y=random(100,400);
		
	
	}


	   for(int i = 0;i<ch;i++)
	   {
			for(int j = 0;j<5;j++)
			{
				if(contact[i][j]==1)
				{
					 setlinecolor(YELLOW);
					 line (node[i].lx,node[i].ly,node[j].lx,node[j].ly);//����
					 contact[j][i]=0;
					 count++;

				}
			
			}
	   }
	
	getch();
	closegraph();
}



#endif
#ifndef REAR_END_H
#define REAR_END_H 
#include "Rear_End.h"
#endif

class People
{
//protected:
//TODO：改为protected++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public://调试时使用
	int presflr;
	int objflr;
	int direction;
	int weight;

public:
	People();
};

list <People> ListUp, ListDown;

People::People()
{
	//随机生成所在层与目标层
	presflr = rand() % TOP;
	do{
		objflr = rand() % TOP;
	}while(presflr == objflr);

	//生成方向
	direction = presflr < objflr ? UP : DOWN;

	//随机生成体重
	weight = 50 + rand() % 50;
	//TODO：改为正态分布+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//cout<<presflr<<endl<<objflr<<endl<<direction<<endl<<weight<<endl;//测试用代码
}

void Refresh()
{
	//srand((int)time(0));	//备用方法
	//int n = rand() % TOP;	//备用方法
	int n = 1;
	//TODO：改为随机、大量++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int i = 0;
	People *p;
	srand((int)time(0));
	while(i++ < n){
		p = new People;
		if(p->direction == UP){
			ListUp.push_front(*p);
		}else{
			ListDown.push_front(*p);
		}
		//cout<<p->weight<<"\t"<<p->objflr<<endl;//测试用代码
	}
}


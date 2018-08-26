#include "Rear_End.h"

#ifndef PEOPLE_H
#define PEOPLE_H 

class People
{
//protected:
//TODO：改为protected++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
protected://调试时使用
	int presflr;			//所在层
	int objflr;				//目标层
	int direction;			//方向
	int weight;				//体重

public:
	People();				//构造
	void Check();	//轮询待乘乘客
	int Direction();
};

People::People()
{
	//随机生成所在层与目标层
	presflr = rand() % L + 1;
	do{
		objflr = rand() % L +1;
	}while(presflr == objflr);

	//生成方向
	direction = presflr < objflr ? UP : DOWN;

	//随机生成体重
	weight = 50 + rand() % 50;
	//TODO：改为正态分布+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//cout<<presflr<<endl<<objflr<<endl<<direction<<endl<<weight<<endl;//测试用代码
}

int People::Direction()
{
	return direction;
}

void People::Check()
{

}

#endif
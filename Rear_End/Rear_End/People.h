#pragma once
#ifndef PEOPLE_H
#define PEOPLE_H 

#include "Elevator.h"

class People
{
//protected:
//TODO：改为protected++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
protected://调试时使用
	int presflr;			//所在层
	int objflr;				//目标层
	int direction;			//方向
	int weight;				//体重
	int condition;			//状态

public:
	People();				//构造
	int Direction(){return direction;}
	void Check(Elevator *p);//轮询电梯
};

list <People> *Up[N] = {new list <People>};
list <People> *Down[N] = {new list <People>};
list <People> NotArranged = new list <People>;

People::People()
{
	Elevator e1(1);
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

	condition = 0;
}

void People::Check(Elevator *p)
{
	int i, j = -1;

	for(i = 0; i < N; i++){
		if(!p[i].IsFull(weight)){
			if(p[i].Direction() == direction){
				if((objflr - p[i].Objflr()) * direction > 0){
					if(j < 0 || (p[i].Objflr() - p[j].Objflr()) * direction > 0){
						j = i;
					}
				}
			}
		}
	}

	if(j >= 0){
		condition = 1;
		if (direction == UP){
			Up[j]->push_back(this);
		}else{
			Down[j]->push_back(this);
		}
	}else{
		NotArranged->push_back(this);
	}
}



#endif
#pragma once
#ifndef PEOPLE_H
#define PEOPLE_H 

#include "Elevator.h"
#include "List.h"

class People
{
protected://调试时使用
	int presflr;			//所在层
	int objflr;				//目标层
	int direction;			//方向
	int weight;				//体重
	int condition;			//状态

public:
	People();				//构造
	void Check(Elevator <People> *p);//轮询电梯
	void Delete();//从链表中移除
	int Direction(){return direction;}
	int Objflr(){return objflr;}
	int Presflr(){return presflr;}
	int Weight(){return weight;}
	void Arrange(){condition = WAITING;}
	People *pNext;
	People *pFront;
};

List <People> *Up[N] = {new List <People>};
List <People> *Down[N] = {new List <People>};
List <People> *NotArranged = new List <People>;

List <People> ListUp, ListDown;

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

	condition = NOTARRANGED;
	pFront = NULL;
	pNext = NULL;
}

void People::Check(Elevator <People> *p)
{
	int i, j = -1;//j用于存储准备调用的电梯编号

	for(i = 0; i < N; i++){
		if(!p[i].IsFull(weight)){
			if(p[i].Direction() == direction){
				if((presflr - p[i].Presflr()) * direction > 0){
					if(j < 0 || (p[i].Presflr() - p[j].Presflr()) * direction > 0){
						j = i;
					}
				}
			}else if (!p[i].Direction()){
				if ((presflr - p[i].Presflr()) * direction > 0){
					if(j < 0 || (p[i].Presflr() - p[j].Presflr()) * direction > 0){
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

void People::Delete()
{
	if (direction == UP)
	{
		ListUp.dele(this);
	}else{
		ListDown.dele(this);
	}
}

#endif
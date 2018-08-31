#pragma once
#ifndef PEOPLE_H
#define PEOPLE_H 

#include "Elevator.h"
#include "List.h"
#include <cmath>

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
	void Check(Elevator <People> *e[N]);//轮询电梯
	void Delete();//从链表中移除
	int Direction(){return direction;}
	int Objflr(){return objflr;}
	int Presflr(){return presflr;}
	int Weight(){return weight;}
	void Arrange(){condition = WAITING;}
	People *pNext;//供ListUp/Down使用
	People *pFront;//供ListUp/Down使用
	People *next;//供Board/Drop使用
	People *prev;//供Board/Drop使用
};

List <People> *Board[N] = {new List <People>, new List <People>, new List <People>};
List <People> *Drop[N] = {new List <People>, new List <People>, new List <People>};

List <People> ListUp, ListDown, NotArranged;

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
	pFront = pNext = prev = next = NULL;
}
/*
List<CString> list[10];
*/
void People::Check(Elevator <People> *e[N])
{
	int i, j = -1;//j用于存储准备调用的电梯编号
	for(i = 0; i < N; i++){
		if(!e[i]->IsFull(weight)){
			if(e[i]->Direction() == direction){
				if((presflr - e[i]->Presflr()) * direction > 0){
					if(j < 0 || (e[i]->Presflr() - e[j]->Presflr()) * direction > 0){
						j = i;
					}
				}
			}else if (!e[i]->Direction()){
				if(j < 0 || abs(e[i]->Presflr() - presflr) < abs(e[j]->Presflr() - presflr)){
					j = i;
				}
			}
		}
	}

	if(j >= 0){
		condition = 1;
		Board[j]->push_back(this, MODEBD);
	}else{
		NotArranged.push_back(this, MODEBD);
	}
}

void Refresh(Elevator <People> *e[N])
{
	//srand((int)time(0));	//备用方法
	//int n = rand() % TOP;	//备用方法
	int n = 9;
	//TODO：改为随机、大量++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int i = 0;
	People *p;
	srand((int)time(0));
	while(i++ < n){
		p = new People;
		if(p->Direction() == UP){
			ListUp.push_back(p, MODELIST);
		}else{
			ListDown.push_back(p, MODELIST);
		}
		p->Check(e);
	}
}

void Ini(Elevator <People> *e[N])//初始化电梯
{
	int i;
	for(i = 0; i < N; i++){
		if(i < N / 3){
			e[i] = new Elevator <People> (i, 1);
		}else if(i >= 2 * N / 3){
			e[i] = new Elevator <People> (i, L);
		}else{
			e[i] = new Elevator <People> (i, L / 2);
		}
	}
}

void Show(int *n)//显示各层等待人数
{
	People *i;
	for(i = ListUp.pHead; i; i = i->pNext){
		n[i->Presflr()]++;
	}
	for(i = ListDown.pHead; i; i = i->pNext){
		n[i->Presflr()]++;
	}
}
#endif
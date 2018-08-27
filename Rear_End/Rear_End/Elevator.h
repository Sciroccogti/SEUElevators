#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Rear_End.h"
#include "List.h"
class Elevator
{
protected:
	int num;		//编号
	int total;		//总重
	int presflr;	//所在层
	int direction;	//方向
	int condition;	//运行状态
	int objflr;		//目标层
	double time;	//总运行时间
	int waiting;	//状态保持时间

public:
	Elevator(int num, int presflr1);	//构造
	void Move(int goal);	//电梯移动
	void Board(int n);		//电梯上客
	void Drop(int n);		//电梯下客
	void Change();			//电梯改变状态
	void Continue();		//电梯续航
	Elevator& operator [](const int n){return this[n];}
	bool IsFull(int weight1){return MAX - total < weight1;}
	int Direction(){return direction;}
	int Objflr(){return objflr;}
};

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
	void Check(Elevator *p);//轮询电梯
	int Direction(){return direction;}
	int Objflr(){return objflr;}
	int Presflr(){return presflr;}
	void Arrange(){condition = WAITING;}
	People *pNext;
	People *pFront;
};

List <People> *Up[N] = {new List <People>};
List <People> *Down[N] = {new List <People>};
List <People> *NotArranged = new List <People>;

Elevator::Elevator(int num1, int presflr1)//构造
{
	num = num1;
	total = 0;
	presflr = presflr1;
	direction = STOP;
	condition = STOP;
	objflr = 0;
	time = 0;
	waiting = 0;
}

void Elevator::Move(int goal)//电梯移动
{
	objflr = goal;
	direction = objflr > presflr ? UP : DOWN;
	waiting += S;
}

void Elevator::Board(int weight1)//电梯上客
{
	if(!IsFull(weight1)){
		total += weight1;
		condition = ON;
		waiting += T;
	}
}

void Elevator::Drop(int weight1)//电梯下客
{
	total -= weight1;
	condition = OFF;
	waiting += T;
}

void Change()//电梯改变状态
{
	
}

void Elevator::Continue()//电梯续航
{
	if(waiting != 0){
		if(direction == STOP){
			if(condition = ON){//上客
				waiting --;
				if(waiting == 0){
					condition = STOP;
				}

				if(waiting % T){//寻找待上乘客
					People *i;
					for(i = Up[num]->pHead; i <= Up[num]->pRear; i++){
						if (i->Presflr() == presflr){
							i->Arrange();
							Up[num]->dele(i);
							Down[num]->push_back(i);
						}
					}
				}
			}

			if(condition = OFF){//下客
				waiting --;
				if(waiting == 0){
					condition = STOP;
				}

				if(waiting % T){//寻找待下乘客
					People *i;
					for(i = Down[num]->pHead; i <= Down[num]->pRear; i++){
						if (i->Objflr() == presflr){
							Down[num]->dele(i);
							delete i;
						}
					}
				}
			}
		}else if (direction != UP)
		{
			waiting--;
			if (!waiting)
			{
				direction = STOP;
			}
		}
	}
}

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

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
		condition = WAITING;
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
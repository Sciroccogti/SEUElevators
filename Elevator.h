#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Rear_End.h"

class Elevator
{
protected:
	int total;		//总重
	int presflr;	//所在层
	int direction;	//方向
	int condition;	//运行状态
	int objflr;		//目标层
	double time;	//时间
	int waiting;	//状态保持时间

public:
	Elevator(int presflr1);				//构造
	void Move(int goal);				//电梯移动
	void Board(int n);					//电梯上客
	void Drop(int n);					//电梯下客
	Elevator& operator [](const int n);
	bool IsFull(int weight1){return MAX - total < weight1;}
	int Direction(){return direction;}
	int Objflr(){return objflr;}
};

Elevator::Elevator(int presflr1)//构造
{
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

Elevator& Elevator::operator [](const int n)
{
	return this[n];
}

#endif
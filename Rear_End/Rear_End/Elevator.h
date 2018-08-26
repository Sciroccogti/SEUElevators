#include "Rear_End.h"
#include "People.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

class Elevator
{
protected:
	int num;		//编号
	int passenger;	//人数
	int presflr;	//所在层
	int condition;	//运行状态
	int objflr;		//目标层
	double time;	//时间
	int waiting;	//状态保持时间

public:
	Elevator(int,int);	//构造
	void Move(int goal);//电梯移动
	void Board(int n);	//电梯上客
	void Drop(int n);	//电梯下客
	friend void People::Check();
};

Elevator::Elevator(int num1, int presflr1)//构造
{
	num = num1;
	passenger = 0;
	presflr = presflr1;
	condition = STOP;
	objflr = 0;
	time = 0;
	waiting = 0;
}

void Elevator::Move(int goal)//电梯移动
{
	objflr = goal;

}

void Elevator::Board(int n)//电梯上客
{
	passenger += n;
	condition = ON;
	waiting += T * n;
}

void Elevator::Drop(int n)//电梯下客
{
	passenger -= n;
	condition = OFF;
	waiting += T * n;
}

#endif
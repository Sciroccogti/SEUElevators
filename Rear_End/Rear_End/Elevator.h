#ifndef REAR_END_H
#define REAR_END_H 
#include "Rear_End.h"
#endif

class Elevator
{
protected:
	int num;		//编号
	int passenger;	//人数
	int presflr;	//所在层
	int condition;	//运行状态
	int objflr;		//目标层
	double time;	//时间

public:
	Elevator(int,int);					//构造
	~Elevator();						//析构
	void move(int sflr,int eflr,int n);	//电梯移动
	void movein(int num_in);			//电梯上客
	void moveout(int num_out);			//电梯下客
	int check();						//轮询待乘乘客
};

Elevator::Elevator(int num1, int presflr1)//构造
{
	num = num1;
	passenger = 0;
	presflr = presflr1;
	condition = STOP;
	objflr=0;
	time=0;
}

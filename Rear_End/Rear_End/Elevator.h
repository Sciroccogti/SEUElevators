#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Rear_End.h"

template <class TYPE>
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
	Elevator <TYPE> (int num1, int presflr1){//构造
		num = num1;
		total = 0;
		presflr = presflr1;
		direction = STOP;
		condition = STOP;
		objflr = 0;
		time = 0;
		waiting = 0;
	}

	void Move(int goal){//电梯移动
		objflr = goal;
		direction = objflr > presflr ? UP : DOWN;
		waiting += S;
	}

	void Board(int n){//电梯上客
		if(!IsFull(weight1)){
			total += weight1;
			condition = ON;
			waiting += T;
		}
	}

	void Drop(int n){//电梯下客
		total -= weight1;
		condition = OFF;
		waiting += T;
	}

	void Change();			//电梯改变状态

	void Continue(){//电梯续航
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

	Elevator <TYPE> & operator [](const int n){return this[n];}
	bool IsFull(int weight1){return MAX - total < weight1;}
	int Direction(){return direction;}
	int Objflr(){return objflr;}
};

#endif
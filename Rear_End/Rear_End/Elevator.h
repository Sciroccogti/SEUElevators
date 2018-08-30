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
	double presflr;	//所在层
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

	void Change(){			//电梯改变状态
		TYPE *i;
		if(Up[num]->pHead){
			for(i = Up[num]->pHead; i; i = i->pNext){
				if (i->Presflr() == presflr && condition == STOP && !waiting){//上当前楼层的乘客
					condition = ON;
					waiting += T;
					total += i->Weight();
					if ((i->Objflr() - objflr) * direction < 0){//更改目标楼层
						objflr = i->Objflr();
					}
				}else if (!direction && !condition && !objflr){//更改目标楼层并开动电梯
					objflr = i->Presflr();
					direction = objflr > presflr ? UP : DOWN;
				}
			}		
		}
		
		if(Down[num]->pHead){
			for(i = Down[num]->pHead; i; i = i->pNext) {
				if (i->Objflr() == presflr && !condition){//下客
					condition = OFF;
					waiting += T;
					total -= i->Weight();
				}else if (!waiting && (i->Objflr() - objflr) * direction >= 0){//到下一个目标楼层
					objflr = i->Objflr();
					direction = objflr - presflr > 0 ? UP : DOWN;
					waiting += S;
				}
			}
		}
	}

	void Continue(){//电梯续航
		if(waiting != 0){
			if(direction == STOP){
				if(condition = ON){//上客
					waiting --;
					if(waiting == 0){//寻找待上乘客
						condition = STOP;
						TYPE *i;
						for(i = Up[num]->pHead; i; i = i->pNext){
							if (i->Presflr() == presflr){
								i->Arrange();
								Up[num]->Delete(i, MODEUD);
								Down[num]->push_back(i, MODEUD);
							}
						}
					}
				}

				if(condition = OFF){//下客
					waiting --;			
					if(waiting == 0){//寻找待下乘客
						condition = STOP;
						TYPE *i, *j;
						for(i = Down[num]->pHead; i; i = i->pNext){
							if (i->Objflr() == presflr){
								j = i;
								i = j->pFront;
								Down[num]->Delete(j, MODEUD);
								if (j->Direction() == UP){
									ListUp.Delete(j, MODELIST);
								}
								delete j;
								j = NULL;
							}
						}
					}
				}
			}else if (direction != STOP)//移动
			{
				waiting--;
				time++;
				presflr += (1 / S)* direction;
				if (!waiting && presflr == objflr){
					direction = STOP;
				}else if (!waiting){
					waiting += S;
				}
			}
		}
	}

	Elevator <TYPE> & operator [](const int n){return this[n];}
	bool IsFull(int weight1){return MAX - total < weight1;}
	int Direction(){return direction;}
	int Objflr(){return objflr;}
	double Presflr(){return presflr;}
};

#endif
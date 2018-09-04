#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Rear_End.h"

template <class TYPE>
class Elevator
{
//protected:
public:
	int num;		//编号
	int total;		//总重
	double presflr;	//所在层
	int direction;	//方向
	int condition;	//运行状态
	int objflr;		//目标层
	double time;	//总运行时间
	int waiting;	//状态保持时间
	bool isOK;		//是否不需要维护
	int inside;		//电梯内人数

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
		isOK = true;
		inside = 0;
	}

	void Change(){			//电梯改变状态
		TYPE *i;
		if(Board[num]->pHead){
			int j = objflr;//存储扫描到的最近待乘乘客所在层
			for(i = Board[num]->pHead; i; i = i->next){
				if (i->Presflr() == presflr && condition == STOP && direction == STOP && !waiting){//上当前楼层的乘客
					if(!isOK || IsFull(i->Weight())){
						i->Arrange(NOTARRANGED);
						Board[num]->Delete(i, MODEBD);
						NotArranged.push_back(i, MODEBD);
						continue;
					}
					condition = ON;
					waiting += T;
					total += i->Weight();
					j = objflr;
					break;

				}else if (!direction && !condition && !Drop[num]->pHead && !objflr){//若电梯正无所事事
					j = i->Presflr();
				
				}else if ((i->Presflr() - presflr) * direction < (j - presflr) * direction && direction == i->Direction()){//若扫到的人比上一个扫到的乘客或当前目标层更近
					j = i->Presflr();

				}else if((i->Presflr() - presflr) * direction > 0 && (i->Objflr() - objflr) * direction < 0 && direction == i->Direction()){//若乘客路径在电梯路径中
					j = i->Presflr();

				}else if (j ){
				}
			}		
			if (j != objflr){
				objflr = j;
				direction = objflr > presflr ? UP : DOWN;
				if(!waiting)waiting += S;
			}
		}
		
		if(Drop[num]->pHead){
			int j = objflr;//存储扫到的乘客目标层
			for(i = Drop[num]->pHead; i; i = i->next) {
				if (i->Objflr() == presflr && !condition){//下客
					condition = OFF;
					waiting += T;
					total -= i->Weight();
					j = objflr;
					break;
				}else if (!waiting && ((i->Objflr() - j) * direction < 0 || !j)){//到下一个目标楼层
					j = i->Objflr();
				}
			}
			if (j != objflr) {
				objflr = j;
				direction = objflr - presflr > 0 ? UP : DOWN;
				waiting += S;
			}
		}
	}

	void Continue(){//电梯续航
		if(waiting != 0){
			if(direction == STOP){
				if(condition == ON){//上客
					waiting --;
					if(waiting == 0){//寻找待上乘客
						condition = STOP;
						TYPE *i;
						
						for(i = Board[num]->pHead; i; i = i->next){
							if (i->Presflr() == presflr){
								Board[num]->Delete(i, MODEBD);
								Drop[num]->push_back(i, MODEBD);
								i->Arrange(INELE);
								direction = i->Objflr() - presflr > 0 ? UP : DOWN;
								inside ++;
								break;
							}
						}

						int j = objflr;//存储扫描到的乘客目标层
						for (i = Drop[num]->pHead; i; i = i->next) {
							if ((i->Objflr() - presflr) * direction < (j - presflr) * direction || !j) {
								j = i->Objflr();
							}
						}
						objflr = j;
						waiting += S;
					}

				}else if(condition == OFF){//下客
					waiting --;			
					if(waiting == 0){//寻找待下乘客
						condition = STOP;
						TYPE *i = Drop[num]->pHead;
						for(i = Drop[num]->pHead; i; i = i->next){
							if (i->Objflr() == presflr){
								Drop[num]->Delete(i, MODEBD);
								if (i->Direction() == UP){
									ListUp.Delete(i, MODELIST);
								}else{
									ListDown.Delete(i, MODELIST);
								}
								delete i;
								i = NULL;
								inside --;
								break;
							}
						}
					}
				}
			}else if (direction != STOP && objflr)//移动
			{
				waiting--;
				time++;
				presflr += (1 / (double)S) * direction;
				if(abs(floor(presflr + 0.5) - presflr) < 0.1){
					presflr = floor(presflr + 0.5);
				}
				if (!waiting && presflr == objflr){
					objflr = 0;
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
	int Condition(){return condition;}
	int Inside(){return inside;}//返回电梯内人数
	bool IsOK(){return isOK;}
	void Repair(){isOK = true;}
};

#endif
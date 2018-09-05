#ifndef REAR_END_H
#define REAR_END_H 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define STOP 0			//停止
#define UP 1			//上行
#define DOWN -1			//下行
#define ON 2			//上客中
#define OFF -2			//下客中

#define NOTARRANGED -1	//乘客状态：未安排
#define WAITING 0		//乘客状态：等待中
#define INELE 1			//乘客状态：电梯中

#define MODEBD 1		//供Board/Drop/NotArranged使用
#define MODELIST 2		//供ListUp/Down使用

#define N 3				//电梯数量
#define L 20			//最高楼层
#define MAX 1600		//最大载重量
#define S 3				//电梯运行速度S秒/层
#define T 2				//乘客上下时间
#define T0 1000		//维护阈值

using namespace std;
//ATTENTION:
//本项目尽可能保持：
//		变量名全部小写
//		函数名与类名首字母大写

#endif
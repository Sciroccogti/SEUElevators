#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>
#define STOP 0
#define DOWN -1
#define UP 1
int top = 20;

class Elevator
{
protected:
	int num;		//编号
	int passenger;	//人数
	int presflr;	//所在层
	int run;		//是否运动
	int objflr;		//目标层
	double time;	//时间

public:
	Elevator(int,int);					//构构
	~Elevator();						//析构
	void move(int sflr,int eflr,int n);	//电梯移动
	void movein(int num_in);			//电梯上客
	void moveout(int num_out);			//电梯下客
	int check();						//轮询待乘乘客
};

Elevator::Elevator(int num1, int presflr1)
{
	num = num1;
	passenger = 0;
	presflr = presflr1;
	run = STOP;
	objflr=0;
	time=0;
}

class People
{
protected:
	int presflr;
	int objflr;
	int direction;
	int weight;

public:
	People();
};

People::People()
{
	//随机生成所在层与目标层
	srand((int)time(0));
	presflr = rand() % top;
	do{
		objflr = rand() % top;
	}while(presflr == objflr);
	//生成方向
	direction = presflr < objflr ? UP : DOWN;
	//随机生成体重
	weight = 50 + rand() % 50;
	//TODO：改为正态分布+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//cout<<presflr<<endl<<objflr<<endl<<direction<<endl<<weight<<endl;//测试用代码
}

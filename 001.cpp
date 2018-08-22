#include<iostream.h>
#include<stdlib.h>
#include<time.h>
#define STOP 0
#define DOWN -1
#define UP 1
int floor=20;
class Ele
{
	int num;		//编号
	int innum;		//人数
	int presflr;	//所在楼层
	int run;		//是否运动
	int objflr;		//目标楼层
	double time;	//时间
public:
	Ele(int,int);
	~Ele();
	void move(int sflr,int eflr,int n);
	void movein(int numin);
	void moveout(int numout);
	int check();
};

Ele::Ele(int num1, int presflr1)
{
	num = num1;
	innum = 0;
	presflr = presflr1;
	run = STOP;
	objflr=0;
	time=0;
}


class People
{
public:
	int presflr;
	int objflr;
	People();
	~People();
};

People::People()
{
	presflr=rand()%20;
	objflr=rand()%20;
}

People::~People()
{
	presflr=0;
	objflr=0;
}


void main()
{
	int count;
	cin>>count;
	People p[count];
}
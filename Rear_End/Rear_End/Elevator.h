#ifndef REAR_END_H
#define REAR_END_H 
#include "Rear_End.h"
#endif

class Elevator
{
protected:
	int num;		//���
	int passenger;	//����
	int presflr;	//���ڲ�
	int condition;	//����״̬
	int objflr;		//Ŀ���
	double time;	//ʱ��

public:
	Elevator(int,int);					//����
	~Elevator();						//����
	void move(int sflr,int eflr,int n);	//�����ƶ�
	void movein(int num_in);			//�����Ͽ�
	void moveout(int num_out);			//�����¿�
	int check();						//��ѯ���˳˿�
};

Elevator::Elevator(int num1, int presflr1)//����
{
	num = num1;
	passenger = 0;
	presflr = presflr1;
	condition = STOP;
	objflr=0;
	time=0;
}

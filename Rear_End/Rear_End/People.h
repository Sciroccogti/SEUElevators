#ifndef REAR_END_H
#define REAR_END_H 
#include "Rear_End.h"
#endif

class People
{
//protected:
//TODO����Ϊprotected++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public://����ʱʹ��
	int presflr;
	int objflr;
	int direction;
	int weight;

public:
	People();
};

list <People> ListUp, ListDown;

People::People()
{
	//����������ڲ���Ŀ���
	presflr = rand() % TOP;
	do{
		objflr = rand() % TOP;
	}while(presflr == objflr);

	//���ɷ���
	direction = presflr < objflr ? UP : DOWN;

	//�����������
	weight = 50 + rand() % 50;
	//TODO����Ϊ��̬�ֲ�+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//cout<<presflr<<endl<<objflr<<endl<<direction<<endl<<weight<<endl;//�����ô���
}

void Refresh()
{
	//srand((int)time(0));	//���÷���
	//int n = rand() % TOP;	//���÷���
	int n = 1;
	//TODO����Ϊ���������++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int i = 0;
	People *p;
	srand((int)time(0));
	while(i++ < n){
		p = new People;
		if(p->direction == UP){
			ListUp.push_front(*p);
		}else{
			ListDown.push_front(*p);
		}
		//cout<<p->weight<<"\t"<<p->objflr<<endl;//�����ô���
	}
}


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
	People* pNext;
	People* pFront;

public:
	People();
	People(People&);
};


class ST_People
{
public:
	People* pHead;
	People* pRear;
	int num;
	int mode;
public:
	ST_People(int);
	~ST_People();
	void push_front(int nm);
	void push_back(int nm);
	void print();
	void dele(People* p);
};
////////////////////////////////////////////////////////////////////////////////////////////////
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
	pNext = pFront = NULL;
}

People::People(People&t)
{
	presflr=t.presflr;
	objflr=t.objflr;
	direction=t.direction;
	weight=t.weight;
	People* pNext=0;
	People* pFront=0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
ST_People::ST_People(int md)
{
	pHead = pRear = 0;
	mode=md;
}

ST_People::~ST_People()
{
	while(pHead)
	{
		People* pCur=pHead;
		pHead=pHead->pNext;
		delete pCur;
	}
	pRear=NULL;
	num=0;
}



void ST_People::push_front(int nm)
{
	for(int i=0;i<nm;i++)
	{
			People* pNew=0;
		while(1)
		{
			pNew=new People;
			if(pNew->direction==mode)
				break;
			else
				delete pNew;
		}
		if(pHead&&pRear)
		{
			pNew->pNext=pHead;
			pHead->pFront=pNew;
			pHead=pNew;
		}
		else
		{
			pHead=pRear=pNew;
		}
	}
}

void ST_People::push_back(int nm)
{
	for(int i=0;i<nm;i++)
	{
			People* pNew=0;
		while(1)
		{
			pNew=new People;
			if(pNew->direction==mode)
				break;
			else
				delete pNew;
		}
		if(pHead&&pRear)
		{
			pNew->pFront=pRear;
			pRear->pNext=pNew;
			pRear=pNew;
		}
		else
		{
			pHead=pRear=pNew;
		}
	}
}

void ST_People::print()
{
	
	People* pCur=pHead;
	if(pCur)
	{	
		if(mode==1)
		cout<<"����������Ϣ:"<<endl;
		else
		cout<<"����������Ϣ"<<endl;
	}
	while(pCur)
	{	
		cout<<"Ŀǰ¥��:"<<pCur->presflr<<'\t'<<"Ŀ��¥��"<<pCur->objflr<<'\t';
		cout<<"����";
		if(pCur->direction==UP)
			cout<<"����";
		else
			cout<<"����";
		cout<<'\t'<<"����"<<pCur->weight<<endl;
		pCur=pCur->pNext;
	}
	cout<<"*******************************************************************"<<endl;
}

void ST_People::dele(People* p)
{
	if(p&&pHead&&pRear)
	{
		if(p==pHead)
		{
			People* pCur=pHead;
			pHead=pHead->pNext;
			delete pCur;
		}
		else if(p==pRear)
		{
			People* pCur=pRear;
			pRear=pRear->pFront;
			delete pCur;
		}
		else
		{
			People* pCur=p;
			p->pFront->pNext=p->pNext;
			delete pCur;
		}
	}
}

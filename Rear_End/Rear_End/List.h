#include "Rear_End.h"

template <class TYPE>
class List
{
public:
	TYPE* pHead;
	TYPE* pRear;
	int num;
public:
	List <TYPE>(){
		pHead = pRear = NULL;
	}

	~List<TYPE>(){
		while(pHead)
		{
			TYPE* pCur=pHead;
			pHead=pHead->pNext;
			delete pCur;
		}
		pRear=NULL;
		num=0;
	}
	/*
	void push_front(TYPE *p){
		for(int i = 0;i < n; i++)
		{
			People* pNew = 0;
			while()
			{
				pNew = new People;
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
	*/
	void push_back(TYPE *p){
		if (pHead == pRear)
		{
			pHead = pRear = p;
		}else{
			pRear = p;
			p->pFront = pRear;
		}
	}
	/*
	void print(){
		TYPE* pCur=pHead;
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
	*/
	void dele(TYPE* p){
		if(p && pHead && pRear)
		{
			if(p == pHead)
			{
				TYPE* pCur = pHead;
				pHead = pHead->pNext;
				delete pCur;
			}
			else if(p == pRear)
			{
				TYPE* pCur = pRear;
				pRear = pRear->pFront;
				delete pCur;
			}
			else
			{
				TYPE* pCur = p;
				p->pFront->pNext = p->pNext;
				delete pCur;
			}
		}
	}

};
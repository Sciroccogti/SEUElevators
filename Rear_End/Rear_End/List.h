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
	void push_back(TYPE *p, int mode){
		if (!pHead && !pRear)
		{
			pHead = pRear = p;
		}else{
			if (mode == MODELIST)
			{
				p->pFront = pRear;
				pRear->pNext = p;
				pRear = p;
			}else if(mode == MODEUD){
				p->prev = pRear;
				pRear->next = p;
				pRear = p;
			}

		}
	}
	/*
	void print(){
		TYPE* pCur=pHead;
		if(pCur)
		{	
			if(mode==1)
				cout<<"上行链表信息:"<<endl;
			else
				cout<<"下行链表信息"<<endl;
		}
		while(pCur)
		{	
			cout<<"目前楼层:"<<pCur->presflr<<'\t'<<"目标楼层"<<pCur->objflr<<'\t';
			cout<<"方向";
			if(pCur->direction==UP)
				cout<<"向上";
			else
				cout<<"向下";
			cout<<'\t'<<"体重"<<pCur->weight<<endl;
			pCur=pCur->pNext;
		}
		cout<<"*******************************************************************"<<endl;
	}
	*/
	void Delete(TYPE* p, int mode){
		if (mode == MODELIST)
		{
			if(p && pHead && pRear)
			{
				if(p == pHead)
				{
					pHead = pHead->pNext;
				}
				else if(p == pRear)
				{
					pRear = pRear->pFront;
				}
				else
				{
					p->pFront->pNext = p->pNext;
				}
			}
		}else if (mode ==MODEUD)
		{
			if(p && pHead && pRear)
			{
				if(p == pHead)
				{
					pHead = pHead->next;
				}
				else if(p == pRear)
				{
					pRear = pRear->prev;
				}
				else
				{
					p->prev->next = p->next;
				}
			}
		}
		
	}

};
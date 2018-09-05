#include "Rear_End.h"

template <class TYPE>
class List
{
public:
	TYPE* pHead;
	TYPE* pRear;
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
			}else if(mode == MODEBD){
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
				if (pHead == pRear)
				{
					pHead = pRear = NULL;
				} 
				else if(p == pHead)
				{
					pHead = pHead->pNext;
					p->pNext->pFront = p->pFront;
				}
				else if(p == pRear)
				{
					pRear = pRear->pFront;
					p->pFront->pNext = p->pNext;
				}
				else
				{
					p->pFront->pNext = p->pNext;
					p->pNext->pFront = p->pFront;
				}
				p->pFront = NULL;
				p->pNext = NULL;
			}
		}else if (mode ==MODEBD)
		{
			if(p && pHead && pRear)
			{
				if (pHead == pRear)
				{
					pHead = pRear = NULL;
				}
				else if(p == pHead)
				{
					pHead = pHead->next;
					p->next->prev = p->prev;
				}
				else if(p == pRear)
				{
					pRear = pRear->prev;
					p->prev->next = p->next;
				}
				else
				{
					p->prev->next = p->next;
					p->next->prev = p->prev;
				}
				p->prev = NULL;
				p->next = NULL;
			}
		}
		
	}

};
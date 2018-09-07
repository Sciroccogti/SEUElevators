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
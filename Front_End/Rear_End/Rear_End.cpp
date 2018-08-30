﻿#include "stdafx.h"
#include "People.h"


void Refresh(Elevator <People> *e[N])
{
	//srand((int)time(0));	//备用方法
	//int n = rand() % TOP;	//备用方法
	int n = 9;
	//TODO：改为随机、大量++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int i = 0;
	People *p;
	srand((int)time(0));
	while(i++ < n){
		p = new People;
		if(p->Direction() == UP){
			ListUp.push_back(p, MODELIST);
		}else{
			ListDown.push_back(p, MODELIST);
		}
		p->Check(e);
		cout<<p->Presflr()<<"\t"<<p->Objflr()<<"\n";
	}
}

void Initialize(Elevator <People> *e[N])//初始化电梯
{
	int i;
	for(i = 0; i < N; i++){
		if(i < N / 3){
			e[i] = new Elevator <People> (i, 1);
		}else if(i >= 2 * N / 3){
			e[i] = new Elevator <People> (i, L);
		}else{
			e[i] = new Elevator <People> (i, L / 2);
		}
	}
}

void Show(int *n)//显示各层等待人数
{
	People *i;
	for(i = ListUp.pHead; i; i = i->pNext){
		n[i->Presflr()]++;
	}
	for(i = ListDown.pHead; i; i = i->pNext){
		n[i->Presflr()]++;
	}
}/*
//TODO：增加对待定乘客的操作+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(){
	Elevator <People> *e[N];
	Initialize(e);
	int n[L + 1] = {0}, i;
	Refresh(e);	
	cout<<endl;
	Show(n);
	for (i = 1; i <= L; i++){
		cout<<i<<"\t"<<n[i]<<"\n";
	}

	cout<<"\n";
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}
	return 0;
}
*/
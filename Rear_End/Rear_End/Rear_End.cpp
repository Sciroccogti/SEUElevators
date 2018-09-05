#include "People.h"
#include <iomanip>


//TODO：增加对待定乘客的操作+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(){
	srand((int)time(0));
	Elevator <People> *e[N];
	Ini(e);
	int n[L + 1] = {0}, i = 0, j;/*
	Show(n);
	for (i = 1; i <= L; i++){
		cout<<i<<"\t"<<n[i]<<"\n" ;
	}
	
	cout<<"\n";
	*/
	/*
		_sleep(200);
		People *p;
		p = new People(1,3);
		if(p->Direction() == UP){
			ListUp.push_back(p, MODELIST);
		}else{
			ListDown.push_back(p, MODELIST);
		}
		p->Check(e, true);
		e[i]->Change();
		e[i]->Continue();
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	cout<<endl;	

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	_sleep(200);
	p = new People(2,3);
	if(p->Direction() == UP){
		ListUp.push_back(p, MODELIST);
	}else{
		ListDown.push_back(p, MODELIST);
	}
	p->Check(e, true);
	e[i]->Change();
	e[i]->Continue();
	cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
	cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	cout<<endl;	
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	_sleep(200);
	p = new People(3,1);
	if(p->Direction() == UP){
		ListUp.push_back(p, MODELIST);
	}else{
		ListDown.push_back(p, MODELIST);
	}
	p->Check(e, true);
	e[i]->Change();
	e[i]->Continue();
	cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
	cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	cout<<endl;	
	*/
	
	for (j = 0; j < 500; j++)
	{
		_sleep(1);
		Refresh(e);
		/*
		p = NotArranged.pHead;
		while(p){
			p->Check(e, false);
			p = p->next;
		}
		*/
		for (i = 0; i < N; i++){
			e[i]->Change();
			e[i]->Continue();
			cout<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
			cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<"\t"<<e[i]->Direction()<<endl;
		}
		cout<<endl;	
	}

	return 0;
}

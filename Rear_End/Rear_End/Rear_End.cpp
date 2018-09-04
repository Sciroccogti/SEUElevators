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

	cout<<"\n";*/

		_sleep(200);


		People *p;

		p = new People(2,1);
		if(p->Direction() == UP){
			ListUp.push_back(p, MODELIST);
		}else{
			ListDown.push_back(p, MODELIST);
		}
		p->Check(e, true);
		cout<<p->Presflr()<<"\t"<<p->Objflr()<<"\t"<<p->Weight()<<endl;
		e[i]->Change();
		e[i]->Continue();
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	cout<<endl;	

	_sleep(200);
	//TODO：改为随机、大量++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	p = new People(3,4);
	if(p->Direction() == UP){
		ListUp.push_back(p, MODELIST);
	}else{
		ListDown.push_back(p, MODELIST);
	}
	p->Check(e, true);
	cout<<p->Presflr()<<"\t"<<p->Objflr()<<"\t"<<p->Weight()<<endl;
	e[i]->Change();
	e[i]->Continue();
	cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
	cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	cout<<endl;	

	for (j = 0; j < 30; j++)
	{
		_sleep(200);

			e[0]->Change();
			e[0]->Continue();
			cout<<0<<"\t"<<setw(10)<<e[0]->Presflr()<<"\t";
			cout<<e[0]->Objflr()<<"\t"<<e[0]->waiting<<endl;
			p = NotArranged.pHead;

			while(p){
				p->Check(e, false);
				p = p->next;
			}
		cout<<endl;	
	}

	return 0;
}

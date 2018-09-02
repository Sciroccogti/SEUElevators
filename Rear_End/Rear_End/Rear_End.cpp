#include "People.h"
#include <iomanip>


//TODO：增加对待定乘客的操作+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(){
	srand((int)time(0));
	Elevator <People> *e[N];
	Ini(e);
	int n[L + 1] = {0}, i, j;
	Refresh(e);	
	cout<<endl;/*
	Show(n);
	for (i = 1; i <= L; i++){
		cout<<i<<"\t"<<n[i]<<"\n" ;
	}

	cout<<"\n";*/
	for (j = 0; j < 20; j++)
	{
		_sleep(200);
		Refresh(e);
		for(i = 0; i < N; i++){
			e[i]->Change();
			e[i]->Continue();
			cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
			cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
		}cout<<endl;	
	}
	return 0;
}

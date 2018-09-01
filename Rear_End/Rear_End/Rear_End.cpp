#include "People.h"
#include <iomanip>


//TODO：增加对待定乘客的操作+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(){
	Elevator <People> *e[N];
	Ini(e);
	int n[L + 1] = {0}, i;
	Refresh(e);	
	cout<<endl;
	Show(n);
	for (i = 1; i <= L; i++){
		cout<<i<<"\t"<<n[i]<<"\n";
	}

	cout<<"\n";
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	
	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	for(i = 0; i < N; i++){
		cout<<i<<"\t"<<setw(10)<<e[i]->Presflr()<<"\t";
		e[i]->Change();
		e[i]->Continue();
		cout<<e[i]->Objflr()<<"\t"<<e[i]->waiting<<endl;
	}	

	return 0;
}

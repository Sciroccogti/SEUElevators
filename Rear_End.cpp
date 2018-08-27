#include "People.h"

list <People> ListUp, ListDown;

void Refresh()
{
	//srand((int)time(0));	//备用方法
	//int n = rand() % TOP;	//备用方法
	int n = 1;
	//TODO：改为随机、大量++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int i = 0;
	People *p;
	srand((int)time(0));
	while(i++ < n){
		p = new People;
		if(p->Direction() == UP){
			ListUp.push_back(*p);
		}else{
			ListDown.push_back(*p);
		}
		//cout<<p->weight<<"\t"<<p->objflr<<endl;//测试用代码
	}
}

int main(){
	Elevator *e[N];
	int i;
	for(i = 0; i < N; i++){
		if(i < N / 3){
			e[i] = new Elevator(1);
		}else if(i > 2 * N / 3){
			e[i] = new Elevator(L);
		}else{
			e[i] = new Elevator(L / 2);
		}
	}
	return 0;
}

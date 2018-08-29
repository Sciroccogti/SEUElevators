#include "People.h"


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
			ListUp.push_back(p);
		}else{
			ListDown.push_back(p);
		}
		//cout<<p->weight<<"\t"<<p->objflr<<endl;//测试用代码
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
		n[i->Presflr() - 1]++;
	}
	for(i = ListDown.pHead; i; i = i->pNext){
		n[i->Presflr() - 1]++;
	}
}

int main(){
	Refresh();
	int n[L + 1] = {0}, i;
	Show(n);
	for (i = 1; i <= L; i++)
	{
		cout<<i<<"\t"<<n[i]<<"\n";
	}
	return 0;
}

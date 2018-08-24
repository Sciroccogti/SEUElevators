#include "Rear_End.h"
#include "Elevator.h"
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
		if(p->direction == UP){
			ListUp.push_front(*p);
		}else{
			ListDown.push_front(*p);
		}
		//cout<<p->weight<<"\t"<<p->objflr<<endl;//测试用代码
	}
}

void Check()
{

}

int main(){
	//People people;//测试用代码
	//Refresh();
	Elevator e1(1, 1);
	e1.Board(2);
	return 0;
}

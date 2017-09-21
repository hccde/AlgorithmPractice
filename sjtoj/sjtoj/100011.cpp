#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int height;int chair;int count;
	int apple;int number(0);
	cin>>height>>chair>>count;
	for(int i = 0;i < count;i++){
		cin>>apple;
		if(apple <= (height + chair))
			number += 1;
	}
	cout<<number;
}
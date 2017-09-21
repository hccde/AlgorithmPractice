#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int monthMoney(0);
	int total(0);
	int save(0);
	for(int i = 0; i < 12 ; i++){
		cin>>monthMoney;
		total+=(300-monthMoney);
		label:if(total >= 100){
			total -= 100;
			save += 100;
			goto label;
		}else if(total<0){
			cout << (i+1) * -1<<endl;
			return 0;
		}
	}
	cout<<save*1.2+total<<endl;
}
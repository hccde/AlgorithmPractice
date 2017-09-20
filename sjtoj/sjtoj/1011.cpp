#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
private:
  double x,y;
public:
	double getX() const{
		return x;
	}
	double getY() const{
		return y;
	}
	friend istream& operator >>(istream& cin,MyComplex& val);
	friend ostream& operator <<(ostream& cout,MyComplex& val);
	friend MyComplex operator +(MyComplex& lv,MyComplex& rv);
	friend MyComplex operator -(MyComplex& lv,MyComplex& rv);
	friend MyComplex operator *(MyComplex& lv,MyComplex& rv);
	friend MyComplex operator /(MyComplex& lv,MyComplex& rv);

	friend MyComplex& operator +=(MyComplex& lv,MyComplex& rv);
	friend MyComplex& operator -=(MyComplex& lv,MyComplex& rv);
	friend MyComplex& operator *=(MyComplex& lv,MyComplex& rv);
	friend MyComplex& operator /=(MyComplex& lv,MyComplex& rv);
};

	istream& operator >>(istream& cin,MyComplex& val){
		cin>>val.x>>val.y;
		return cin;
	}

	ostream& operator <<(ostream& cout,MyComplex& val){
		cout.setf(ios::fixed);
		cout<<setprecision(2)<<val.x<<" "<<val.y<<endl;
		return cout;
	}

	ostream& operator <<(ostream& cout,const MyComplex& val){//const形成临时变量 const的
		cout.setf(ios::fixed);
		cout<<setprecision(2)<<val.getX()<<" "<<val.getY()<<endl;
		return cout;
	}

	MyComplex operator +(MyComplex& lv,MyComplex& rv){
		MyComplex res;
		res.x = rv.x + lv.x;
		res.y = rv.y + lv.y;
		return res;
	}
	
	MyComplex operator -(MyComplex& lv,MyComplex& rv){
		MyComplex res;
		res.x = lv.x - rv.x;
		res.y = lv.y - rv.y;
		return res;
	}

	MyComplex operator *(MyComplex& lv,MyComplex& rv){//乘法截断？
		MyComplex res;
		res.x = rv.x * lv.x - rv.y * lv.y;
		res.y = rv.x * lv.y + rv.y * lv.x;
		return res;
	}

	MyComplex operator /(MyComplex& lv,MyComplex& rv){
		MyComplex res;
		double b = rv.x * rv.x + rv.y *rv.y;
		res.x = (lv.x * rv.x + lv.y * rv.y) / b;
		res.y = (rv.x * lv.y - rv.y * lv.x) / b;
		return res;
	}

	MyComplex& operator +=(MyComplex& lv,MyComplex& rv){
		lv.x = rv.x + lv.x;
		lv.y = rv.y + lv.y;
		return lv;
	}
	MyComplex& operator -=(MyComplex& lv,MyComplex& rv){
		lv.x = lv.x - rv.x;
		lv.y = lv.y - rv.y;
		return lv;
	}
	MyComplex& operator *=(MyComplex& lv,MyComplex& rv){
		double s = rv.x * lv.y + rv.y * lv.x;
		double f = rv.x * lv.x - rv.y * lv.y;
		lv.x = f;
		lv.y = s;
		return lv;
	}
	MyComplex& operator /=(MyComplex& lv,MyComplex& rv){
		double b = rv.x * rv.x + rv.y *rv.y;
		double f = lv.x * rv.x + lv.y * rv.y; 
		double s = rv.x * lv.y - rv.y * lv.x;
		lv.x = f / b;
		lv.y = s / b;
		return lv;
	}


int main()
{
  MyComplex z1;
  MyComplex z2;
  cin>>z1>>z2;

  cout << z1 + z2 <<endl;
  cout << z1 - z2 <<endl;
  cout << z1 * z2 <<endl;
  cout << z1 / z2 <<endl;
  cout << (z1 += z2) <<endl;
  cout << (z1 -= z2) <<endl;
  cout << (z1 *= z2) <<endl;
  cout << (z1 /= z2) <<endl;

  return 0;
}

#include <iostream>
#include <string.h>
#include <algorithm>
#include"String.h"
using namespace std;
void main()
{
	
	String a;
	cout << "\nNhap String a: ";
	cin >> a;
	String b;
	cout << "\nNhap String b: ";
	cin >> b;
	cout<<"\nlength string a:"<<a.getlength();
	cout << "\nLength string b: " << a.getlength();
	String c(a);
	cout << "\nChuoi c(copy tu chuoi a) : " << c;
	cout << endl;
	cout << "Info: " << a;
	a.Expand(b);
	cout << "\nAter expand: " << a;
	a.Reverse();
	cout << "\nAfter reverse: " << a << endl;
	
	system("pause");
	
}
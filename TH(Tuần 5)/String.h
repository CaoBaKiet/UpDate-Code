
#include <iostream>
#include <String.h>
#include <algorithm>
using namespace std;
class String
{
	char *str;
	int length;
public:
	String();
	String(const String &);
	String(char*);
	void set(char *);
	int getlength();
	friend istream& operator >> (istream& inDev, String &a);
	friend ostream& operator << (ostream& outDev, String a);
	String& Expand(String); // Noi 2 chuoi
	String& Reverse(); // dao nguoc chuoi
	~String();
};


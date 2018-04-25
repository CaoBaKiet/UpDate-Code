#include "String.h"



String::String()
{
	str = NULL;
	length = 0;
}

String::String(char *a)
{
	length = strlen(a);
	str = new char[length];
	str = a;
}

String::String(const String &a)
{
	length = a.length;
	this->str = a.str;
}

void String::set(char *a)
{
	length = strlen(a);
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = a[i];
	}
	
	

}

int String::getlength()
{
	return this->length;
}

String & String::Expand(String a)
{
	String temp(*this);
	this->length += (a.length);
	this->str = new char[length];
	for (int i = 0; i < temp.length; i++)
		str[i] = temp.str[i];
	for (int i = temp.length; i < length; i++)
		str[i] = a.str[i - temp.length];
	
	return *this;
}

String & String::Reverse()
{
	reverse(str, str + length);
	return *this;
}

String::~String()
{
	//str = NULL;
	//delete []str;
	
}

istream & operator >> (istream & is, String & a)
{
	char b[256];
	
	gets_s(b);
	
a.set(b);
	return is;
}

ostream & operator<<(ostream & os, String a)
{
	for (int i = 0; i < a.length; i++) 
		os << a.str[i];
	
	return os;
}

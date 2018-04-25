#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
void DocFile(ifstream &filein, vector <string> &a)
{
	while (!filein.eof())
	{
		string x;
		getline(filein, x);
		a.push_back(x);
	}
}
int Dem(string a)
{
	int dem = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if ((a[i] == '.' || a[i] == '?' || a[i] == '!')&&a[i-1]!='.'&&a[i - 1] != '?'&&a[i - 1] != '!')
			dem++;
	}
	return dem;
}
int demsotu(string b)
{
	string a = b;
	int dem = 0;
	while (true)
	{
		if (a[0] == ' ' || a[0] == '!' || a[0] == '.' || a[0] == '?' || a[0] == ':' || a[0] == ',')
			a.erase(a.begin() + 0);
		else
		{
			break;
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		
			
		if ((a[i] == ',' || a[i] == ':' || a[i] == '.' || a[i] == '!' || a[i] == '?' || a[i] == ' ')&&a[i-1]!=' '&& a[i - 1] != '!'&&a[i - 1] != '.'&&a[i - 1] != ','&&a[i - 1] != '?'&& a[i] != ':')
			dem++;
		if(a[i+1]=='\0' &&a[i] != ' '&&a[i] != ':'&& a[i] != '!'&&a[i] != '.'&&a[i] != ','&&a[i] != '?')
			dem++;
	}
	return dem;
}
void demsotutrongfile(ofstream &fileout,vector <string> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		int dem = 0;
		dem += demsotu(a[i]);
		fileout << "\nSo tu trong hang thu " << i + 1 << ":  ";
		fileout << dem;
	}
	

}
void DemSoCau(ofstream &fileout,vector <string> a)
{
	int dem = 0;
	for (int i = 0; i < a.size(); i++)
	{
		dem+=Dem(a[i]);
	}
	fileout <<"So cau trong file: "<< dem;
}
void CatTu(vector <string>&b, vector <string>& c)
{
	
	while (c.size() != 0)
	{

		string a = c[0];
		c.erase(c.begin() + 0);
		while (a.size() != 0)
		{
			while (true)
			{
				if (a[0] == ' ' || a[0] == '!' || a[0] == '.' || a[0] == '?' || a[0] == ':' || a[0] == ',')
				{
					a.erase(a.begin() + 0);
					
				}
				else
				{
					break;
				}
			}
			if (a.size() == 0)
				break;
			int i = 0;
			while (a[i] != ' ' &&a[i] != ','&& a[i] != '!' && a[i] != '.' && a[i] != '?' && a[i] != ':'&&a[i] != '\0')
			{
				i++;
			}
			
			string x = a.substr(0, i);
			b.push_back(x);
			a.erase(a.begin() + 0, a.begin() + i);
		}
	}
}
int TanSuat(vector <string>a, string x)
{
	int dem = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] == x)
			dem++;
	return dem;
}
void tansuatmax(ofstream &fileout, vector<string> b)
{
	int lc = TanSuat(b, b[0]);
	for (int i = 0; i < b.size(); i++)
	{
			if (TanSuat(b, b[i]) > lc)
				lc = TanSuat(b, b[i]);
	}
	
	fileout<< "\n tan suat cua tu xuat hien nhieu nhat =: " << lc << endl;
	fileout << "\n\tTu co tan suat max : ";
	for (int i = 0; i < b.size(); i++)
	{
		if(TanSuat(b,b[i])==lc)
		{
			int f = 0;
			for (int j = 0; j < i; j++)
				if (b[j] == b[i])
					f = 1;
			if (f == 0)
				fileout << b[i] << endl;
		}
		
	}
}
void main()
{
	vector <string> a;
	vector <string> b;
	ifstream filein("File.txt");
	DocFile(filein, a);
	filein.close();
	ofstream fileout("KQ.txt");
	DemSoCau(fileout, a);
	demsotutrongfile(fileout, a);
	CatTu(b, a);
	tansuatmax(fileout, b);
	fileout.close();
	cout << endl;

	system("pause");
}
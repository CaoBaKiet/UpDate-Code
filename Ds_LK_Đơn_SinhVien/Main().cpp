#include <iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<iomanip>
using namespace std;
string Ho[27] = { "Mai","Cao","Phan","Nguyen","Tran","Le","Pham","Phan","Vo","Truong","Dang","Vu","Ly","Ngo","Do","Bui","Ho","Doan","Luu","Trinh","Dinh","Chu","Dam","Huynh","Hoang","Ton","Lam" };
string Dem[15] = { "Thi","Nhu","Van","Ba","Quoc","Huyen","My","Anh","Hoang","Tuan","Quang","Tien","Thu","Huu","Lam" };
string Ten[20] = { "Kiet","Huy","Nam","Phu","Lien","Thuy","Minh","Trong","Thu","Tuyen","Hoa","Tu","Son","Trung","Hieu","Hung","Huong","Hau", "Diem","Duy" };
string MSSV[10] = { "KA","KB","KC","KD","KE","KF","KM","KN" ,"KI","KL"};

struct ngay
{
	int Ngay, Thang, Nam;
}; typedef struct ngay Ngay;
void NhapNgay(ngay &a)
{
	int Nam[10] = { 1999,2000,2001,1998,1997,2002,1996,1995,1994,1992 };
	a.Ngay = rand() % 20 + 5;
	a.Thang = rand() % 10 + 2;
	a.Nam = Nam[rand()%10];
}
void XuatNgay(ofstream &fileout,Ngay a)
{
	fileout <<setfill('0')<<setw(2)<<a.Ngay << "/" << setfill('0') << setw(2)<< a.Thang<<"/" << a.Nam;
}
void XuatNgay2(Ngay a)
{
	cout<< a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
struct sinhvien
{
	string strHoTen;
	string strMSSV;
	Ngay NgaySinh;
	float DTB;
}; typedef struct sinhvien SinhVien;

struct Node
{
	SinhVien SV;
	struct Node *pNext;
};
struct List
{
	Node *pHead;
	Node *pTail;
};
void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}
Node *GetNode(SinhVien x)
{
	Node *p=new Node;
	p->SV = x;
	p->pNext = NULL;
	return p;
}
void DocThongTin1SinhVien(ifstream &filein, SinhVien &a)
{

	getline(filein, a.strMSSV,'\t');
	getline(filein, a.strHoTen,'\t');
	filein >> a.NgaySinh.Ngay;
	filein.seekg(1, 1);
	filein >> a.NgaySinh.Thang;
	filein.seekg(1, 1);
	filein >> a.NgaySinh.Nam;
	
	filein >> a.DTB;
	string x;
	getline(filein, x);
	return;
}
void XuatThongTin1SinhVien(ofstream &fileout, SinhVien a)
{
	fileout << a.strHoTen << "\t" << a.strMSSV << "\t" << a.NgaySinh.Ngay<<"/"<<a.NgaySinh.Thang<<"/"<<a.NgaySinh.Nam << "\t" << a.DTB;
}
void XuatThongTin1SinhVien1(SinhVien a)
{
	cout << a.strHoTen << "\t\t" << a.strMSSV << "\t\t" << a.NgaySinh.Ngay << "/" << a.NgaySinh.Thang << "/" << a.NgaySinh.Nam << "\t\t" << a.DTB;
}
void AddTail(ifstream &filein,List &l,Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}


}
void AddTail2(List &l, Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void AddHead(List &l)
{

}
void DocDanhSachSinhVienVaoList(ifstream &filein, List &l)
{
	Init(l);
	while (!filein.eof())
	{
		SinhVien a;
		DocThongTin1SinhVien(filein, a);
		Node *p = GetNode(a);
		AddTail(filein, l, p);
	}
}
void XuatDanhSachSinhVienTuList(ofstream &fileout, List l)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		XuatThongTin1SinhVien(fileout, p->SV);
		fileout << endl;
		
	}
}
void Swap(SinhVien &a, SinhVien &b)
{
	SinhVien t = a;
	a = b;
	b = t;
}
void Saptang(List l)
{
	
		for (Node*p = l.pHead; p->pNext != NULL; p = p->pNext)
		{
			for (Node *q = p->pNext; q != NULL; q = q->pNext)
			{
				if (p->SV.DTB > q->SV.DTB)
					Swap(p->SV, q->SV);
			}
		}
	
}
string CatLayTen(string a)
{
	int d = 0;
	for (int i = a.size() - 1;a[i]!=' '; i--)
	{
		d++;
	}
	return a.substr(a.size()-d, d);
}
void TimKiemTheoTen(ofstream &fileout, List l,string ten)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		if (CatLayTen(p->SV.strHoTen) == ten)
		{
			XuatThongTin1SinhVien(fileout, p->SV);
			fileout << endl;
		}
	}
}
void ChuyenSoNguyenThanhString(long a, string &b)
{
	b.resize(10);
	int n = a;
	int i = 9;
	while (n != 0)
	{
		b[i] = n % 10+48;
		n = n / 10;
		i--;
	}

}
// Hàm tạo file
void InPut(List&l)
{
	Init(l);
	int n;
	cout << "\nNhap so luong sinh vien : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		SinhVien a;
		a.strHoTen = Ho[rand() % 27];
		a.strHoTen.insert(a.strHoTen.size(), " ");
		a.strHoTen.insert(a.strHoTen.size(), Dem[rand() % 15]);
		a.strHoTen.insert(a.strHoTen.size(), " ");
		a.strHoTen.insert(a.strHoTen.size(), Ten[rand() % 20]);
		a.strMSSV = MSSV[rand() % 10];
		long b = rand() % 7777777777 + 1000000000;
		string c;
		ChuyenSoNguyenThanhString(b, c);
		a.strMSSV.insert(a.strMSSV.size(),c);
		NhapNgay(a.NgaySinh);
		a.DTB = rand() % 5 + 5.6;
		Node*p = GetNode(a);
		AddTail2(l, p);
	
	}
}
void OutPut(ofstream &fileout, List &l)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		fileout << p->SV.strMSSV <<"\t" << p->SV.strHoTen<<"\t" ;
		XuatNgay(fileout, p->SV.NgaySinh);
		fileout << "\t" << p->SV.DTB << "\n";
	}
}
void XuatRaManHinh(List &l)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		XuatThongTin1SinhVien1(p->SV);
		cout << endl;

	}
}
void main()
{	
	srand(time(NULL));
	List l;
	ifstream filein("THONGTINSINHVIEN.txt");
	DocDanhSachSinhVienVaoList(filein, l);	
	filein.close();
	ofstream fileout("kkk.txt");
	Saptang(l);
	
	XuatRaManHinh(l);
	fileout.close();

	ofstream fileout2("TimKiem.txt");
	TimKiemTheoTen(fileout2, l, "Kiet");
	fileout.close();
	/*List l;
	InPut(l);
	ofstream fileout("THONGTINSINHVIEN.txt");

	OutPut(fileout, l);
	fileout.close();*/



	 system("pause");
}
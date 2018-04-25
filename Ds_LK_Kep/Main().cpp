#include <iostream>
#include <string>
using namespace std;


struct Node
{
	float fData;
	struct Node *pNext;
	struct Node *pPre;
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
//Ham tao Node
Node *GetNode(float x)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->fData = x;
	p->pNext = NULL;
	p->pPre = NULL;
	return p;
}
//Them vao cuoi danh sach
void AddTail(List &l, Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		p->pPre = l.pTail;
		l.pTail = p;
	}
}
//Them vao dau danh sach
void AddHead(List &l, Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPre = p;
		l.pHead = p;
	}
}
//Nhap danh sach lien ket don
void InPut(List &l)
{
	Init(l);

	while (true)
	{
		string x;

		cout << "\n\tNhap du lieu cho data: ";
		cin >> (x);
		if (x == ".")
			return;
		float diem = atof((char *)x.c_str());
		Node *p = GetNode(diem);

		
		AddTail(l, p);
		//AddHead(l,p);

	}
}
//Xuat danh sach lien ket don
void OutPut(List l)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
		cout<<p->fData<<"    ";
}
//Thêm Node p vào vào sau node q 
void ThemNodePVaoSauNodeq(List &l, Node *p, Node*q)
{
	if (l.pHead == NULL)
		return;
	if (l.pHead == l.pTail)
	{
		if (l.pHead->fData == q->fData)
		{
			AddTail(l, p);
			return;
		}
		else
		{
			return;
		}
	}
	Node *qq = l.pHead;
	for (Node *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->fData == q->fData)
		{
			qq = k->pNext;
			k->pNext = p;
			p->pPre = k;
			p->pNext = qq;
			qq->pPre = p;
			
		}
	}
	return;
}
// Xoa Node dau tien trong danh sach lien ket don
void XoaDau(List &l)
{
	if (l.pHead == NULL) return;
	if (l.pHead == l.pTail)
	{
		Init(l);
		return;
	}
	
	Node *q = l.pHead;
	l.pHead = l.pHead->pNext;
	l.pHead->pPre = NULL;
	delete q;
}
//Xoa Node Cuoi cung trong danh sach lien ket don
void XoaCuoi(List &l)
{
	if (l.pHead == NULL) return;
	if (l.pHead == l.pTail)
	{
		Init(l);
		return;
	}
	Node *q = l.pTail;
	l.pTail = l.pTail->pPre;
	l.pTail->pNext = NULL;
	delete q;

}
// Xoa mot node bat ki co truong info bang k
void XoaNodeCoGiaTriK(List &l, float k)
{
	if (l.pHead == l.pTail)
	{
		if(l.pHead->fData==k)
			Init(l);
		return;
	}
	Node *pp = l.pHead;
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->fData == k)
		{
			pp->pNext = p->pNext;
			p = p->pNext;
			p->pPre = pp;
		}
			pp = p;
	}
	return;
}
// Tìm xem gia tri X co trong mang khong (co tra ve 1 khong co tra ve -1)
int Search(List &l, float x)
{
	AddTail(l, GetNode(x));
	Node *p = l.pHead;
	for (; p->fData != x; p = p->pNext);
	if (p == l.pTail)
	{
		XoaCuoi(l);
		return -1;
	}
	XoaCuoi(l);
	return 1;
	
		
	
}
void main()
{
	List l;
	Node *p = GetNode(-9);
	Node *q = GetNode(3);
	InPut(l);
	ThemNodePVaoSauNodeq(l, p, q);
    XoaDau(l);
	XoaCuoi(l);
	XoaNodeCoGiaTriK(l, 3);
	if (Search(l, 5) == 1)
		cout << "\nGia tri 5 co trong mang!!";
	else
		cout << "\nGia tri 5 khong co trong mang!!";
	cout << endl;
	cout << "\n=====================Mang Sau khi xu ly===============================\n";
	OutPut(l);
	system("pause");
}
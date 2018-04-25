
#include <iostream>
#include <string>
using namespace std;
// Yêu cầu: Nhâp mảng danh sách các số nguyên vào list (Theo thứ tự tăng dần)
// Trộn hai list tăng dần thành 1 list tăng dần

struct Node
{
	float fData;
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
Node *GetNode(float x)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;

	p->fData = x;
	p->pNext = NULL;
	return p;

}
//Thêm một Node vào cuối danh sách
void AddTail(List &l, Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
// Thêm một Node vào đầu danh sách
void AddHead(List &l, Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;


	}
}
//Nhập danh sách liên kết đơn
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

		//AddTail(l, p);
		AddHead(l, p);

	}
}
//xuất danh sách liên kết đơn
void OutPut(List l)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
		cout << p->fData << "    ";

}
//Huỷ danh sách liên kết đơn
void GiaiPhong(List &l)
{
	Node *p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
//xoá node đầu danh sách liên kết
void xoadau(List &l)
{
	if (l.pHead == l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
		return;
	}
	Node *q = l.pHead;
	l.pHead = l.pHead->pNext;
	delete q;

}
//xoá node cuối danh sách liên kết
void xoacuoi(List &l)
{
	if (l.pHead == l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
		return;
	}
	Node *p = l.pHead;
	for (; p->pNext != l.pTail; p = p->pNext);

	delete l.pTail;
	p->pNext = NULL;
	p = l.pTail;


}
//Xoá một node sau node p
void Them1NodeVaoListTangDanDeDuocListTangDan(List&l, Node *q)
{
	if (l.pHead == NULL)
	{
		AddTail(l, q);
		return;
	}
	if (l.pHead->fData > q->fData)
	{
		AddHead(l, q);
		return;
	}
	if (l.pHead == l.pTail)
	{
		AddTail(l, q);
		return;
	}
	Node*k = l.pHead;
	Node *p = l.pHead->pNext;
	for (; p != NULL && p->fData < q->fData; p = p->pNext)
	{
		k = p;
	}
	k->pNext = q;
	q->pNext = p;
	return;
}
//Nhap danh sach lien ket don tang dan
void InPutDsLKTangDan(List &l)
{
	Init(l);
	int n;
	cout << "\nNhap so phan tu ban muon them veo node: ";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		float diem;
		diem = rand() % 100 - 35;
		Node *p = GetNode(diem);
		Them1NodeVaoListTangDanDeDuocListTangDan(l, p);
	}

}
//Nhap danh sách lien kết đơn
void TronTangDan(List &l1, List &l2)
{
	while (l1.pHead != NULL)
	{
		Node*p = l1.pHead;
		l1.pHead = l1.pHead->pNext;
		p->pNext = NULL;
		Them1NodeVaoListTangDanDeDuocListTangDan(l2, p);
	}
}

void main()
{
	List l1, l2;
	InPutDsLKTangDan(l1);
	cout << "\nList l1:\n";
	OutPut(l1);
	InPutDsLKTangDan(l2);
	cout << "\nList l2: \n";
	OutPut(l2);
	cout << endl << endl;
	cout << "\n=====================List 1 va 2 sau khi tron=============================\n";
	TronTangDan(l1, l2);
	OutPut(l2);
	cout << endl;
	GiaiPhong(l2);

	system("pause");

}




#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 1 tao cau truc Node va cay
struct Node
{
    int data;
    Node* pLeft;
    Node* pRight;
};

 // 2 chuyen gia tri sang Node
Node* initNode (int value)
{
    Node* p = new Node;
    p->data = value;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Ham khoi tao cay
struct Tree
{
    Node* pRoot;
};

void initTree(Tree& t)
{
    t.pRoot = NULL;
}

//4 Ham chuyen gia tri vao cay
void addNode (Tree& t, Node* p)
{
    if(t.pRoot == NULL)
    {
        t.pRoot = p;
        return;
    }

    Node* pGoto = t.pRoot;
    Node* pLoca = NULL;

    while(pGoto != NULL)
    {
        pLoca = pGoto;
        if(pGoto->data < p->data)
        {
            pGoto = pGoto->pRight;
        }else if (pGoto->data > p->data)
        {
            pGoto = pGoto->pLeft;
        }else if (pGoto->data == p->data)
        {
            return;
        }
    }

    if(p->data < pLoca->data)
    {
        pLoca->pLeft = p;
    }else if (p->data > pLoca->data)
    {
        pLoca->pRight = p;
    }
}


void inOrder(Tree t)
{
    stack <Node*> s;
    Node* p = t.pRoot;

    while(p!=NULL || s.empty() == false)
    {
        while(p!=NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        p = s.top();
        s.pop();
        cout << p->data << "   ";

        p = p->pRight;
    }
}

// 6 Ham nhap gia tu mang
void addArr(Tree& t, int a[])
{
    for(int i = 0; i < sizeof a; i++)
    {
        addNode(t, initNode(a[i]));
    }
}

// 7 Ham duyet theo LNR
void LNR(Node* p)
{
    if(p != NULL)
    {
        LNR(p->pLeft);
        cout << p->data << "   ";
        LNR(p->pRight);
    }
}

// 8 Tim gia tri trong cay
bool searchValue (Tree t, int value)
{
    Node* p = t.pRoot;

    while(p!=NULL)
    {
        if(p->data == value)
        {
            return true;
        }
        if(p->data < value)
        {
            p = p->pRight;
        }else if(p->data > value)
        {
            p = p->pLeft;
        }
    }
    return false;
}

// 9 Ham dem so Node cua cay
int countNode (Tree t)
{
    int cnt = 0;

    stack<Node*> s;
    Node* p = t.pRoot;

    while(p!=NULL ||s.empty()==false)
    {
        while(p!=NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        p = s.top();
        s.pop();
        cnt++;

        p = p->pRight;
    }
    return cnt;
}

//10 ham dem so Node la cua cay
int countLeaf(Tree t)
{
    int cnt1 = 0;
    stack<Node*> s;
    Node* p = t.pRoot;

    while(p!=NULL || s.empty() == false)
    {
        while(p!=NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        if(p->pLeft == NULL && p->pRight == NULL)
            cnt1++;
        s.pop();

        p = p->pRight;
    }
    return cnt1;
}

// 11 in nhanh
Node* timNode(Tree t, int value)
{
    Node* p = t.pRoot;

    while(p!=NULL)
    {
        if(p->data == value)
            return p;

        if(p->data < value)
            p = p->pRight;
        else if (p->data > value)
            p = p->pLeft;
    }
    return NULL;
}


//12 Ham dem so Node co gia tri nho hon X
int searchSmaller (Tree t, int x)
{
    int cnt2 = 0;
    stack<Node*> s;
    Node* p = t.pRoot;

    while(p!=NULL || s.empty() == false)
    {
        while(p!=NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        if(p->data < x) cnt2++;
        s.pop();

        p= p->pRight;
    }
    return cnt2;
}

// 13 Ham tinh tong cac Node trong cay
int total(Tree t)
{
    int tong = 0;
    stack<Node*> s;
    Node* p = t.pRoot;

    while(p!=NULL || s.empty() == false)
    {
        while(p!=NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        tong+= p->data;
        s.pop();

        p=p->pRight;
    }
    return tong;
}

//14 Ham tinh tong cac Node chan trong cay
int totaleven(Tree t)
{
    int tong = 0;
    stack<Node*> s;
    Node* p = t.pRoot;

    while(p!=NULL || s.empty() == false)
    {
        while(p!=NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        if(p->data%2 == 0) tong+=p->data;
        s.pop();

        p=p->pRight;
    }
    return tong;
}

//15 tim max va min trong cay
void searchMaxMin(Tree t)
{
    int minNode = t.pRoot->data;
    int maxNode = t.pRoot->data;
    Node* p = t.pRoot;
    Node* p1 = t.pRoot;
    while(p!=NULL)
    {
        minNode = p->data;
        p=p->pLeft;
    }
    while(p1!=NULL)
    {
        maxNode = p1->data;
        p1 = p1->pRight;
    }
    cout << "MIN: " << minNode << "\nMAX: " << maxNode << endl;
}


int main()
{
    Tree t;
    initTree(t);

    int n[] = {48, 23, 45, 89, 99, 69, 79, 34};
    addArr(t, n);

    inOrder(t);
    cout << endl;
    LNR(t.pRoot);

    cout << "\nTim gia tri 69:" << searchValue(t, 69) << endl;

    cout << "\nSo Node co trong cay:" << countNode(t) << endl;

    LNR(timNode(t, 89));

    cout << "\nSo la cua cay:" << countLeaf(t) << endl;

    int x; cin>> x;
    cout << "\nSo Node co gia tri nho hon X: " << searchSmaller(t, x) << endl;

    cout << "\nTong gia tri cac Node: " << total(t) << endl;

    cout << "\nTong gia tri cac Node chan: " << totaleven(t) << endl;

    searchMaxMin(t);

    return 0;
}

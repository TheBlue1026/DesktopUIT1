#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* pNext;
};

Node* initNode (int value){
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

struct Stack {
    Node* pTop;
};

void initStack (Stack& s){
    s.pTop = NULL;
}

void push (Stack& s, Node* p){
    if(s.pTop == NULL){
        s.pTop = p;
    }else {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void printfStack (Stack s){
    for(Node* p = s.pTop; p!=NULL; p = p->pNext){
        cout << p->data << "\t";
    }
}

int pop(Stack& s)
{
    int value = 0;
    if(s.pTop == NULL)
        return 0;
    Node* p = s.pTop;
    value = p->data;
    s.pTop = s.pTop->pNext;
    delete p;
    return value;

}



int main()
{
    Stack s;
    initStack(s);

    Node* p1 = initNode(10);
    Node* p2 = initNode(39);
    Node* p3 = initNode(79);

    push(s, p1);
    push(s, p2);
    push(s, p3);

    printfStack(s);
    int value = pop(s);

    printfStack(s);
    cout << "\n" <<value;

    return 0;
}

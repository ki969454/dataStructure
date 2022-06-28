#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct CLnode
{
    ElemType data;
    CLnode* next;
}CLnode, *CLinkList;

//初始化
void initList(CLinkList& L) {
    L = new CLnode;
    L->next = L;
}

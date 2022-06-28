#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    DuLNode* prior, * next;
}DuLNode, *DuLinkList;
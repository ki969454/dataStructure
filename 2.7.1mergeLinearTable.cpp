#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Lnode {
    ElemType data;
    Lnode* next;
}Lnode, *LinkList;

//初始化链表
void initList(LinkList& L) {
    L = new Lnode;
    L->next = NULL;
}

//头插法创建链表
void creatListByHead(LinkList& L, int num) {
    cout << "头插法创建链表：" << endl;
    for (int i = 0; i < num; i++) {
        Lnode* p = new Lnode;
        cout << "请输入第" << i + 1 << "个数据：" << endl;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

//合并链表(直接并)
LinkList mergeList(LinkList L1, LinkList L2) {
    LinkList L3;
    L3 = L1;
    Lnode* p = L3;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = L2->next;
    return L3;
}

//合并链表(无重复元素)
LinkList mergeListNoSame(LinkList L1, LinkList L2) {
    LinkList L3 = L1;
    Lnode* p = L2->next;
    while (p->next != NULL) {
        Lnode* q = L1->next;
        while (q != NULL) {
            if (q->data == p->data) {
                break;
            }
            else {

            }
        }
        p = p->next;
    }
}

void displayList(LinkList L) {
    for (Lnode* p = L->next; p; p = p->next) {
        cout << p->data << endl;
    }
}

int main () {
    LinkList L1, L2, L3;
    initList(L1);
    initList(L2);
    creatListByHead(L1, 5);
    creatListByHead(L2, 5);
    L3 = mergeList(L1, L2);
    displayList(L3);
    return 0;
}
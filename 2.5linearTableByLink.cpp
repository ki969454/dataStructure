#include<iostream>
using namespace std;
//
typedef int ElemType;

//链表定义
typedef struct Lnode {
    ElemType data;
    Lnode* next;
}Lnode, *LinkList;                  //LinkList为指向结构体Lnode的指针类型

//链表初始化(带头节点。头指针就是头节点的存储位置，头指针只是抽象出来的概念)
bool initList(LinkList& L) {
    L = new Lnode;
    L->next = NULL;
    return true;
}

//链表判断是否为空
bool ifListEmpty(LinkList L) {
    if (L->next) {
        return false;
    } else {
        return true;
    }
}

//链表销毁
bool destoryList(LinkList& L) {
    LinkList p;
    while (L) {
        p = L;
        L = L->next;
        delete p;
    }
    return true;
}

//链表清空(头指针和头节点还在)
bool clearList(LinkList& L) {
    Lnode* p;
    Lnode* q;
    p = L->next;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    return true;
}

//链表表长
int lengthOfList(LinkList L) {
    int n = 0;
    Lnode* p;
    p = L->next;
    while (p) {
        n++;
        p = p->next;
    }
    return n;
}

//链表取值
bool getElem(LinkList L, int i, ElemType& e) {
    Lnode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || i <= 0) { 
        return false;
    }
    e = p->data;
    return true;
}

//链表查找值的地址
Lnode* locateElem(LinkList L, ElemType e) {
    Lnode* p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//链表查找值的索引
int indexElem(LinkList L, ElemType e) {
    Lnode* p = L->next;
    int j = 1;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    if (p) {
        return j;
    } else {
        return -1;
    }
}

//链表指定位置插入节点(找第1~i个元素)
bool insertElem(LinkList& L, ElemType e, int i) {
    Lnode* p = L->next;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || i <= 0) {
        return false;
    }
    Lnode* q;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

//链表删除节点(找第1~（i-1）个元素)
bool deleteElem(LinkList& L, int i) {
    int j = 0;
    Lnode* p = L->next;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!(p->next) || i <= 0) {
        return false;
    }
    Lnode* q = p->next;
    p->next = p->next->next;
    delete q;
    return true;
}

//链表头插法
void createListByHead(LinkList& L, int num) {
    for (int i = 0; i < num; i++) {
        Lnode* p = new Lnode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

//链表尾插法
void createListBytail(LinkList& L, int num) {
    Lnode* r = L;
    for (int i = 0; i < num; i++) {
        Lnode* p = new Lnode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = r->next;
    }
}

int main() {
    LinkList L;
    initList(L);

    //createListByHead(L, 5);
    createListBytail(L, 5);
    for (Lnode* p = L->next; p; p = p->next) {
        cout << p->data << endl;
    }

    return 0;
}
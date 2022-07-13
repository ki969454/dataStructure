#include <iostream>


using namespace std;


typedef struct PNode {
    double coef;                    //系数
    int expn;                       //指数
    PNode* next;
}PNode, *LinkList;


//链表初始化
void initList(LinkList& L) {
    L = new PNode;
    L->next = NULL;
    return ;
}

//尾插法创建链表
void createListByTail(LinkList& L, int num) {
    PNode* r = L;
    for (int i = 0; i < num; i++) {
        PNode* p = new PNode;
        cout << "系数：" << " " << "次数：" << endl; 
        cin >> p->coef;
        cin >> p->expn;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//查看链表内容
void displayList(LinkList L) {
    PNode* p = L;
    p = p->next;
    while(p) {
        cout << p->coef << "  " << p->expn << endl;
        p = p->next;
    }
}

//稀疏多项式相加L3 = L1 + L2
void SPA(LinkList L1, LinkList L2, LinkList& L3) {
    PNode* p1 = L1->next;
    PNode* p2 = L2->next;
    PNode* p3 = L3;
    while(p1 != NULL && p2 != NULL) {
        if(p1->expn < p2->expn) {
            PNode* p = new PNode;
            p->coef = p1->coef;
            p->expn = p1->expn;
            p->next = NULL;
            p3->next = p;
            p3 = p3->next;
            p1 = p1->next;
        } else if (p1->expn > p2->expn) {
            PNode* p = new PNode;
            p->coef = p2->coef;
            p->expn = p2->expn;
            p->next = NULL;
            p3->next = p;
            p3 = p3->next;
            p2 = p2->next;
        } else {
            PNode* p = new PNode;
            p->coef = p1->coef + p2->coef;
            p->expn = p1->expn;
            if(p->coef != 0) {
                p3->next = p;
                p3 = p3->next;
                p3->next = NULL;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if(p1 == NULL) {
        p3->next = p2;
    } else {
        p3->next = p1;
    }
}

int main() {
    LinkList p1, p2, p3;
    initList(p1);
    initList(p2);
    initList(p3);
    cout << "1" << endl;
    createListByTail(p1, 5);
    cout << "2" << endl;
    createListByTail(p2, 3);

    SPA(p1, p2, p3);

    displayList(p3);
    return 0;
}
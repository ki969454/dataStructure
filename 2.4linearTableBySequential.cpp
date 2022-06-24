#define MAXSIZE 100
#include<iostream>
using namespace std;

//线性表的定义
struct SqList {
    int* elem;
    int length;
};

//线性表的初始化
bool initList(SqList& L) {
    L.elem = new int [MAXSIZE];
    if (!L.elem) {
        cout << "error" << endl;
    }
    L.length = 0;
    return 1;
}

//线性表的销毁
void destoryList(SqList& L) {
    if (L.elem) {
        delete L.elem;
        L.elem = NULL;
    }
}

//线性表的清空
void clearList(SqList& L) {
    L.length = 0;
}

//判断线性表是否为空
bool isEmpty(SqList& L) {
    return static_cast<bool>(L.length);
}

//线性表的取值
bool getElem(SqList& L, int i, int &e) {
    if (i < 0||i > L.length - 1) {
        cout << "out of range" << endl;
        return false;
    }
    e = L.elem[i];
    return true;
}

//线性表的查找
int locateList(SqList& L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i;
        }
    }
    return -1;
}

//线性表的插入
bool insertList(SqList& L, int i, int elem) {
    if (L.length == MAXSIZE) {
        cout << "can not insert" << endl;
        return false;
    }
    if (i < 0||i > L.length) {
        cout << "wrong insert position" << endl;
        return false;
    }
    for (int j = L.length; j >= i ; j--) {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i] = elem;
    L.length++;
    return true;
}

//线性表的删除
bool deleteList(SqList& L, int i) {
    if (i < 0||i > L.length - 1) {
        cout << "wrong delete position" << endl;
        return false;
    }
    if (L.length == 0) {
        cout << "List has no length" << endl;
        return false;
    }
    for (int j = i; j < L.length - 1; j++) {
        L.elem[j] = L.elem[j + 1];
    }
    L.length--;
    return true;
}

bool showList(SqList& L) {
    if (!L.elem) {
        cout << "do not have the list" << endl;
        return false;
    }
    cout << "Length of List: " << L.length << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << endl;
    }
    return true;
}

int main() {
    SqList L1;
    initList(L1);
    for (int i = 0; i < 10; i++) {
        insertList(L1, i, i);
    }
    insertList(L1, 2, 100);
    deleteList(L1, 2);
    showList(L1);
    cout << "2: " << locateList(L1, 2) << endl;
    return 0;
}
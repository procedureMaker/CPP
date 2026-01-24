// 2026考研数据结构算法题

#include <bits/stdc++.h>
typedef struct TNode
{
    int data;
    struct TNode *lchild, *rchild;
} TNode, *TTree;

// 存放最小点
int mmin = 1000000;

using namespace std;

// 获取最小值
void searchTree(TTree T, int k)
{
    if (T != NULL)
    {
        searchTree(T->lchild, k);
        if (abs(T->data - k) < mmin)
        {
            mmin = abs(T->data - k);
        }
        searchTree(T->rchild, k);
    }
}

// 查找并输出
void searchTree2(TTree T, int k)
{
    if (T != NULL)
    {
        searchTree2(T->lchild, k);
        if (mmin == abs(T->data - k))
        {
            cout << T->data << endl;
        }
        searchTree2(T->rchild, k);
    }
}

int main()
{

    return 0;
}
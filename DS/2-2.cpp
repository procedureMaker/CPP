#include <bits/stdc++.h>

using namespace std;

// 将两个非递减有序线性表LA和LB合并为新线性表LC，结果仍然非递减
vector<int> mergeSorted(const vector<int> &LA, const vector<int> &LB)
{
    vector<int> LC;
    LC.reserve(LA.size() + LB.size());
    size_t i = 0, j = 0;
    while (i < LA.size() && j < LB.size())
    {
        if (LA[i] <= LB[j])
        {
            LC.push_back(LA[i++]);
        }
        else
        {
            LC.push_back(LB[j++]);
        }
    }
    // 复制剩余部分
    while (i < LA.size())
        LC.push_back(LA[i++]);
    while (j < LB.size())
        LC.push_back(LB[j++]);
    return LC;
}

int main()
{
    vector<int> LA = {1, 3, 5, 7};
    vector<int> LB = {2, 3, 6, 8, 9};

    cout << "LA: ";
    for (int v : LA)
        cout << v << " ";
    cout << '\n';
    cout << "LB: ";
    for (int v : LB)
        cout << v << " ";
    cout << '\n';

    vector<int> LC = mergeSorted(LA, LB);

    cout << "合并后的LC: ";
    for (int v : LC)
        cout << v << " ";
    cout << '\n';

    return 0;
}
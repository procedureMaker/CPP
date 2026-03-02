#include <bits/stdc++.h>

using namespace std;

// 将LB中的元素依次插入LA（如果LA中不存在该元素）
void mergeUnique(vector<int> &LA, const vector<int> &LB)
{
    for (int x : LB)
    {
        // 查找LA中是否存在x
        if (find(LA.begin(), LA.end(), x) == LA.end())
        {
            LA.push_back(x); // 不存在则插入
        }
    }
}

int main()
{
    // 示例用法：
    vector<int> LA = {1, 3, 5};
    vector<int> LB = {2, 3, 4, 5, 6};

    cout << "初始LA: ";
    for (int v : LA)
        cout << v << " ";
    cout << '\n';

    cout << "LB: ";
    for (int v : LB)
        cout << v << " ";
    cout << '\n';

    mergeUnique(LA, LB);

    cout << "处理后LA: ";
    for (int v : LA)
        cout << v << " ";
    cout << '\n';

    return 0;
}
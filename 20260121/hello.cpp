#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());

int partition(vector<int> &a, int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; ++j)
    {
        if (a[j] <= pivot)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quicksort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    // 随机选择枢轴并放到右端
    uniform_int_distribution<int> dist(l, r);
    swap(a[dist(rng)], a[r]);
    int p = partition(a, l, r);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        if (i)
            cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
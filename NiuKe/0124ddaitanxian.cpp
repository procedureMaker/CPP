// dd爱探险
// 包含所有标准库头文件，竞赛常用写法
#include <bits/stdc++.h>
// 使用标准命名空间，避免重复写std::
using namespace std;

// 以下宏定义为竞赛代码习惯写法，本题实际未使用ll/ull/mod
#define ll long long
#define ull unsigned long long
// 本题未使用的配对类型，代码冗余可忽略
typedef pair<int, int> pii;
typedef pair<int, char> pic;

// 常量定义：点的最大数量（状压DP适配n≤16，2^16=65536状态可控）
const int N = 16;
// 取模常量，本题未使用
const int mod = 1e9 + 7;

// 全局变量定义（竞赛中减少栈内存占用，方便大数组定义）
int n;       // 实际输入的点的数量（0~n-1编号）
int a[N][N]; // 邻接矩阵：a[k][j]表示从点k走到点j的花费
// 核心DP数组：dp[mask][u][s]，三维分别为「状态掩码」「当前终点」「优惠状态」
// 1<<N 表示所有点集状态（2^N种），N表示当前终点（0~n-1），3表示3种优惠状态
int dp[1 << N][N][3];

int main()
{
    // 第一步：输入数据
    cin >> n;                       // 读入点的数量
    for (int i = 0; i < n; i++)     // 遍历所有起点
        for (int j = 0; j < n; j++) // 遍历所有终点
            cin >> a[i][j];         // 读入从i到j的花费，填充邻接矩阵

    // 第二步：初始化DP数组
    // memset按字节赋值，0x3f对应每个字节为0x3f，int占4字节即0x3f3f3f3f（约1e9），表示无穷大（初始状态不可达）
    memset(dp, 0x3f, sizeof(dp));
    // 起点初始化：只遍历单个点i，最后停在i，优惠状态s=0（未使用、未标记），花费为0（无移动）
    for (int i = 0; i < n; i++)
        dp[1 << i][i][0] = 0;

    // 第三步：核心状压DP状态转移（三重循环：遍历所有状态→遍历当前终点→遍历前驱点）
    // 第一层循环：遍历所有可能的点集状态mask（1<<n表示2^n，即所有点都遍历的下一个状态）
    for (int mask = 1; mask < (1 << n); mask++)
    {
        // 第二层循环：遍历当前mask中所有可能的终点j（判断j是否在mask中）
        for (int j = 0; (1 << j) <= mask; j++)
        {
            // 位运算判断：若mask的第j位为0，说明j未被遍历，跳过
            if (((1 << j) & mask) == 0)
                continue;
            // 拆分状态：mask_prev = 原mask去掉点j后的状态（前驱状态，已遍历mask_prev的点，最后未到j）
            int mask_prev = (1 << j) ^ mask;
            // 第三层循环：遍历前驱状态mask_prev中所有可能的前驱点k（从k走到j）
            for (int k = 0; (1 << k) <= mask_prev; k++)
            {
                // 位运算判断：若mask_prev的第k位为0，说明k不在前驱状态中，跳过
                if (((1 << k) & mask_prev) == 0)
                    continue;

                // 状态转移1：优惠状态s=0（未使用、未标记任何路径）
                // 前驱必须也是s=0，从k到j按原价累加，更新当前最小花费
                dp[mask][j][0] = min(dp[mask][j][0], dp[mask_prev][k][0] + a[k][j]);

                // 状态转移2：优惠状态s=1（未使用优惠，但已标记某条路径待减半）
                // 两种合法前驱：1.前驱s=0（选择当前k→j为待优惠路径，直接继承花费）；2.前驱s=1（已标记，k→j按原价累加）
                // 取两种情况的最小值，更新当前s=1的最小花费
                dp[mask][j][1] = min(dp[mask][j][1], min(dp[mask_prev][k][0], dp[mask_prev][k][1] + a[k][j]));

                // 状态转移3：优惠状态s=2（已使用一次优惠，某条路径已减半）【最终需要的状态】
                // 两种合法前驱：1.前驱s=2（优惠已用，k→j按原价累加）；2.前驱s=1（执行优惠，将标记路径减半，2*a[k][j]为浮点规避写法）
                // 取两种情况的最小值，更新当前s=2的最小花费
                dp[mask][j][2] = min(dp[mask][j][2], min(dp[mask_prev][k][2] + a[k][j], dp[mask_prev][k][1] + 2 * a[k][j]));
            }
        }
    }

    // 第四步：求解最终答案
    int ans = 0x3fffffff; // 初始化答案为更大的无穷大，避免溢出
    // 最终状态：mask=(1<<n)-1（n位二进制全1，所有点都遍历完毕）、优惠状态s=2（已用优惠）
    // 遍历所有可能的最终终点i，取最小花费即为答案
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i][2]);

    // 输出答案
    cout << ans;
    return 0;
}
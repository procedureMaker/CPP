// 邮递员送信
#include <iostream> // 输入输出（cin/cout）
#include <vector>   // 存邻接表、距离数组（动态数组，不用提前定大小）
#include <queue>    // 存优先队列（小根堆）

using namespace std; // 简化代码，不用每次写std::cin、std::vector

const long long INF = 1e18; // 极大值，代表「节点初始不可达」

// 存一条有向边：起点隐含在邻接表的下标里，存终点+权重
struct Edge
{
    int to;
    int weight;
};

// 优先队列的元素：存节点编号+当前到起点的距离
struct Node
{
    int id;
    long long dist;
    // 小根堆规则：dist小的先出队（必须写const，否则编译报错）
    bool operator>(const Node &other) const
    {
        return dist > other.dist;
    }
};

/**
 * @brief 函数迪杰斯特拉
 *
 * @param n 结点数量
 * @param start_node 初始位置
 * @param adj 二维数组 引用代表函数内修改，则原来的也修改
 * @param dist 结果 引用作用同上 存「1→所有节点」的最短路 或 存「所有节点→1」的最短路（反向图1→所有节点）
 */
void dijkstra(int n, int start_node, const vector<vector<Edge>> &adj, vector<long long> &dist)
{
    // 步骤1：初始化距离数组——所有节点距离设为INF（不可达）
    dist.assign(n + 1, INF);
    // 起点到自己的距离是0（自己到自己不用走）
    dist[start_node] = 0;

    // 步骤2：初始化小根堆，把起点入队（起点编号，距离0）
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start_node, 0});

    // 步骤3：核心循环——堆不空就一直处理
    while (!pq.empty())
    {
        // 3.1 取出堆顶节点（当前距离起点最近的节点）
        Node current = pq.top();
        pq.pop();

        // 提取当前节点的编号u，和当前已知的距离d
        int u = current.id;
        long long d = current.dist;

        // 3.2 关键判断：跳过「过时的节点」（剪枝，提高效率）
        // 解释：如果堆里存的距离d，比已经确定的最短路dist[u]大，说明这个节点已经处理过了，不用再管
        if (d > dist[u])
        {
            continue;
        }

        // 3.3 遍历当前节点u的所有出边（u→v）
        for (const auto &edge : adj[u])
        {
            int v = edge.to;     // 边的终点v
            int w = edge.weight; // 边的权重w
            // 3.4 松弛操作（迪杰斯特拉的核心！）
            // 解释：如果「从起点到u的最短路 + u→v的权重」 < 「当前起点到v的已知距离」，说明找到了更短的路
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w; // 更新v的最短路为更短的距离
                pq.push({v, dist[v]}); // 把更新后的v入队，后续处理
            }
        }
    }
}

int main()
{
    // 优化cin/cout速度（大数据输入时必须加，避免超时）
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 步骤1：读入节点数n、边数m
    int n, m;
    cin >> n >> m;

    // 步骤2：初始化两个邻接表——原图adj、反向图adj_rev（节点编号1~n，所以大小n+1）
    vector<vector<Edge>> adj(n + 1);
    vector<vector<Edge>> adj_rev(n + 1);

    // 步骤3：读入m条边，构建原图和反向图
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;           // 原边：u→v，权重w
        adj[u].push_back({v, w});     // 原图：把u→v加入adj[u]
        adj_rev[v].push_back({u, w}); // 反向图：把v→u加入adj_rev[v]（边反转）
    }

    // 步骤4：定义两个距离数组，存最短路结果
    vector<long long> dist_from_1; // 存「1→所有节点」的最短路
    vector<long long> dist_to_1;   // 存「所有节点→1」的最短路（反向图1→所有节点）

    // 步骤5：两次调用迪杰斯特拉，计算最短路
    dijkstra(n, 1, adj, dist_from_1);   // 原图：起点1，求1→所有节点
    dijkstra(n, 1, adj_rev, dist_to_1); // 反向图：起点1，求1→所有节点（即原图标所有节点→1）

    // 步骤6：计算所有节点（2~n）的往返最短路总和
    long long total_time = 0;
    for (int i = 2; i <= n; ++i)
    {
        total_time += dist_from_1[i] + dist_to_1[i]; // 1→i + i→1
    }

    // 步骤7：输出最终结果
    cout << total_time << endl;

    return 0;
}
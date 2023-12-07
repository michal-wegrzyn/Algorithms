#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<int> graph[10003];
vector<int> transpose_graph[10003];
vector<int> postorder;
int scc[10003];
bitset<10003> visited;

void dfs_postorder(int v)
{
    visited[v] = true;
    for (int i : graph[v])
    {
        if (!visited[i])
            dfs_postorder(i);
    }
    postorder.push_back(v);
}

void dfs_scc(int v, int scc_num)
{
    scc[v] = scc_num;
    for (int i : transpose_graph[v])
    {
        if (!scc[i])
            dfs_scc(i, scc_num);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, num1, num2, curr_scc_num = 1;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        transpose_graph[num2].push_back(num1);
    }
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs_postorder(i);
    for (int i = postorder.size() - 1; i >= 0; i--)
    {
        if (!scc[postorder[i]])
        {
            dfs_scc(postorder[i], curr_scc_num);
            curr_scc_num++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << scc[i] << ' ';
    return 0;
}
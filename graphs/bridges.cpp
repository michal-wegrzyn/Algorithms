#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10003];
bool visited[10003];
int low[10003];
int preorder[10003];
int ttime = 0;

void bridges(int v, int parent){
    visited[v] = true;
    preorder[v] = low[v] = ++ttime;
    for(int u:graph[v]){
        if(!visited[u]){
            bridges(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] > preorder[v]) cout << v << ' ' << u << '\n';
        }
        else if(u != parent) low[v] = min(low[v], preorder[u]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++) if(!visited[i]) bridges(i, -1);
}
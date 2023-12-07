#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10003];
int lvl[10003];
int jumps[10003][15];

void DFS(int v, int prev){
    jumps[v][0] = prev;
    lvl[v] = lvl[prev]+1;
    for(int i:graph[v]) if(i != prev) DFS(i, v);
}

int lca(int x, int y){
    if(lvl[x] < lvl[y]) swap(x, y);
    for(int i=14; i>=0; i--) if(lvl[x] - (1<<i) >= lvl[y]) x = jumps[x][i];
    if(x==y) return x;
    for(int i=14; i>=0; i--) if(jumps[x][i] != jumps[y][i]){
        x = jumps[x][i];
        y = jumps[y][i];
    }
    return jumps[x][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, num1, num2;
    cin >> n >> q;
    for(int i=1; i<n; i++){
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }
    DFS(1, 1);
    for(int i=1; i<15; i++){
        for(int j=1; j<=n; j++) jumps[j][i] = jumps[jumps[j][i-1]][i-1];
    }

    for(int i=0; i<q; i++){
        cin >> num1 >> num2;
        cout << lca(num1, num2) << '\n';
    }
    return 0;
}
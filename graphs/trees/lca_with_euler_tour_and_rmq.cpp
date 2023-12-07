#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1007];
vector<int> euler_tour;
int pos[1007];
int depth[1007];

void dfs_euler_tour(int v, int p){
    pos[v] = euler_tour.size();
    euler_tour.push_back(v);
    for(int u:graph[v]){
        if(u==p) continue;
        depth[u] = depth[v]+1;
        dfs_euler_tour(u,v);
        pos[v] = euler_tour.size();
        euler_tour.push_back(v);
    }
}

int RMQ_tab[2007][12];

int lca(int a, int b){
    if(a==b) return a;
    a = pos[a]; b = pos[b];
    if(a>b) swap(a,b);
    int c = 31-__builtin_clz(b-a+1);
    if(depth[RMQ_tab[a][c]] < depth[RMQ_tab[b+1-(1<<c)][c]]) return RMQ_tab[a][c];
    return RMQ_tab[b+1-(1<<c)][c];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b; cin >> n;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs_euler_tour(1, -1);
    for(int i=0; i<2*n-1; i++) RMQ_tab[i][0] = euler_tour[i];
    // for(int i:euler_tour) cout << i << ' '; cout << '\n';
    for(int j=1; j<11; j++){
        for(int i=0; i<2*n-(1<<j); i++){
            if(depth[RMQ_tab[i][j-1]] < depth[RMQ_tab[i+(1<<(j-1))][j-1]]) RMQ_tab[i][j] = RMQ_tab[i][j-1];
            else RMQ_tab[i][j] = RMQ_tab[i+(1<<(j-1))][j-1];
            // cout << RMQ_tab[i][j] << ' ';
        }
        // cout << '\n';
    }
    int q; cin >> q;
    for(int i=0; i<q; i++){
        cin >> a >> b;
        cout << lca(a,b) << '\n';
    }
}
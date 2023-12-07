#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1007];
int subtree_size[1007];
bitset<1007> is_del;

int n;
void dfs_subtree_sizes(int v, int p){
    subtree_size[v] = 1;
    for(int u:graph[v]){
        if(u == p || is_del[u]) continue;
        dfs_subtree_sizes(u,v);
        subtree_size[v] += subtree_size[u];
    }
}

int find_centroid(int v, int p){
    for(int u:graph[v]){
        if(u==p || is_del[u]) continue;
        if(subtree_size[u]*2 == n) return u; // u and v are both centroids
        if(subtree_size[u]*2 > n) return find_centroid(u,v);
    }
    return v;
}

void centroid_decomposition(int v){
    dfs_subtree_sizes(v,-1);
    int c = find_centroid(v,-1);
    is_del[c] = true;
    // do sth
    for(int u:graph[c]){
        if(is_del[u]) continue;
        centroid_decomposition(u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    centroid_decomposition(1);
}
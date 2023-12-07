#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[1007];
int subtree_size[1007];
bitset<1007> is_del;
map<int,int> sum_count;

int n;
void dfs_subtree_sizes(int v, int p){
    subtree_size[v] = 1;
    for(auto u:graph[v]){
        if(u.second == p || is_del[u.second]) continue;
        dfs_subtree_sizes(u.second,v);
        subtree_size[v] += subtree_size[u.second];
    }
}

int find_centroid(int v, int p){
    for(auto u:graph[v]){
        if(u.second==p || is_del[u.second]) continue;
        if(subtree_size[u.second]*2 == n) return u.second; // u and v are both centroids
        if(subtree_size[u.second]*2 > n) return find_centroid(u.second,v);
    }
    return v;
}

int query_value, res;
void dfs_res(int v, int p, int curr_sum){
    res += sum_count[query_value-curr_sum];
    for(auto u:graph[v]){
        if(u.second == p || is_del[u.second]) continue;
        dfs_res(u.second, v, curr_sum+u.first);
    }
}

void dfs_upd(int v, int p, int curr_sum){
    sum_count[curr_sum]++;
    for(auto u:graph[v]){
        if(u.second == p || is_del[u.second]) continue;
        dfs_upd(u.second, v, curr_sum+u.first);
    }
}

void centroid_decomposition(int v){
    dfs_subtree_sizes(v,-1);
    int c = find_centroid(v,-1);
    is_del[c] = true;
    
    sum_count[0] = 1;
    for(auto u:graph[c]){
        if(is_del[u.second]) continue;
        dfs_res(u.second, -1, u.first);
        dfs_upd(u.second, -1, u.first);
    }
    sum_count.clear();

    for(auto u:graph[c]){
        if(is_del[u.second]) continue;
        centroid_decomposition(u.second);
    }
}

int countPathsWithGivenSum(int value){
    query_value = value;
    res = 0;
    centroid_decomposition(1);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, w;
    cin >> n >> query_value;
    for(int i=1; i<n; i++){
        cin >> a >> b >> w;
        graph[a].push_back({w,b});
        graph[b].push_back({w,a});
    }
    cout << countPathsWithGivenSum(query_value) << '\n';
}
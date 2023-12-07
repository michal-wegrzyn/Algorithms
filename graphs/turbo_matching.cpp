#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10003];
int match[10003];
bitset<10003> vis;

bool augment(int u)
{
    vis[u] = true;
    for(auto v : graph[u])
        if(match[v] == -1){ match[v] = u; match[u] = v; return true; }
    for(auto v : graph[u])
        if(!vis[match[v]] && augment(match[v])){ match[v] = u; match[u] = v; return true; }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool any;
    for(int i=0; i<n; i++) match[i] = -1;

    while(true)
    {
        vis.reset(); any = false;
        for(int u = 0; u < n; u++)
            if(match[u] == -1 && augment(u)) any = true;
        if(! any) break;
    }

    for(int i=0 ; i<n; i++) cout << match[i] << ' ';
    cout << '\n';

}
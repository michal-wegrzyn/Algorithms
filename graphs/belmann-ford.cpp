#include <bits/stdc++.h>
using namespace std;

struct edge{
    int st;
    int en;
    int wgh;
};

vector<edge> E;
int dist[1007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, w;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        E.push_back({a,b,w});
    }

    for(int i=0; i<n; i++) dist[i] = INT_MAX/2;
    dist[0] = 0;

    for(int i=0; i<n; i++){
        for(edge e:E){
            if(dist[e.en] > dist[e.st] + e.wgh){
                dist[e.en] = dist[e.st] + e.wgh;
                if(i == n-1){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for(int i=0; i<n; i++) cout << dist[i] << ' ';
}
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int, int>> graph[10003];
int deg_in[10003];
vector <int> toposort;
queue <int> q;
int dist[10003];
int inf = 2100000000;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, start, num1, num2, w;
    cin >> n >> m >> start;
    for(int i=0; i<m; i++){
        cin >> num1 >> num2 >> w;
        graph[num1].push_back(make_pair(w, num2));
        deg_in[num2]++;
    }
    for(int i=1; i<=n; i++) if(!deg_in[i]){
        q.push(i);
        toposort.push_back(i);
    }
    while(!q.empty()){
        num1 = q.front();
        q.pop();
        for(auto i:graph[num1]){
            deg_in[i.second]--;
            if(!deg_in[i.second]){
                q.push(i.second);
                toposort.push_back(i.second);
            };
        }
    }
    for(int i=1; i<=n; i++) dist[i] = inf;
    dist[start] = 0;
    for(int v:toposort) if(dist[v] != inf) for(auto u:graph[v]) if (dist[u.second] < dist[v] + u.first || dist[u.second] == inf) dist[u.second] = dist[v] + u.first;
    for(int i=1; i<=n; i++) cout << dist[i] << ' ';
    return 0;
}
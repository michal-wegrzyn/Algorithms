#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[10003];
int deg_in[10003];
vector <int> toposort;
queue <int> q;
int dist[10003];
int inf = 2100000000;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, start, num1, num2;
    cin >> n >> m >> start;
    for(int i=0; i<m; i++){
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        deg_in[num2]++;
    }
    for(int i=1; i<=n; i++) if(!deg_in[i]){
        q.push(i);
        toposort.push_back(i);
    }
    while(!q.empty()){
        num1 = q.front();
        q.pop();
        for(int i:graph[num1]){
            deg_in[i]--;
            if(!deg_in[i]){
                q.push(i);
                toposort.push_back(i);
            };
        }
    }
    for(int i=1; i<=n; i++) dist[i] = inf;
    dist[start] = 0;
    for(int v:toposort) if(dist[v] != inf) for(int u:graph[v]) if (dist[u] < dist[v] + 1 || dist[u] == inf) dist[u] = dist[v] + 1;
    for(int i=1; i<=n; i++) cout << dist[i] << ' ';
    return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[10003];
priority_queue<pair<int, int>> pq;
int dist[10003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, num1, num2, len, start;
    cin >> n >> m;
    for(int i=1; i<=n; i++) dist[i] = 2000000000;
    for(int i=0; i<m; i++){
        cin >> num1 >> num2 >> len;
        graph[num1].push_back(make_pair(len, num2));
    }
    cin >> start;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()){
        num1 = -pq.top().first; num2 = pq.top().second;
        pq.pop();
        if(num1>dist[num2]) continue;
        for(auto i:graph[num2]){
            num1 = i.second;
            if(dist[num2]+i.first < dist[num1]){
                dist[num1] = dist[num2]+i.first;
                pq.push(make_pair(-dist[num1], num1));
            }
        }
    }
    for(int i=1; i<=n; i++) cout << dist[i] << ' ';
}
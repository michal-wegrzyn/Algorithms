#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10003];
bool visited[10003];

void dfs(int v){
    visited[v] = true;
    cout << v << '\n';
    for(int i:graph[v]) if(!visited[i]) dfs(i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, num1, num2, start;
    cin >> n >> m >> start;
    for(int i=0; i<m; i++){
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
    }
    dfs(start);
    return 0;
}
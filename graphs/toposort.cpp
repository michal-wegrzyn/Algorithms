#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[10003];
int deg_in[10003];
vector <int> toposort;
queue <int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, num1, num2;
    cin >> n >> m;
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
    for(int i:toposort) cout << i << ' ';
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[100000];
int odl[100000];

int curr_peak = 0;

void BFS(int start){
    for(int i=0; i<100000; i++) odl[i] = -1;
    odl[start] = 0;
    queue <int> q;
    q.push(start);
    while(!q.empty()){
        curr_peak = q.front();
        q.pop();
        for(int i:graph[curr_peak]){
            if(odl[i] == -1){
                odl[i] = odl[curr_peak] + 1;
                q.push(i);
            }
        }
    }
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
    BFS(start);
    for(int i=1; i<=n; i++) cout << odl[i] << '\n';
}
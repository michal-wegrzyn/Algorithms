#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector <pair<int, bool>> graph[10003];
int odl[100000];

int curr_peak = 0;

void BFS_01(int start){
    for(int i=0; i<100000; i++) odl[i] = -1;
    odl[start] = 0;
    deque <int> q;
    q.push_back(start);
    while(!q.empty()){
        curr_peak = q.front();
        q.pop_front();
        for(auto i:graph[curr_peak]){
            if(odl[i.first] == -1){
                if(i.second){
                    odl[i.first] = odl[curr_peak] + 1;
                    q.push_back(i.first);
                }
                else{
                    odl[i.first] = odl[curr_peak];
                    q.push_front(i.first);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, num1, num2, start;
    bool b;
    cin >> n >> m >> start;
    for(int i=0; i<m; i++){
        cin >> num1 >> num2 >> b;
        graph[num1].push_back(make_pair(num2, b));
    }
    BFS_01(start);
    for(int i=1; i<=n; i++) cout << odl[i] << '\n';
}
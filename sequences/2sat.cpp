#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10003];
vector <int> transpose_graph[10003];
vector <int> postorder;
int scc[10003];
bool visited[10003];
bool res[5003];

void dfs_postorder(int v){
    visited[v] = true;
    for(int i:graph[v]){
        if(!visited[i]) dfs_postorder(i);
    }
    postorder.push_back(v);
}

void dfs_scc(int v, int scc_num){
    scc[v] = scc_num;
    for(int i:transpose_graph[v]){
        if(!scc[i]) dfs_scc(i, scc_num);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, mx=0; cin >> n;
    int a, sign_a, b, sign_b; // sign 1 -> negation
    for(int i=0; i<n; i++){
        cin >> sign_a >> a >> sign_b >> b;
        graph[(a<<1)+1-sign_a].push_back((b<<1)+sign_b);
        graph[(b<<1)+1-sign_b].push_back((a<<1)+sign_a);
        transpose_graph[(b<<1)+sign_b].push_back((a<<1)+1-sign_a);
        transpose_graph[(a<<1)+sign_a].push_back((b<<1)+1-sign_b);
        mx = max(mx, max(a,b));
    }
    int curr_scc_num = 1;
    for(int i=0; i<2*mx+2; i++) if(!visited[i]) dfs_postorder(i);
    for(int i=postorder.size()-1; i>=0; i--){
        if(!scc[postorder[i]]){
            dfs_scc(postorder[i], curr_scc_num);
            curr_scc_num++;
        }
    }
    for(int i=0; i<=mx; i++){
        if(scc[2*i] == scc[2*i+1]){
            cout << "Impossible\n";
            return 0;
        }
        if(scc[2*i] > scc[2*i+1]) res[i] = true;
    }
    for(int i=1; i<=mx; i++) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}
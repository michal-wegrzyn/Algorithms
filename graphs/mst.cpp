#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{
    int s;
    int v1;
    int v2;
};
edge q_mst[10003];
int it_q_mst;
vector<edge> mst_graph;
int repr[10003];
int sizes[10003];

bool sort_edge(edge a, edge b){
    return (a.s < b.s);
}

int F(int v){
    if(repr[v]==v) return v;
    return repr[v] = F(repr[v]);
}

void U(int a, int b){
    a = F(a);
    b = F(b);
    if(a==b) return;
    if(sizes[a] > sizes[b]) swap(a, b);
    repr[a] = b;
    sizes[b] += sizes[a];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, num1, num2, dist;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> num1 >> num2 >> dist;
        q_mst[it_q_mst] = {dist, num1, num2};
        it_q_mst++;
    }
    for(int i=0; i<=n; i++){
        repr[i] = i;
        sizes[i] = 1;
    }
    sort(q_mst, q_mst+m, sort_edge);
    int it_q_mst2 = 0;
    edge e;
    while(mst_graph.size()<n-1 && it_q_mst2<it_q_mst){
        e = q_mst[it_q_mst2];
        if(F(e.v1) != F(e.v2)){
            mst_graph.push_back(e);
            U(e.v1, e.v2);
        }
        it_q_mst2++;
    }
    cout << '\n';
    for(auto i:mst_graph) cout << i.s << ' ' << i.v1 << ' ' << i.v2 << '\n';
    return 0;
}
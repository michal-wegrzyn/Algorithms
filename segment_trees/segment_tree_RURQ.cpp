#include <iostream>
using namespace std;

constexpr int base = 1 << 17;
int tree[(base<<1)+7];
int lazy[(base<<1)+7];

int qstart, qend, value;

void add(int v, int v_start, int v_end){
    if(v_end<qstart || qend<v_start) return;
    else if(qstart <= v_start && v_end <= qend){
        tree[v] += (v_end-v_start+1)*value;
        lazy[v] += (v_end-v_start+1)*value;
    }
    else{
        tree[v<<1] += lazy[v]/2;
        tree[(v<<1)+1] += lazy[v]/2;
        lazy[v<<1] += lazy[v]/2;
        lazy[(v<<1)+1] += lazy[v]/2;
        lazy[v] = 0;
        add(v<<1, v_start, (v_start+v_end)>>1);
        add((v<<1)+1, ((v_start+v_end)>>1)+1, v_end);
        tree[v] = tree[v<<1] + tree[(v<<1)+1];
    }
}

int query(int v, int v_start, int v_end){
    if(v_end<qstart || qend<v_start) return 0;
    else if(qstart <= v_start && v_end <= qend) return tree[v];
    else{
        tree[v<<1] += lazy[v]/2;
        tree[(v<<1)+1] += lazy[v]/2;
        lazy[v<<1] += lazy[v]/2;
        lazy[(v<<1)+1] += lazy[v]/2;
        lazy[v] = 0;
        return query(v<<1, v_start, (v_start+v_end)>>1) + query((v<<1)+1, ((v_start+v_end)>>1)+1, v_end);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    char c;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c;
        if(c == 'Q'){
            cin >> qstart >> qend;
            cout << query(1, 0, base-1) << '\n';
        }
        else{
            cin >> qstart >> qend >> value;
            add(1, 0, base-1);
        }
    }
    return 0;
}
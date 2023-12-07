#include <bits/stdc++.h>
using namespace std;

constexpr int base = 1 << 14;
int tree[base*2+7];
int lazy[base*2+7];

vector<int> graph[10007];
int preorder[10007];
int max_subtree_preorder[10007];
int subtree_size[10007];
int tp[10007];
int parent[10007];
int depth[10007];

int q_st, q_en, q_val;
void add(int v, int v_st, int v_en){
    if(v_en < q_st || q_en < v_st) return;
    if(q_st <= v_st && v_en <= q_en){
        tree[v] += q_val*(v_en-v_st+1);
        lazy[v] += q_val;
        return;
    } 
    tree[v*2] += lazy[v]*(v_en-v_st+1)/2;
    tree[v*2+1] += lazy[v]*(v_en-v_st+1)/2;
    lazy[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
    add(v*2, v_st, (v_st+v_en)/2);
    add(v*2+1, (v_st+v_en+1)/2, v_en);
    tree[v] = tree[v*2] + tree[v*2+1];
}

int query(int v, int v_st, int v_en){
    if(v_en < q_st || q_en < v_st) return 0;
    if(q_st <= v_st && v_en <= q_en) return tree[v];
    tree[v*2] += lazy[v]*(v_en-v_st+1)/2;
    tree[v*2+1] += lazy[v]*(v_en-v_st+1)/2;
    lazy[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
    return query(v*2, v_st, (v_st+v_en)/2) + query(v*2+1, (v_st+v_en+1)/2, v_en);
}

void dfsSubtreeSizes(int v, int p){
    subtree_size[v] = 1;
    parent[v] = p;
    for(int u:graph[v]){
        if(u==p) continue;
        depth[u] = depth[v]+1;
        dfsSubtreeSizes(u,v);
        subtree_size[v] += subtree_size[u];
    }
}

int preorder_timer = 0;
void dfs_hld(int v, int p, int top){
    preorder[v] = ++preorder_timer;
    tp[v] = top;
    int hv=-1, hsz=0;
    for(int u:graph[v]){
        if(u==p) continue;
        if(subtree_size[u] > hsz){
            hsz = subtree_size[u];
            hv = u;
        }
    }
    if(hv == -1){
        max_subtree_preorder[v] = preorder_timer;
        return;
    }
    dfs_hld(hv, v, top);
    for(int u:graph[v]){
        if(u==p || u==hv) continue;
        dfs_hld(u, v, u);
    }
    max_subtree_preorder[v] = preorder_timer;
}

void addOnSubtree(int v, int value){
    q_st = preorder[v];
    q_en = max_subtree_preorder[v];
    q_val = value;
    add(1, 0, base-1);
}

int queryOnSubtree(int v){
    q_st = preorder[v];
    q_en = max_subtree_preorder[v];
    return query(1, 0, base-1);
}

void addOnPath(int a, int b, int value){
    q_val = value;
    while(tp[a] != tp[b]){
        if(depth[tp[a]] < depth[tp[b]]) swap(a,b);
        q_st = preorder[tp[a]];
        q_en = preorder[a];
        add(1, 0, base-1);
        a = parent[tp[a]];
    }
    if(depth[a] < depth[b]) swap(a, b);
    q_st = preorder[b];
    q_en = preorder[a];
    add(1,0, base-1);
}

int queryOnPath(int a, int b){
    int res = 0;
    while(tp[a] != tp[b]){
        if(depth[tp[a]] < depth[tp[b]]) swap(a,b);
        q_st = preorder[tp[a]];
        q_en = preorder[a];
        res += query(1, 0, base-1);
        a = parent[tp[a]];
    }
    if(depth[a] < depth[b]) swap(a, b);
    q_st = preorder[b];
    q_en = preorder[a];
    res += query(1,0, base-1);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n;

    for(int i=1; i<n; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfsSubtreeSizes(1,1);
    dfs_hld(1,1,1);

    for(int i=1; i<=n; i++){
        cin >> a;
        tree[preorder[i]+base] = a;
    }
    for(int i=base-1; i>0; i--) tree[i] = tree[i*2] + tree[i*2+1];

    addOnSubtree(4, 2);
    cout << queryOnSubtree(3) << '\n';
    addOnPath(2,8,6);
    cout << queryOnPath(6,5) << '\n';
}
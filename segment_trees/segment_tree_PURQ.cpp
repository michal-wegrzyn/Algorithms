#include <iostream>
using namespace std;

constexpr int base = 1 << 17;
int tree[2*base+7];

void add(int v, int value){
    v = v+base;
    tree[v] += value;
    v /= 2;
    while(v){
        tree[v] = tree[2*v]+tree[2*v+1];
        v /= 2;
    }
}

int query(int start, int end){
    int result = 0;
    start = start - 1 + base;
    end = end + 1 + base;
    while(start/2 != end/2){
        if(!(start&1)) result += tree[start+1];
        if(end&1) result += tree[end-1];
        start /= 2;
        end /= 2;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num1, num2;
    char c;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c;
        cin >> num1 >> num2;
        if(c=='Q') cout << query(num1, num2) << '\n';
        else add(num1, num2); 
    }
    
    return 0;
}
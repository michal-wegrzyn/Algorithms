#include <iostream>
using namespace std;

constexpr int base = 1 << 17;
int tree[(base<<1)+7];

void add(int start, int end, int value){
    start = start - 1 + base;
    end = end + 1 + base;
    while(start/2 != end/2){
        if(!(start&1)) tree[start+1] += value;
        if(end&1) tree[end-1] += value;
        start /= 2;
        end /= 2;
    }
}

int query(int v){
    int result = 0;
    v = v+base;
    while(v){
        result += tree[v];
        v /= 2;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num1, num2, value;
    char c;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c;
        if(c=='Q'){
            cin >> num1;
            cout << query(num1) << '\n';
        }
        else{
            cin >> num1 >> num2 >> value;
            add(num1, num2, value);
        }
    }
    
    return 0;
}
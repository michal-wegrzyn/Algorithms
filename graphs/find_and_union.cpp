#include <iostream>
using namespace std;

int repr[10003];
int sizes[10003];

int F(int a){
    if(repr[a] == a) return a;
    repr[a] = F(repr[a]);
    return repr[a];
}

void U(int a, int b){
    a = F(a);
    b = F(b);
    if(a == b) return;
    if(sizes[a] > sizes[b]) swap(a, b);
    sizes[b] += sizes[a];
    repr[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0; i<10003; i++){
        repr[i] = i;
        sizes[i] = 1;
    }
    int q, num1, num2;
    char c;
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> c >> num1 >> num2;
        if(c=='U') U(num1, num2);
        else cout << (F(num1)==F(num2)?"Y\n":"N\n");
    }
    return 0;
}
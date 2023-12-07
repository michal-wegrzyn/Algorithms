#include <iostream>
using namespace std;

long long m = (long long) 1000000007;
long long res = (long long)1;
long long mod(long long num, long long div){
    return num - num/div*div;
}

long long binary_power(long long a, long b){
    res = (long long)1;
    while(b){
        if(b&1) res = mod(res*a, m);
        a = mod(a*a, m);
        b = b >> 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin >> a >> b;
    cout << binary_power(a, b);
    return 0;
}
#include <iostream>
using namespace std;

int t[10003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, start, end, middle, value;
    cin >> n >> value;
    for(int i=0; i<n; i++) cin >> t[i];
    start = 0; end = n; middle = n>>1;
    while(start<end){
        if(t[middle] == value){cout << middle; break;}
        if(t[middle] < value) start = middle+1;
        else end = middle;
        middle = (start+end) >> 1;
    }
    return 0;
}
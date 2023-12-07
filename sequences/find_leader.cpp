#include <iostream>
using namespace std;

int sequence[10003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num, ssize = 0, candidate = -2100000000;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        sequence[i] = num;
    }
    for(int i=0; i<n; i++){
        if(ssize){
            if(candidate != sequence[i]) ssize--;
            else ssize++;
        }
        else{
            ssize = 1;
            candidate = sequence[i];
        }
    }
    if(!ssize){cout << -1; return 0;}
    ssize = 0;
    for(int i=0; i<n; i++) if(sequence[i] == candidate) ssize++;
    if(ssize>n/2) cout << candidate;
    else cout << -1;
    return 0;
}
#include <iostream>
using namespace std;

int T[10003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, curr_sum=0, sstart=0, eend = -1, sum;
    cin >> n >> sum;
    for(int i=0; i<n; i++) cin >> T[i];
    for(int i=0; i<n; i++){
        curr_sum += T[i];
        while(curr_sum > sum){
            curr_sum -= T[sstart];
            sstart++;
        }
        if(curr_sum == sum){ eend = i; break;}
    }
    if(eend!=-1) cout << sstart << ' ' << eend;
    else cout << -1;
    return 0;
}
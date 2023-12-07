#include <bits/stdc++.h>
using namespace std;

long long nums[1000007];
int nb[1000007][4];
int ind[1000007];
vector<int> ti[(1<<15)];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    long long num; 
    for(int i=0; i<n; i++){
        ind[i] = i;
        cin >> num;
        nums[i] = num;
        for(int j=0; j<4; j++){
            nb[i][j] = num - ((num>>15)<<15);
            num >>= 15;
        }
    }

    int count;
    for(int j=0; j<4; j++){
        for(int i=0; i<n; i++){
            ti[nb[ind[i]][j]].push_back(ind[i]);
        }
        count = 0;
        for(int i=0; i<(1<<15); i++){
            for(int k:ti[i]){
                ind[count] = k; count ++;
            }
            ti[i].clear();
        }
    }

    for(int i=0; i<n; i++){
        cout << nums[ind[i]] << '\n';
    }
}
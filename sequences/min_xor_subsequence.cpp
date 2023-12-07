#include <bits/stdc++.h>
using namespace std;

vector<int> layers[33];
vector<int> basis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, starting_number;
    cin >> n >> starting_number;
    for(int i=0; i<n; i++){
        cin >> a;
        layers[__builtin_clz(a)].push_back(a);
    }

    for(int i=0; i<32; i++){
        if(!layers[i].size()) continue;
        basis.push_back(layers[i].back());
        layers[i].pop_back();
        for(int j=layers[i].size()-1; j>=0; j--){
            a = (layers[i].back() ^ basis.back());
            layers[__builtin_clz(a)].push_back(a);
            layers[i].pop_back();
        }
    }
    // for(int i:basis) cout << i << ' ';
    for(int i:basis){
        if(starting_number & (1<<(31-__builtin_clz(i)))){
            starting_number ^= i;
        }
    }
    cout << starting_number << '\n';
}
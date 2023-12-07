#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_LEN = 30007;
constexpr int LOG_LEN = 15;

int id[MAX_LEN][LOG_LEN];
pair<pair<int,int>,int> id_parts[MAX_LEN];
vector<pair<pair<int,int>,int>> buckets[MAX_LEN];
int letter_id[30];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, counter;
    string s;
    cin >> s;
    n=s.size();

    for(char c:s) letter_id[c-'a'] = 1;
    for(int i=1; i<26; i++) letter_id[i] = letter_id[i-1] + letter_id[i];
    for(int i=0; i<n; i++) id[i][0] = letter_id[s[i]-'a'];
    for(int j=1; j<LOG_LEN; j++){
        for(int i=0; i<n-(1<<j)+1; i++){
            id_parts[i] = {{id[i][j-1], id[i+(1<<(j-1))][j-1]},i};
        }
        for(int i=0; i<n-(1<<j)+1; i++){
            buckets[id_parts[i].first.second].push_back(id_parts[i]);
        }
        counter = 0;
        for(int i=1; i<=n-(1<<(j-1))+1; i++){
            for(auto k:buckets[i]){
                id_parts[counter] = k;
                counter++; 
                cout << k.second << ' ';
            }
            buckets[i].clear();
        }
        cout << '\n';
        for(int i=0; i<n-(1<<j)+1; i++){
            buckets[id_parts[i].first.first].push_back(id_parts[i]);
        }
        counter = 0;
        for(int i=1; i<=n-(1<<(j-1))+1; i++){
            for(auto k:buckets[i]){
                id_parts[counter] = k;
                counter++;
                cout << k.second << ' ';
            }
            buckets[i].clear();
        }
        cout << '\n';
        counter = 1;
        id[id_parts[0].second][j] = 1;
        for(int i=1; i<n-(1<<j)+1; i++){
            if(id_parts[i].first!=id_parts[i-1].first) counter++;
            id[id_parts[i].second][j] = counter;
        }
        for(int i=0; i<n-(1<<j)+1; i++) cout << id[i][j] << ' ';
        cout << '\n';
    }
}
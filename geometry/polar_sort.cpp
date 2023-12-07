#include <bits/stdc++.h>
using namespace std;

pair<int,int> points[1007];

pair<int,int> sort_point;
int plane_part(pair<int,int> a){
    if(a.first == 0 && a.second == 0) return 0;
    if(a.second > 0) return 1;
    if(a.second < 0) return 2;
    return (a.first > 0 ? 1 : 2);
}

bool compare_points(pair<int,int> a, pair<int,int> b){
    a.first -= sort_point.first;
    a.second -= sort_point.second;
    b.first -= sort_point.first;
    b.second -= sort_point.second;
    if(plane_part(a) < plane_part(b)) return true;
    if(plane_part(a) > plane_part(b)) return false;
    if(a.first * b.second - a.second * b.first > 0) return true;
    if(a.first * b.second - a.second * b.first < 0) return false;
    return (abs(a.first) < abs(b.first));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    sort_point = {a,b};
    for(int i=0; i<n; i++){
        cin >> a >> b;
        points[i] = {a, b};
    }
    sort(points, points+n, compare_points);
    for(int i=0; i<n; i++) cout << points[i].first << ' ' << points[i].second << '\n';
}
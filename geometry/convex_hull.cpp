#include <bits/stdc++.h>
using namespace std;

pair<int,int> sort_point;
pair<int,int> points[1007];

int cross_product(pair<int,int> a, pair<int,int> b, pair<int,int> s){
    a.first -= s.first;
    a.second -= s.second;
    b.first -= s.first;
    b.second -= s.second;
    return a.first * b.second - a.second * b.first;
}

int comp_points(pair<int,int> a, pair<int,int> b){
    if(a==sort_point && b != sort_point) return true;
    return (cross_product(a,b, sort_point) > 0);
}

vector<int> convex_hull;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n;
    sort_point = {INT_MAX/4, INT_MAX/4};
    for(int i=0; i<n; i++){
        cin >> a >> b;
        points[i] = {a, b};
        if(b==sort_point.second && a < sort_point.first) sort_point = {a,b};
        if(b < sort_point.second) sort_point = {a,b};
    }

    sort(points, points+n, comp_points);

    convex_hull.push_back(0);
    convex_hull.push_back(1);
    for(int i=2; i<n; i++){
        while(cross_product(points[convex_hull.back()], points[i], points[convex_hull[convex_hull.size()-2]]) <= 0){
            convex_hull.pop_back();
            if(convex_hull.size() < 2) break;
        }
        convex_hull.push_back(i);
    }

    cout << convex_hull.size() << '\n';
    for(int i:convex_hull) cout << points[i].first << ' ' << points[i].second << '\n';
}

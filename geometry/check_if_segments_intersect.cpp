#include <bits/stdc++.h>
using namespace std;

int cross_product(pair<int,int> a, pair<int,int> b, pair<int,int> s){
    a.first -= s.first;
    b.first -= s.first;
    a.second -= s.second;
    b.second -= s.second;
    return a.first * b.second - a.second * b.first;
}

bool doSegmentsIntersect(pair<int,int> a1, pair<int,int> b1, pair<int,int> a2, pair<int,int> b2){
    int c1 = cross_product(b1,a2,a1);
    int c2 = cross_product(b2,b1,a2);
    int c3 = cross_product(a1,b2,b1);
    int c4 = cross_product(a2,a1,b2);
    if(c1>=0 && c2>=0 && c3>=0 && c4>=0) return true;
    if(c1<=0 && c2<=0 && c3<=0 && c4<=0) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x1,y1, x2,y2;
    int x3,y3, x4,y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    cout << doSegmentsIntersect({x1,y1}, {x2,y2}, {x3,y3}, {x4,y4}) << '\n';
}
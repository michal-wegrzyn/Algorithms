#include <bits/stdc++.h>
using namespace std;

pair<int, int> points[107];

int dot_product(pair<int, int> a, pair<int, int> b, pair<int, int> s)
{
    a.first -= s.first;
    a.second -= s.second;
    b.first -= s.first;
    b.second -= s.second;
    return a.first * b.second - a.second * b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, y, area = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        points[i] = {x, y};
    }
    for (int i = 1; i < n - 1; i++)
        area += dot_product(points[i], points[i + 1], points[0]);
    area = abs(area);
    cout << area / 2 << (area & 1 ? ".5" : "") << '\n';
}
#include <iostream>
#include <map>
using namespace std;

int T[10003];

pair<int, int> subArraySum(int n, int sum)
{
    map<int, int> mmap;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + T[i];
        if (curr_sum == sum)
            return {0, i};
        if (mmap.find(curr_sum - sum) != mmap.end())
            return {mmap[curr_sum - sum] + 1, i};
        mmap[curr_sum] = i;
    }
    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, sum;
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
        cin >> T[i];
    pair<int, int> res = subArraySum(n, sum);
    cout << res.first << ' ' << res.second << '\n';

    return 0;
}

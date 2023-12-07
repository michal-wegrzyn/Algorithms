#include <iostream>
using namespace std;

int T[10003];
int maxSubArraySum(int size)
{
    int res = 0, curr_res = 0;

    for (int i = 0; i < size; i++)
    {
        curr_res += T[i];

        if (res < curr_res)
            res = curr_res;

        if (curr_res < 0)
            curr_res = 0;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> T[i];
    int max_sum = maxSubArraySum(n);
    cout << max_sum << '\n';
    return 0;
}

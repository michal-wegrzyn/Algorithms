#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000007

long long powers_of_prime[1003];
long long hsh;

string text;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long prime = 29, prime_pow = 1;
    for (int i = 0; i < 1002; i++)
    {
        powers_of_prime[i] = prime_pow;
        prime_pow *= prime;
        prime_pow %= MOD;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> text;
        int s = text.size();
        hsh = 0;
        for (int i = 0; i < s; i++)
        {
            hsh += (text[i] - 'a' + 1) * powers_of_prime[i];
            hsh %= MOD;
        }
        cout << hsh << '\n';
    }
}
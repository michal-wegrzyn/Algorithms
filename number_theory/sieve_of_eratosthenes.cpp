#include <bits/stdc++.h>
#include <ios>
using namespace std;

#define SIEVE_SIZE 10000
bitset<SIEVE_SIZE> is_prime;

vector<int> primes;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    is_prime.set();
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i < SIEVE_SIZE; i++)
    {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j < SIEVE_SIZE; j += i)
            is_prime[j] = 0;
    }

    for (int i = 2; i < SIEVE_SIZE; i += 1)
        if (is_prime[i])
            primes.push_back(i);

    for (int p : primes)
        cout << p << ' ';
    cout << '\n';
}
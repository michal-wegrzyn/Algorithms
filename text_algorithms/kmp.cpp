#include <iostream>
using namespace std;

int P[10000];
string text, pattern;

void p()
{
    int M = pattern.size();
    int j = 0;
    P[0] = 0;
    for (int i = 1; i < M; i++)
    {
        while (j && pattern[j] != pattern[i])
            j = P[j - 1];
        if (pattern[j] == pattern[i])
            j++;
        P[i] = j;
    }
}

void kmp()
{
    int N = text.size();
    int M = pattern.size();
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        while (j && pattern[j] != text[i])
            j = P[j - 1];
        if (pattern[j] == text[i])
            j++;
        if (j == M)
        {
            cout << 'S' << i - M + 1 << 'K' << i << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> pattern;
    p();
    cin >> text;
    kmp();
    return 0;
}
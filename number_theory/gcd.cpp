#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num1, num2;
    cin >> num1 >> num2;
    cout << gcd(num1, num2) << '\n';
}
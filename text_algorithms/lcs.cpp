#include <iostream>
using namespace std;
  
int max(int a, int b){
    return (a>b?a:b);
}

int LCS[2][10003];
char lcs_string[10003];
int lcs(string X, string Y){
    int m = X.size();
    int n = Y.size();
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) LCS[0][0] = 0;
            else if (X[i-1] == Y[j-1]) LCS[i&1][j] = LCS[(i-1)&1][j - 1] + 1;
            else LCS[i&1][j] = max(LCS[(i-1)&1][j], LCS[i&1][j - 1]);
        }
    }
    // To cout lcs string
    int index = LCS[m&1][n];
    lcs_string[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0){
        if (X[i-1] == Y[j-1]){
            lcs_string[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if (LCS[(i-1)&1][j] > LCS[i&1][j-1]) i--;
        else j--;
    }
    cout << lcs_string << '\n';
    return LCS[m&1][n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string x;
    string y;
    cin >> x;
    cin >> y;
    cout << lcs(x, y);
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int dp[10003][10003];
string str1, str2;

int minDis(int n, int m){
    if(n==0) return m;	
    if(m==0) return n;
    if(dp[n][m]!=-1) return dp[n][m];

    if(str1[n-1]==str2[m-1]){		
	    if(dp[n-1][m-1]==-1) return dp[n][m] = minDis(n-1, m-1);
	    else return dp[n][m] = dp[n-1][m-1];
	}	
    else{		
	    int m1, m2, m3;
	    if(dp[n-1][m]!=-1) m1 = dp[n-1][m];		
	    else m1 = minDis(n-1, m);
	    if(dp[n][m-1]!=-1) m2 = dp[n][m-1];	
	    else m2 = minDis(n, m-1);
	    if(dp[n-1][m-1]!=-1) m3 = dp[n-1][m-1];
	    else m3 = minDis(n-1, m-1);
	    return dp[n][m] = 1+min(m1, min(m2, m3));	
    }

}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str1 >> str2;
	
    int n = str1.length();
    int m = str2.length();
    
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m; j++) dp[i][j] = -1;
    }
				
    cout << minDis(n, m);
    return 0;
	
}
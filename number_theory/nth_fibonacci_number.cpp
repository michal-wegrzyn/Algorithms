#include <iostream>
using namespace std;

long long matrix[30][2][2];
long long mod(long long num){
    return num - num/1000000007*1000000007;
}

long long result_matrix[2][2];
long long result_copy[2][2];
void multiple(int n){
    result_copy[0][0] = mod(matrix[n][0][0]*result_matrix[0][0]+matrix[n][0][1]*result_matrix[1][0]);
    result_copy[0][1] = mod(matrix[n][0][0]*result_matrix[0][1]+matrix[n][0][1]*result_matrix[1][1]);
    result_copy[1][0] = mod(matrix[n][1][0]*result_matrix[0][0]+matrix[n][1][1]*result_matrix[1][0]);
    result_copy[1][1] = mod(matrix[n][1][0]*result_matrix[0][1]+matrix[n][1][1]*result_matrix[1][1]);
    result_matrix[0][0] = result_copy[0][0];
    result_matrix[0][1] = result_copy[0][1];
    result_matrix[1][0] = result_copy[1][0];
    result_matrix[1][1] = result_copy[1][1];
}

long long nth_fibonacci_number(int n){
    result_matrix[0][0] = 0;
    result_matrix[0][1] = 1;
    result_matrix[1][0] = 1;
    result_matrix[1][1] = 0;
    for(int i=0; n; i++, n>>=1) if(n&1){
        multiple(i);
    }
    return result_matrix[1][1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    matrix[0][0][0] = 0;
    matrix[0][0][1] = 1;
    matrix[0][1][0] = 1;
    matrix[0][1][1] = 1;
    for(int i=1; i<30; i++){
        matrix[i][0][0] = mod(matrix[i-1][0][0]*matrix[i-1][0][0]+matrix[i-1][0][1]*matrix[i-1][1][0]);
        matrix[i][0][1] = mod(matrix[i-1][0][0]*matrix[i-1][0][1]+matrix[i-1][0][1]*matrix[i-1][1][1]);
        matrix[i][1][0] = mod(matrix[i-1][1][0]*matrix[i-1][0][0]+matrix[i-1][1][1]*matrix[i-1][1][0]);
        matrix[i][1][1] = mod(matrix[i-1][1][0]*matrix[i-1][0][1]+matrix[i-1][1][1]*matrix[i-1][1][1]);
    }
    int q, num;
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> num;
        cout << nth_fibonacci_number(num) << '\n';
    }
    return 0;
}
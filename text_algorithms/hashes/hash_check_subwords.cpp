#include <iostream>
#include <string>
using namespace std;

long long powers_of_prime[1003];
long long hsh[1003];
long long prime1 = 1000000007, prime2 = 1000000321;

string text;

long long mod(long long num, long long p){
    if(num>=0) return num - num/p*p;
    else return num - (num+1)/p*p + p;
}

long long char_to_num(char c){
    return (long long)c - 96;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long mod_prime = 1000000007, prime = 29, aux_var = 1, prev = 0;
    char aux_c;
    for(int i=0; i<1002; i++){
        powers_of_prime[i] = aux_var;
        aux_var *= prime;
        aux_var = mod(aux_var, mod_prime);
    }

    cin >> text;
    int s = text.size();
    for(int i=0; i<s; i++){
        aux_c = text[i];
        hsh[i] = char_to_num(aux_c)*powers_of_prime[i]+prev;
        hsh[i] = mod(hsh[i], mod_prime);
        prev = hsh[i];
    }
    int s1, s2, e1, e2;
    long long hsh1, hsh2;
    cin >> s1 >> e1 >> s2 >> e2;
    if(e1-s1 != e2-s2) cout << 'N';
    else{
        hsh1 = hsh[e1];
        if(s1) hsh1 -= hsh[s1-1];
        hsh2 = hsh[e2];
        if(s2) hsh2 -= hsh[s2-1];
        if(s1<s2){
            hsh1 *= powers_of_prime[s2-s1];
            hsh1 = mod(hsh1, mod_prime);
        }
        if(s2<s1){
            hsh2 *= powers_of_prime[s1-s2];
            hsh2 = mod(hsh2, mod_prime);
        }
        if(hsh1==hsh2) cout << 'Y';
        else cout << 'N';
    }
}
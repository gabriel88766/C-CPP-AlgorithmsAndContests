//WA

#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353;

long long binpow(long long int a, long long int b, long long int m = mod){
    if(a == 0 && b != 0) return 0;
    a %= m;
    long long int res = 1;
    while(b > 0){
        if(b & 1) 
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

long long divi(long long int a, long long int b, long long int m = mod){
    long long inv = binpow(b, m-2);
    return (a * inv) % m;
}

long long solve(long long n, long long k, long long m){
    int i = 0;
    long long res = 0, k_bin = 1, m_bin = 1, cur;
    while((i <= k) && (i < m)){
        if(i != 0){
            k_bin = (k_bin * (k - i + 1)) % mod;
            k_bin = divi(k_bin, i);
            m_bin = (m_bin * (m - i + 1)) % mod;
            m_bin = divi(m_bin, i);
        }
        cur = (k_bin * m_bin) % mod;
        cur = cur * binpow(m - i, n - k - i) % mod;
        cur = cur * binpow(m - i - 1, k - i) % mod;
        res = (res + cur) % mod;
        i++;
    }
    return res;
}


//inv, if m = prime, and division, 4/3 = 4 * inv 3 mod p
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k = 0;
    long long int sum = 0;
    cin >> n >> m;
    vector<long long int> v(n);
    for(int i=0;i<n;i++){ 
        cin >> v[i];
        sum += v[i];
    }
    if(n == 1) cout << m;
    else if(n == 2) cout << (m * m) % mod;
    else {
        if((sum % 2) == 0) {
            sum /= 2;
            int pi = 0, pf = 0;
            long long cursum = 0;
            while(pf < n){
                if(cursum < sum){
                    cursum += v[pf];
                    pf++;
                    if(cursum == sum){
                        k++;
                        cursum -= v[pi];
                        pi++;
                    }
                }else{
                    cursum -= v[pi];
                    pi++;
                    if(cursum == sum){
                        k++;
                        cursum -= v[pi];
                        pi++;
                    }
                }
            }
        }

        cout << solve(n, k ,m);
    }
}
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


//FOR DIVISORS, MULTIPLES
vector<ll> pr;
void sieve(int n){
    vector<bool> p(n+1, false);
    pr.clear();
    for(ll i=2; i<=n; i++){
        if(!p[i]){
            for(ll j = i*i; j <= n; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
}


//multiple is inverse and also invert order.
template<typename T>
void DivisorZetaTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
    sieve(n);
	for (auto p : pr) {
		for (int i = 1; i * p <= n; i++){
			v[i * p] += v[i];
            v[i * p] %= MOD;
        }
	}
}

template<typename T>
void DivisorMobiusTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
    sieve(n);
	for (auto p : pr) {
		for (int i = n / p; i; i--){
			v[i * p] -= v[i];
            v[i * p] %= MOD;
        }
    }
}


template<typename T>
vector<T> LCMConvolution(vector<T> A, vector<T> B) {
    DivisorZetaTransform(A);
    DivisorZetaTransform(B);
    for (int i = 0; i < A.size(); i++) A[i] = (A[i] * B[i]) % MOD;
    DivisorMobiusTransform(A);
    return A;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    sieve(n);
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    auto ans = LCMConvolution(a, b);
    for(int i=1;i<=n;i++){
        ll x = ans[i];
        if(x < 0) x += MOD;
        cout << x << " ";
    }
    cout << "\n";
}

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T>
void SupersetZetaTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i ^ j] += v[i]; 
	}
    for(int i=0;i<n;i++) v[i] %= MOD;
}

template<typename T>
void SupersetMobiusTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i ^ j] -= v[i]; 
	}
    for(int i=0;i<n;i++){
        v[i] %= MOD;
        if(v[i] < 0) v[i] += MOD;
    }
}

template<typename T>
vector<T> AndConvolution(vector<T> A, vector<T> B) {
	SupersetZetaTransform(A);
	SupersetZetaTransform(B);
	for (int i = 0; i < A.size(); i++) A[i] = (A[i] * B[i]) % MOD;
	SupersetMobiusTransform(A);
	return A;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> a(1 << n), b(1 << n);
    for(int i=0;i<a.size();i++) cin >> a[i];
    for(int i=0;i<b.size();i++) cin >> b[i];
    auto ans = AndConvolution(a, b);
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}

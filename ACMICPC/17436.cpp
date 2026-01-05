//OVERALL O(n * 2^n)
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//g[a] = sum f[b] zeta(b, a);
//zeta(b, a) = 1 if b <= a, 0 otherwise.
template<typename T>
void SubsetZetaTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i] += v[i ^ j]; //invert if superset to v[i ^ j] += v[i];
	}
}

//f[a] = sum g[b] mi(b, a);
//mi(b, a) = (-1)^|a-b| (if b <= a)
template<typename T>
void SubsetMobiusTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i] -= v[i ^ j]; //invert if superset to v[i ^ j] -= v[i];
	}
}


template<typename T>
void SupersetMobiusTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i ^ j] -= v[i]; //invert if superset to v[i ^ j] -= v[i];
	}
}


ll g[1 << 10];
ll f[1 << 10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<ll> g(1 << n);
    for(int i=0;i<(1 << n);i++){
        ll prd = 1;
        for(int j=0;j<n;j++){
            if(i & (1 << j)) prd *= v[j];
        }
        g[i] = m / prd;
    }
    //without SOS
    ll ans = 0;
    // for(int s=0;s<(1<<n);s++){
    //     for(int t=0;t<(1 << n);t++){ 
    //         //s in t, then f[s] += g[t] * (-1)^|t-s|
    //         if((s & t) == s){
    //             if(__builtin_popcount(s^t) % 2) f[s] -= g[t];
    //             else f[s] += g[t];
    //         }
    //     }
    //     if(__builtin_popcount(s) >= 1) ans += f[s];
    // }
    // cout << ans << "\n";
    //with SOS
    //s in t, then f[s] += g[t] * (-1)^|t-s|
    //clearly mi transform
    //but sum is over supersets;
    SupersetMobiusTransform(g);
    for(int s=1;s<(1<<n);s++){
        ans += g[s];
    }
    cout << ans << "\n";
}

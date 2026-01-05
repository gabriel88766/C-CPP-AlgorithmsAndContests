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
void SupersetZetaTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i ^ j] += v[i]; //invert if superset to v[i ^ j] += v[i];
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


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<ll> fi(1 << 20);
    for(int i=0;i<n;i++) fi[v[i]]++;
    auto f1 = fi;
    auto f2 = fi;
    //x | y = x, count subsetzeta of x, y in x
    SubsetZetaTransform(f1);
    //x & y = x, count supersetzeta of x, x in y
    SupersetZetaTransform(f2);
    //x & y = 0 => ~x | y = ~x, n - count subsetzeta of ~x
    int msk = (1 << 20) - 1;
    for(int i=0;i<n;i++){
        cout << f1[v[i]] << " " << f2[v[i]] << " " << n-f1[msk^v[i]] << "\n";
    }
}

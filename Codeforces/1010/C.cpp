#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    set<int> pos;
    int k;
    cin >> n >> k;
    int minv = k;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        aux %= k;
        minv = min(minv, __gcd(minv, aux));
    }
    cout << k/minv << "\n";
    for(int i=0;i<=k;i++){
        if(i*minv >= k) break;
        cout << i*minv << " ";
    }
}

#include <bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    vector<int> isl(m);
    for(int i=0;i<m;i++){
        cin >> isl[i];
    }
    vector<ll> ps(n+1, 0);
    for(int i=1;i<m;i++){
        int a = isl[i-1], b = isl[i];
        if(a > b) swap(a, b);
        int d1 = b - a;
        int d2 = n - d1;
        //if closed is from a to b-1, then d2, else d1
        ps[1] += d1;
        ps[a] += d2 - d1;
        ps[b] += d1 - d2;
    }
    ll minv = INF_LL;
    for(int i=1;i<=n;i++){
        ps[i] += ps[i-1];
        minv = min(minv, ps[i]);
    }
    cout << minv << "\n";
}

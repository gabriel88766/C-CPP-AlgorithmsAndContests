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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> av(n+1);
    for(int i=1;i<=n;i++){
        cin >> av[i];
    }
    ll lo = 1, hi = 1e9;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1) / 2;
        ll aa = 0, sb = 0;  
        for(int i=1;i<=n;i++){
            if(av[i] >= mid) sb += (av[i] - mid) / b;
            else aa += (mid - av[i] + a - 1) / a;
        }
        if(aa <= sb) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}

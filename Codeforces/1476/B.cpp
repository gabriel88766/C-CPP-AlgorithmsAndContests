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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> p(n);
        for(int i=0;i<n;i++) cin >> p[i];
        ll lo = 0, hi = 1e15;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll sum = mid + p[0];
            bool ok = true;
            for(int i=1;i<n;i++){
                if(100 * p[i] > sum * k) ok = false;
                sum += p[i];
            }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}

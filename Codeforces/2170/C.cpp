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
        ll n, k;
        cin >> n >> k;
        vector<ll> q(n), r(n);
        for(int i=0;i<n;i++) cin >> q[i];
        for(int i=0;i<n;i++) cin >> r[i];
        sort(q.begin(), q.end());
        sort(r.begin(), r.end());
        int lo = 0, hi = n;
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            bool ok = true;
            for(int i=0;i<mid;i++){
                if(q[mid - i - 1] * (r[i] + 1) + r[i] > k) ok = false;
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}

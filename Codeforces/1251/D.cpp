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
        ll n, s;
        cin >> n >> s;
        vector<pair<ll, ll>> vp(n+1);
        ll S = 0;
        for(int i=1;i<=n;i++){
            int a, b;
            cin >> a >> b;
            vp[i] = {a, b};
            S += a;
        }
        sort(vp.begin(), vp.end());
        int lo = 1, hi = 1e9;
        int hf = (n+1) / 2;
        while(lo != hi){    
            int mid = lo + (hi - lo + 1)/2;
            int r = n;
            int tt = 0;
            while(vp[r].first >= mid) r--, tt++;
            if(tt >= hf) lo = mid;
            else{
                ll curs = S;
                bool ok = true;
                for(int i=r;i>=0;i--){
                    if(tt >= hf) break;
                    if(vp[i].second < mid) continue;
                    else{
                        curs += mid - vp[i].first;
                        tt++;
                    }
                }
                if(curs <= s && tt == hf) lo = mid;
                else hi = mid - 1;
            }
        }
        cout << lo << "\n";
    }
}

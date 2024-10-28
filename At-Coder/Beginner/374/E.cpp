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
        int n, x;
        cin >> n >> x;
        vector<ll> a(n), b(n), p(n), q(n), lc(n);
        for(int i=0;i<n;i++){
            cin >> a[i] >> p[i] >> b[i] >> q[i];
            lc[i] = a[i] * b[i];
        }
        ll lo = 0, hi = 1'000'000'001;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            ll pr = 0;
            //pr is the price to make min = mid
            for(int i=0;i<n;i++){
                ll qq = mid / lc[i];
                ll r = mid % lc[i];
                ll cur = INF_LL;
                for(int j=0;j<=max(a[i], b[i]);j++){
                    ll mb  = mid - j * a[i];
                    mb = max((mb + b[i] - 1) / b[i], 0LL);
                    cur = min(cur, p[i] * j + q[i] * mb);
                }
                for(int j=0;j<=max(a[i], b[i]);j++){
                    ll ma  = mid - j * b[i];
                    ma = max((ma + a[i] - 1) / a[i], 0LL);
                    cur = min(cur, p[i] * ma + q[i] * j);
                }
                pr += cur;
            }
            if(pr <= x) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }

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
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<pair<int, int>> vs(n);
    for(int i=0;i<n;i++) cin >> vs[i].first >> vs[i].second;
    vector<int> gs(k);
    for(int i=0;i<k;i++) cin >> gs[i];
    sort(gs.begin(), gs.end());
    gs.push_back(s);
    if(t < s) cout << "-1\n"; //not even possible.
    else{
        ll lo = 0, hi = 2 * s;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll tt = 0;
            int pl = 0;
            for(auto x : gs){
                if(mid < x - pl){
                    tt = t + 1; //impossible to reach, exiting
                    break;
                }else{
                    //2*a + b <= mid
                    //a + b = x - pl
                    //tt += 2*b + a;
                    if(2 * (x - pl) <= mid) tt += x - pl;
                    else{
                        ll a = mid - (x - pl);
                        ll b = (x - pl) - a;
                        assert(a >= 0 && b >= 0);
                        tt += 2 * b + a;
                    }
                    pl = x;
                }
            }
            if(tt <= t) hi = mid;
            else lo = mid + 1;
        }
        int bst = INF_INT;
        for(auto [a, b] : vs){
            if(b >= lo) bst = min(bst, a);
        }
        if(bst == INF_INT) cout << "-1\n";
        else cout << bst << "\n";
    }
}

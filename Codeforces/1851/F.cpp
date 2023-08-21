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
        bool rep = false;
        int ind;
        vector<pair<int,int>> vp(n+1);
        for(int i=1;i<=n;i++){
            cin >> vp[i].first;
            vp[i].second = i;
        }
        sort(vp.begin()+1, vp.end());
        for(int i=1;i<=n-1;i++){
            if(vp[i].first == vp[i+1].first){
                rep = true;
                ind = i;
                break;
            }
        }
        if(rep){
            cout << vp[ind].second << " " << vp[ind+1].second << " " << (((1 << k)-1)^vp[ind].first) << "\n";
        }else{
            set<int> s;
            for(int i=1;i<=n;i++) s.insert(vp[i].first);
            int best = (1 << k), ix, iy, ii;
            for(int i=1;i<=n;i++){
                //test for i
                s.erase(vp[i].first);
                int lo = 0, hi = (1 << k)-1;
                for(int j = k-1;j>=0;j--){
                    int m = 1 << j;
                    bool pmore = false;
                    if(vp[i].first & m) pmore = true;
                    bool ok = true;
                    if(pmore){
                        int nlo = lo+m;
                        auto x = s.lower_bound(nlo);
                        if(x == s.end() || *x > hi ) ok = false;
                    }else{
                        int nhi = hi-m;
                        auto x = s.lower_bound(lo);
                        if(x == s.end() || *x > nhi) ok = false;
                    }
                    if(ok^pmore) hi-=m;
                    else lo+=m;
                }
                if((lo^vp[i].first) < best){
                    best = lo^vp[i].first;
                    ix = vp[i].second;
                    iy = lower_bound(vp.begin(), vp.end(), make_pair(lo, 0))->second;
                    ii = i;
                }
                s.insert(vp[i].first);
            }
            cout << ix << " " << iy << " " << (vp[ii].first^((1<<k)-1)) << "\n";
        }
    }
}

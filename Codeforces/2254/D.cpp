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
        int n;
        cin >> n;
        vector<ll> bv(n+1);
        map<ll, vector<int>> mp;
        for(int i=1;i<=n;i++){
            cin >> bv[i];
            mp[bv[i]].push_back(i);
        }
        vector<ll> ans(n+1);
        bool ok = true;
        ll lx = 0;
        for(auto it = mp.begin(); ; ++it){
            if(it == mp.begin()){
                if(it->first != 0){
                    ok = false;
                    break;
                }
                continue;
            }
            auto pr = prev(it);
            auto &[vp, vecp] = *pr;
            // auto &[v, vec] = *it;
            int sz = vecp.size();
            if(it != mp.end()){
                auto &[v, vec] = *it;
                ll x = v - vp;
                if(x % sz != 0 || x / sz <= lx){
                    ok = false;
                    break;
                }
                x /= sz;
                for(auto &j : vecp){
                    ans[j] = x;
                }
                lx = x;
            }else{
                for(auto &j : vecp){
                    ans[j] = lx + 1;
                }
                break;
            }
        }
        if(ok){
            for(int i=1;i<=n;i++){
                cout << ans[i] << " ";
            }   
            cout << "\n";
        }else cout << "-1\n";
    }
}

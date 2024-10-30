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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<tuple<ll,ll,ll>> vq(q+1);
    vector<int> qq;
    vector<bool> ans(q+1);
    for(int i=1;i<=q;i++){
        ll l, r, x;
        cin >> l >> r >> x;
        vq[i] = {l, r, x};
        qq.push_back(i);
    }
    function<void(int,int,vector<int>)> dc = [&](int l, int r, vector<int> qq){
        if(l == r){
            for(auto x : qq){
                auto [ll, rr, c] = vq[x];
                ans[x] = (c == a[ll]);
            }
            return;
        }
        if(qq.size() == 0) return;
        int m = (l + r) / 2;
        vector<int> ql, qr, qc;
        for(auto x : qq){
            auto [ll, rr, c] = vq[x];
            if(ll > m) qr.push_back(x);
            else if(rr <= m) ql.push_back(x);
            else qc.push_back(x);
        }
        dc(l, m, ql);
        dc(m+1, r, qr);
        //make basis
        vector<ll> cb(64, 0);
        vector<int> br, bl;
        for(int i=m+1;i<=r;i++){
            ll cur = a[i];
            while(cur && cb[__builtin_clzll(cur)]){
                cur ^= cb[__builtin_clzll(cur)];
            }
            if(cur){
                cb[__builtin_clzll(cur)] = cur;
                br.push_back(i);
            }
        }
        cb.assign(64, 0);
        for(int i=m;i>=l;i--){
            ll cur = a[i];
            while(cur && cb[__builtin_clzll(cur)]){
                cur ^= cb[__builtin_clzll(cur)];
            }
            if(cur){
                cb[__builtin_clzll(cur)] = cur;
                bl.push_back(i);
            }
        }
        for(auto x : qc){
            auto [cl, cr, c] = vq[x];
            int p = 0;
            vector<ll> cb(64, 0);
            while(p < br.size() && br[p] <= cr){
                ll cur = a[br[p]];
                while(cur && cb[__builtin_clzll(cur)]){
                    cur ^= cb[__builtin_clzll(cur)];
                }
                if(cur){
                    cb[__builtin_clzll(cur)] = cur;
                }
                p++;
            }
            p = 0;
            while(p < bl.size() && bl[p] >= cl){
                ll cur = a[bl[p]];
                while(cur && cb[__builtin_clzll(cur)]){
                    cur ^= cb[__builtin_clzll(cur)];
                }
                if(cur){
                    cb[__builtin_clzll(cur)] = cur;
                }
                p++;
            }
            while(c && cb[__builtin_clzll(c)]){
                c ^= cb[__builtin_clzll(c)];
            }
            ans[x] = (c == 0);
        }
    };
    dc(1, n, qq);
    for(int i=1;i<=q;i++){
        if(ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}

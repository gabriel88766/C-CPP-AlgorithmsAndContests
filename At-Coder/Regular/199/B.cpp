#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt = 0;
ll basis[64];
vector<ll> idx, rvx, vb, rmsk;
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
        idx.clear();
        rvx.clear();
        vb.clear();
        rmsk.clear();
        for(int j=0;j<64;j++) basis[j] = 0;
        vector<ll> vx(n+1);
        vector<int> ob;
        for(int i=1;i<=n;i++){
            cin >> vx[i];
            ll val = vx[i];
            while(val && basis[__builtin_clzll(val)]){
                val ^= basis[__builtin_clzll(val)];
            }
            if(val != 0){
                basis[__builtin_clzll(val)] = val;
                idx.push_back(i); 
                rvx.push_back(vx[i]);
                vb.push_back(val);
            }else ob.push_back(i);
        }
        for(int j=0;j<idx.size();j++){
            ll msk = 1LL << j;
            bool ok = true;
            ll aux = rvx[j];
            while(ok){
                ok = false;
                for(int u=0;u<j;u++){
                    if(__builtin_clzll(vb[u]) == __builtin_clzll(aux)){
                        aux ^= vb[u];
                        msk ^= rmsk[u];
                        ok = true;
                        break;
                    }
                }
            }
            rmsk.push_back(msk);
        }
        ll x = k;
        while(x && basis[__builtin_clzll(x)]){
            x ^= basis[__builtin_clzll(x)];
        }
        if(k == 0) cout << "Yes\n2\n1 1\n";
        else if(x == 0){
            vector<int> ao, ae;
            for(int i=1;i<=n;i++){
                if(i % 2) ao.push_back(i);
                else ae.push_back(i);
            }
            auto getnd = [&](ll k){
                ll x = k;
                ll msk = 0;
                while(x && basis[__builtin_clzll(x)]){
                    for(int j=0;j<vb.size();j++){
                        if(vb[j] == basis[__builtin_clzll(x)]){
                            msk ^= rmsk[j];
                            break;
                        }
                    }
                    x ^= basis[__builtin_clzll(x)];
                }
                assert(x == 0);
                vector<int> nd;
                for(int j=0;j<64;j++){
                    if(msk & (1LL << j)) nd.push_back(idx[j]);
                }
                x = 0;
                for(auto j : nd) x ^= vx[j];
                assert(x == k);
                return nd;
            };
            bool isp = false;
            vector<int> gs;
            for(int i=0;i<=2;i++){
                ll x = k;
                int aux = i, aux2 = 0;
                vector<ll> sp;
                while(aux){
                    if(aux & 1){
                        if(aux2 < ob.size()){
                            sp.push_back(ob[aux2]);
                            x ^= vx[ob[aux2]]; 
                        }else break;
                    }
                    aux /= 2;
                    aux2++;
                }    
                gs = getnd(x);
                for(auto x : sp) gs.push_back(x);
                sort(gs.begin(), gs.end());
                if(gs != ae && gs != ao){
                    isp = true;
                    break;
                }
            }
            ll cur = 0;
            for(auto x : gs){
                cur ^= vx[x];
            }
            // assert(cur == k);

            if(isp){
                cout << "Yes\n";
                // for(auto x : gs) cout << x << " ";
                //find 2 adjacent 0 or 2 ajacent 1
                vector<bool> in(n+1);
                for(auto x : gs) in[x] = true;
                int ux = -1;
                for(int i=1;i<n;i++){
                    if(in[i] && in[i+1]){
                        ux = i;
                        break;
                    }else if(in[i] == false && in[i+1] == false){
                        ux = i;
                        break;
                    }
                }
                assert(ux != -1);
                vector<int> ans;
                if(in[ux] == true){
                    if(ux == 1){
                        //easy to solve! :)
                        if(in[3]){
                            ans.push_back(2);
                            ans.push_back(1);
                            in[3] = in[2] = false;
                        }else{
                            ans.push_back(1);
                            in[2] = false;
                        }
                        ux = 2;
                    }else{
                        assert(!in[ux-1]);
                        ans.push_back(ux);
                        in[ux] = false;
                        ux--;
                    }
                }
                ans.push_back(ux);
                ans.push_back(ux);
                //bring all from 1 to ux-1 to ux + 1
                for(int j=ux-1;j>=1;j--){
                    if(in[j]){
                        for(int k=j;k<=ux;k++){
                            ans.push_back(k);
                        }
                        for(int k=j;k<ux;k++){
                            ans.push_back(k);
                            ans.push_back(k);
                        }
                    }else{
                        ans.push_back(j);
                        ans.push_back(j);
                    }
                }
                //bring ux+1 to 1
                for(int j=ux;j>=1;j--) ans.push_back(j);
                for(int j=3;j<=ux+1;j++){
                    ans.push_back(j-1);
                    ans.push_back(j-1);
                }
                for(int j=ux+2;j<=n;j++){
                    if(in[j]){
                        for(int k=j-1;k>=1;k--) ans.push_back(k);
                        for(int k=j-1;k>=2;k--){
                            ans.push_back(k);
                            ans.push_back(k);
                        }
                    }else{
                        ans.push_back(j-1);
                        ans.push_back(j-1);
                    }
                }
                cout << ans.size() << "\n";
                for(auto x : ans) cout << x << " ";
                cout << "\n";
                for(auto x : ans){
                    ll val = vx[x] ^ vx[x+1];
                    vx[x] = vx[x+1] = val;
                }
                // assert(vx[1] == k);
            }else cout << "No\n";
        }else cout << "No\n";

    }
}

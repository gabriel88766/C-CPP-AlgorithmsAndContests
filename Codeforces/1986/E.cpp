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
        map<int, vector<int>> vk;
        for(int i=1;i<=n;i++){
            int x;
             cin >> x;
             vk[x % k].push_back(x);
        }
        for(auto &[cg, v] : vk){
            sort(v.begin(), v.end());
        }
        bool ok = true;
        ll ans = 0;
        int x = 0;
        for(auto [cg, v] : vk){
            if(v.size() % 2) x++;
        }
        if(x >= 2) ok = false;
        if(ok){
            for(auto [cg, v] : vk){
                if(v.size() % 2){
                    if(v.size() == 1) continue;
                    ll bst = INF_LL;
                    vector<ll> ps1(v.size()+1), ps2(v.size()+1);
                    for(int i=1;i<v.size();i+=2){
                        ps1[i] = (v[i]-v[i-1])/k;
                        if(i > 1) ps1[i] += ps1[i-2];
                        ps1[i-1] = INF_LL;
                    }
                    for(int i=v.size()-2;i>=0;i-=2){
                        ps2[i] = ps2[i+2] + (v[i+1] - v[i])/k;
                        ps2[i+1] = INF_LL;
                    }
                    for(int i=0;i<v.size();i++){
                        if(i % 2){
                            ll cur = i > 1 ? ps1[i-2] : 0;
                            ll cur2 = i < v.size() - 1 ? ps2[i+2] : 0;
                            bst = min(bst, cur + cur2 + (v[i+1]-v[i-1])/k);
                        }else{
                            ll cur = i > 0 ? ps1[i-1] : 0;
                            ll cur2 = i < v.size() ? ps2[i+1] : 0;
                            bst = min(bst, cur + cur2);
                        }
                    }
                    ans += bst;
                }else{
                    for(int i=0;i<v.size();i+=2) ans += (v[i+1]-v[i])/k;
                }
            }
            cout << ans << "\n";
        }else cout << "-1\n";
    }
}

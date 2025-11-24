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
        int n, q;
        cin >> n >> q;
        vector<int> v(n+1);
        vector<int> cnt2(n+1);
        vector<bool> usd(n+1, false);
        map<int, int> mp;
        vector<int> g1000;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            mp[v[i]]++;
        }
        vector<int> rv(n+1);
        map<int, int> ord;
        int p = 0;
        for(auto [k, val] : mp){
            ord[k] = p++;
            if(val > 1000){
                g1000.push_back(k);
            }
        }
        for(int i=1;i<=n;i++){
            rv[i] = ord[v[i]];
        }
        sort(g1000.begin(), g1000.end()); //at most 199. size 199 * 200001 * 4 = 160MB
        vector<vector<int>> cnt(n+1, vector<int>(g1000.size()));
        for(int i=1;i<=n;i++){
            for(int j=0;j<g1000.size();j++){
                cnt[i][j] = cnt[i-1][j];
            }
            auto it = lower_bound(g1000.begin(), g1000.end(), v[i]);
            if(it != g1000.end() && *it == v[i]){
                cnt[i][it - g1000.begin()]++;
            }
        }

        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            if(r - l + 1 <= 3000){
                //then bruteforce
                for(int j = l; j <= r; j++){
                    cnt2[rv[j]]++;
                }
                vector<int> ans;
                for(int j = l; j <= r; j++){
                    if(cnt2[rv[j]] > (r - l + 1) / 3){
                        if(!usd[rv[j]]){
                            usd[rv[j]] = true;
                            ans.push_back(v[j]);
                        }
                    }
                }
                sort(ans.begin(), ans.end());
                if(ans.size()){
                    for(auto x : ans) cout << x << " ";
                    cout << "\n";
                }else{
                    cout << "-1\n";
                }
                for(int j = l; j <= r; j++){
                    cnt2[rv[j]]--;
                    usd[rv[j]] = false;
                }
            }else{
                //then must have more than 1000. bruteforce all with >= 1000
                bool ok = false;
                for(int j=0;j<g1000.size(); j++){
                    if(cnt[r][j] - cnt[l-1][j] > (r - l + 1)/3){
                        ok = true;
                        cout << g1000[j] << " ";
                    }
                }
                if(!ok) cout << "-1";
                cout << "\n";
            }
        }
    }
    
}

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
        vector<pair<int, int>> vp(n+1);
        for(int i=1;i<=n;i++){
            cin >> vp[i].first;
        }
        for(int i=1;i<=n;i++){
            cin >> vp[i].second;
        }
        map<pair<int, int>, int> mpp;
        for(int i=1;i<=n;i++) mpp[vp[i]] = i;
        vector<pair<int, int>> ans;
        bool ok = true;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(vp[i].first == vp[i].second) cnt++;
        }
        if(n % 2 == cnt){
            if(cnt == 1){
                int idx = -1;
                for(int i=1;i<=n;i++){
                    if(vp[i].first == vp[i].second) idx = i;
                }
                int hf = n/2 + 1;
                if(idx != hf){
                    ans.push_back({idx, hf});
                    mpp[vp[idx]] = hf;
                    mpp[vp[hf]] = idx;
                    swap(vp[idx], vp[hf]);
                }
            }
        }else ok = false;
        if(ok){
            for(int i=1;i<=n;i++){
                int cp = n - i + 1;
                if(cp <= i) break;
                if(vp[i].first != vp[cp].second || vp[i].second != vp[cp].first){
                    pair<int, int> need = {vp[cp].second, vp[cp].first};
                    if(mpp.count(need)){
                        int ij = mpp[need];
                        ans.push_back({i, ij});
                        mpp[need] = i;
                        mpp[vp[i]] = ij;
                        swap(vp[i], vp[ij]);
                    }else{
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(ok){
            cout << ans.size() << "\n";
            for(auto [a, b] : ans) cout << a << " " << b << "\n";
        }else{
            cout << "-1\n";
        }
    }
}

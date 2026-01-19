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
        vector<vector<int>> v(n);
        vector<int> mex(n), mex2(n);
        map<int, ll> mp;
        for(int i=0;i<n;i++){
            int sz;
            cin >> sz;
            v[i].resize(sz);
            for(int j=0;j<sz;j++) cin >> v[i][j];
            sort(v[i].begin(), v[i].end());
            for(int j=0;j<sz;j++){
                if(mex[i] == v[i][j]) mex[i]++;
            }
            mex2[i] = mex[i] + 1;
            for(int j=0;j<sz;j++){
                if(mex2[i] == v[i][j]) mex2[i]++;
            }
            mp[mex[i]] += mex2[i] - mex[i];
        }
        ll ans = 0, smex = 0;
        for(int i=0;i<n;i++) smex += mex[i];
        for(int i=0;i<n;i++){
            ans += (smex * ((ll)v[i].size())) * ((ll)v.size() - 1);
            for(int j=0;j<v[i].size();j++){
                bool ok = false;
                if(j != 0 && v[i][j-1] == v[i][j]) ok = true;
                if(j + 1 < v[i].size() && v[i][j+1] == v[i][j]) ok = true;
                if(ok == false && v[i][j] < mex[i]){
                    ans -= (mex[i] - v[i][j]) * ((ll)v.size() - 1);
                }
                if(mp.count(v[i][j])) ans += mp[v[i][j]];
            }

        }
        cout << ans << "\n";
    }
}

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
        vector<int> cnt(2*n+1, 0);
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            vp[i] = {a, b};
            if(a == b) cnt[a]++;
        }
        vector<int> okn;
        for(int i=1;i<=2*n;i++){
            if(cnt[i] == 0) okn.push_back(i);
        }
        string ans(n, '.');
        for(int i=0;i<n;i++){
            if(vp[i].first == vp[i].second){
                if(cnt[vp[i].first] == 1) ans[i] = '1';
                else ans[i] = '0';
            }else{
                auto it = lower_bound(okn.begin(), okn.end(), vp[i].first);
                if(it != okn.end() && *it <= vp[i].second) ans[i] = '1';
                else ans[i] = '0';
            }
        }
        cout << ans << "\n";

    }
}

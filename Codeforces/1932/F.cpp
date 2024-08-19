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
        int n, m;
        cin >> n >> m;
        vector<int> dp(n+1);
        vector<pair<int,int>> vp;
        for(int i=1;i<=m;i++){
            int l, r;
            cin >> l >> r;
            vp.push_back({l, r});
        }
        int p = 0;
        sort(vp.begin(), vp.end()); //sort by l
        multiset<pair<int,int>> st;
        multiset<int> ms; //all begins in st
        for(int i=1;i<=n;i++){
            while(st.size() && st.begin()->first < i){
                auto [v1, v2] = *st.begin();
                st.erase(st.begin());
                ms.erase(ms.find(v2));
            }
            while(p < m && vp[p].first == i){
                ms.insert(i);
                st.insert({vp[p].second, i});
                p++;
            }
            dp[i] = dp[i-1];
            if(ms.size()){
                int val = dp[*ms.begin() - 1] + ms.size();
                dp[i] = max(dp[i], val);
            }
        }
        cout << dp[n] << "\n";
    }
}

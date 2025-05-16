#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3;
int dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<pair<int, int>> vp;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        vp.push_back({v[i], i});
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    set<int> st;
    int i = 0;
    while(i < vp.size()){
        int j = i;
        while(j+1 < vp.size() && vp[j+1].first == vp[i].first) j++;
        for(int k=i;k<=j;k++){
            st.insert(vp[k].second);
            auto it = st.lower_bound(vp[k].second);
            dp[*it] = 1;
            if(it != st.begin() && v[*prev(it)] > v[*it]){
                dp[*it] = dp[*prev(it)] + 1;
            }
            if(next(it) != st.end() && v[*next(it)] > v[*it]){
                dp[*it] = max(dp[*it], dp[*next(it)] + 1);
            }
            st.erase(vp[k].second);
        }
        for(int k=i;k<=j;k++) st.insert(vp[k].second);
        i = j + 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}
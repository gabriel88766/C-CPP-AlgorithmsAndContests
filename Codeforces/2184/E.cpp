#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum(ll n){
    ll ans = n;
    ans *= (n-1);
    ans /= 2;
    return ans;
}
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
        vector<int> v(n+1);
        vector<vector<int>> ins(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(i >= 2) ins[abs(v[i] - v[i-1])].push_back(i-1);
        }
        set<ll> st;
        st.insert(0);
        st.insert(n);
        ll ans = sum(n);
        for(int i=1;i<n;i++){
            cout << ans << " ";
            for(auto x : ins[i]){
                auto it = st.lower_bound(x);
                int lst = *prev(it);
                int nxt = *it;
                ans -= sum(nxt - lst);
                ans += sum(x - lst);
                ans += sum(nxt - x);
                st.insert(x);
            }
        }
        cout << "\n";
    }
}

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
        stack<pair<ll,ll>> st;
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ll x;
            cin >> x;
            if(x == 0) continue;
            while(st.size()){
                int s1 = x > 0 ? 1 : -1;
                int s2 = st.top().first > 0 ? 1 : -1;
                if(s1 != s2){
                    if(abs(x) <= abs(st.top().first)){
                        ans += abs(x) * (i - st.top().second);
                        if(abs(x) == abs(st.top().first)) st.pop();
                        else st.top().first += x;
                        x = 0;
                        break;
                    }else{
                        ans += abs(st.top().first) * (i - st.top().second);
                        x += st.top().first;
                        st.pop();
                    }
                }else break;
            }
            if(x){
                st.push({x, i});
            }
        }
        cout << ans << "\n";
    }
}

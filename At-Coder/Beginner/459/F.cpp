#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll qnt[200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    qnt[1] = 1;
    for(int i=2;i<=200000;i++){
        qnt[i] = qnt[i-1] + i;
    }
    while(t--){
        int n;
        cin >> n;
        ll ans = 0;
        vector<pair<ll, ll>> st;
        st.push_back({-INF_LL, 1});
        for(int i=1;i<=n;i++){
            ll x;
            cin >> x;
            x -= i;
            if(x >= st.back().first){
                st.push_back({x, 1});
            }else{
                while(x < st.back().first){
                    auto pr = st.back();
                    st.pop_back();
                    ll cqt = pr.first - st.back().first; //maybe 0, not treated as bug (duplicated)
                    ll lim = cqt;
                    if(INF_LL / pr.second > lim) lim *= pr.second;
                    else lim = INF_LL;
                    if(lim >= st.back().first - x){
                        ll lo = 0, hi = cqt;
                        while(lo != hi){
                            ll mid = lo + (hi - lo + 1)/2;
                            if(pr.first - mid - x > mid * pr.second) lo = mid;
                            else hi = mid - 1;
                        }
                        //lo is safe
                        ans += lo * qnt[pr.second];
                        x += lo * pr.second;
                        pr.first -= lo;
                        ll miss = pr.first - x;
                        if(miss >= pr.second){
                            ans += qnt[pr.second];
                            st.push_back({pr.first - 1, pr.second});
                            x += pr.second;
                            st.push_back({x, 1});
                        }else{
                            ans += qnt[pr.second] - qnt[pr.second - miss];
                            st.push_back({pr.first - 1, miss});
                            st.push_back({pr.first, pr.second - miss + 1});
                            x += miss;
                        }
                    }else{
                        ans += cqt * qnt[pr.second];
                        st.back().second += pr.second;
                        x += lim;
                    }
                }
            }   
            // cout << ans << "\n";
            // for(auto [a,b] : st){
                // cout << a << " " << b << "\n";
            // }
            // cout << "\n";
            
        }
        cout << ans << "\n";
    }
}

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
        ll ans = 0;   
        vector<ll> v(n);

        for(int i=0;i<n;i++) cin >> v[i];
        for(int i=0;i<n;i++) ans = max(ans, v[i]);

    
        for(int i=0;i<n;i++){
            // suppose max element is v[i];
            stack<ll> st; //max element = st.top() + st.size() - 1;
            st.push(v[i]);
            ll op = k;
            for(int j=i+1;j<n;j++){
                if(v[j] >= st.top()){ // 3 4 , 3 3
                    ll x = st.size();
                    if(x*(v[j]-st.top()+1) <= op){
                        op -= x*(v[j]-st.top()+1);
                        st.push(v[j]);
                    }else{
                        ll more = op / x;
                        ans = max(ans, (ll)(st.top() + more + st.size() - 1LL));
                        break;
                    }
                }else{ // 3 2
                    st.push(st.top() - 1);
                    op -= st.top() - v[j];
                    if(op < 0) break;   
                }
            }
            ans = max(ans, (ll)(st.top() + st.size() - 1LL));
        }
        cout << ans << "\n";
        cout.flush();
    }
}

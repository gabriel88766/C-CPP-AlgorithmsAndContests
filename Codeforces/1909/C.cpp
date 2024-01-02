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
        vector<ll> l(n), r(n), c(n);
        for(int i=0;i<n;i++) cin >> l[i];
        for(int i=0;i<n;i++) cin >> r[i];
        for(int i=0;i<n;i++) cin >> c[i];
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        sort(c.begin(), c.end(), greater<ll>());
        ll ans = 0;
        stack<ll> st;
        int p1 = 0, p2 = 0;
        vector<ll> difs;
        for(int i=0;i<2*n;i++){
            if(p1 < n && p2 < n){
                if(l[p1] < r[p2]){
                    st.push(l[p1]);
                    p1++;
                }else{
                    auto x = st.top();
                    st.pop();
                    difs.push_back(r[p2] - x);
                    p2++;
                }
            }else{
                auto x = st.top();
                st.pop();
                difs.push_back(r[p2] - x);
                p2++;
            }
        }
        sort(difs.begin(), difs.end());
        for(int i=0;i<n;i++) ans += difs[i] * c[i];
        cout << ans << "\n";
    }
}

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Barrier{
    ll val;
    ll ind;
    ll S;
};


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    stack<Barrier> st;
    st.push({INF_LL, 0, 0});
    vector<ll> ans;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        ll cur;
        cin >> cur;
        while(cur >= st.top().val) st.pop();
        ll cans = st.top().S + (i - st.top().ind) * cur;
        st.push({cur, i, cans});
        ans.push_back(cans+1);  
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}

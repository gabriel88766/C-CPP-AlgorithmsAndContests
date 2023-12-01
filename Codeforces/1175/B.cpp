#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll MAX_INT = 1LL << 32;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    ll ans = 0;
    stack<ll> st;
    st.push(1);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s == "add") ans += st.top();
        else if(s == "end"){
            st.pop();
        }else{
            ll x;
            cin >> x;
            ll nxt = st.top() * x;
            nxt = min(nxt, MAX_INT);
            st.push(nxt);
        }
    }
    if(ans >= MAX_INT) cout << "OVERFLOW!!!\n";
    else cout << ans << "\n";
}

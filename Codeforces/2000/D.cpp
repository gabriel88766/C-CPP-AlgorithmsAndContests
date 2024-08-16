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
        vector<ll> v(n+1);
        vector<ll> ps(n+1);
        ll ans = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            ps[i] = ps[i-1] + v[i];
        }
        string s;
        cin >> s;
        s = " " + s;
        queue<int> q;
        stack<int> st;
        for(int i=1;i<=n;i++){
            if(s[i] == 'L') q.push(i);
            if(s[i] == 'R') st.push(i);
        }
        while(!q.empty() && !st.empty() && q.front() < st.top()){
            ans += ps[st.top()] - ps[q.front() - 1];
            st.pop();
            q.pop();
        }
        cout << ans << "\n";
    }
}

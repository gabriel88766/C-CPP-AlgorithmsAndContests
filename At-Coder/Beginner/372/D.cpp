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
    int n;
    cin >> n;
    vector<int> ans(n+1), v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    stack<int> st;
    for(int i=n;i>=1;i--){
        ans[i] = st.size();
        while((!st.empty()) && st.top() < v[i]) st.pop();
        st.push(v[i]);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

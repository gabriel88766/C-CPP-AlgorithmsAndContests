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
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> a(n+1);
        stack<pair<int, int>> st;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=m;i++){
            int b, c;
            cin >> b >> c;
            a[b] += c;
            st.push({b, -c});
            if(a[b] > h){
                //crash.
                while(st.size()){
                    auto [b, c] = st.top();
                    st.pop();
                    a[b] += c;
                }
            }
        }
        for(int i=1;i<=n;i++) cout << a[i] << " ";
        cout << "\n";
    }
}

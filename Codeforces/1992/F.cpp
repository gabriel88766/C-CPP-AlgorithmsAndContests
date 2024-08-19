#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
bool dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> d;
        stack<int> st;
        for(int i=1;i*i<=x;i++){
            if(!(x % i)){
                d.push_back(i);
                if(i*i != x) st.push(x/i);
            }
        }
        while(!st.empty()){
            d.push_back(st.top());
            st.pop();
        }
        int ans = 1;
        dp[1] = true;
        for(int i=1;i<=n;i++){
            int cur;
            cin >> cur;
            if(!(x % cur) && dp[x / cur]){
                //fail..
                ans++;
                for(auto dv : d) dp[dv] = false;
                dp[1] = true;
                dp[cur] = true;
            }else{
                for(int j=d.size()-1;j>=0;j--){
                    if(!(d[j] % cur) && dp[d[j]/cur]) dp[d[j]] = true;
                }
            }
        }
        cout << ans << "\n";




        for(auto dv : d) dp[dv] = false;
    }
}

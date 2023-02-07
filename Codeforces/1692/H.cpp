#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int dp[N], p[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> last;
        vector<int> v(n+1);
        vector<int> s(n+1, 0);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(last[v[i]]) s[i] = last[v[i]];
            last[v[i]] = i;
        }
        dp[0] = 0;
        int maxdp = 0, l, r;
        for(int i=1;i<=n;i++){
            if(dp[s[i]] - (i - s[i]-1) > 0){
                p[i] = s[i];
                dp[i] = dp[s[i]] - (i-s[i]-1) + 1;
            }else{
                p[i] = i;
                dp[i] = 1;
            }
            if(dp[i] > maxdp){
                maxdp = dp[i];
                r = i;
            }
        }
        int aux = r;
        while(p[aux] != aux) aux = p[aux];
        l = aux;
        cout << v[r] << " " << l << " " << r << "\n";
        for(int i=1;i<=n;i++) p[i]=dp[i]=0;
    }
}
 
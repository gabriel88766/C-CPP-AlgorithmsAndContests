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
        vector<tuple<ll, ll, ll>> vt(n+1);
        for(int i=1;i<=n;i++){
            ll a, b, c;
            cin >> a >> b >> c;
            vt[i] = {a, b, c};
        }
        //ord is the order when x goes to inf.
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 1);
        sort(ord.begin(), ord.end(), [&](int a, int b){
            auto [aa, ab, ac] = vt[a];
            auto [ba, bb, bc] = vt[b];
            if(aa != ba) return aa < ba;
            else if(ab != bb) return ab < bb;
            else return ac < bc;
        });
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        for(int i=0; i < n; i++){
            for(int j = i+1; j < n; j++){
                //check if i -> j is ok = check if vt[j](x) > vt[i](x) for all x 
                auto [aa, ab, ac] = vt[ord[i]];
                auto [ba, bb, bc] = vt[ord[j]];
                if(aa != ba){
                    ll delta = (bb-ab) * (bb-ab) - 4 * (bc - ac) * (ba - aa);
                    adj[i][j] = delta < 0;
                }else if(ab != bb){
                    //always false, they cross
                    adj[i][j] = false;
                }else{
                    //always true, cause bc *must* be greater than ac
                    adj[i][j] = true;
                }
            }
        }
        //finally solve the graph problem.
        vector<int> d1(n, 1), d2(n, 1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(adj[i][j]) d1[j] = max(d1[j], d1[i] + 1);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(adj[j][i]) d2[j] = max(d2[j], d2[i] + 1);
            }
        }
        vector<int> ans(n+1);
        for(int i=0;i<n;i++){
            ans[ord[i]] = d1[i] + d2[i] - 1;
        }
        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(vector<int> &v){
    cout << "? ";
    for(auto &x : v) cout << x << " ";
    cout << "\n";
    cout.flush();
    int ans = 0;
    if(v[0] == 1) cin >> ans;
    return ans;
}
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
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> qr = {1, 1, 1};
        vector<int> q2 = {2, 1};
        int ans = ask(qr);
        if(ans == 0){
            ask(q2);
            ans = ask(qr);
        }
        vector<int> ansv(n+1, 0);
        if(abs(ans) == 1){
            //then 1 is the root.
            ansv[1] = ans;
            for(int i=2;i<=n;i++){
                vector<int> cv = {1, 1, i};
                ansv[i] = ask(cv) - ans;
            }
        }else{
            //abs should be 2
            ask(q2);
            // now, 1 = -ans/2;
            //the rest is the value in query;
            
            ansv[1] = -ans/2;
            for(int i=2;i<=n;i++){
                vector<int> cv = {1, 1, i};
                ansv[i] = ask(cv);
            }
        }
        cout << "! ";
        for(int i=1;i<=n;i++) cout << ansv[i] << " ";
        cout << "\n";
        cout.flush();


        
    }
}

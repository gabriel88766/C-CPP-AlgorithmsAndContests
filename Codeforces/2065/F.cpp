#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+2;
vector<int> adj[N];
int a[N];
bool ans[N];
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
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            map<int, int> mp;
            mp[a[i]]++;
            for(auto &v : adj[i]){
                mp[a[v]]++;
            }
            for(auto &[k, v] : mp){
                if(v >= 2) ans[k] = true;
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i]) cout << "1";
            else cout << "0";
        }
        for(int i=1;i<=n;i++){
            ans[i] = false;
            a[i] = 0;
            adj[i].clear();
        }
        cout << "\n";
    }
}

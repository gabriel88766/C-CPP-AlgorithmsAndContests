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
        vector<int> vis(n+1);
        vector<int> p(n+1);
        for(int i=1;i<=n;i++) cin >> p[i];
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int cur = i;
                vector<int> cp;
                do{
                    cp.push_back(cur);
                    cur = p[cur];
                }while(cur != i);
                ans += (cp.size()-1)/2;
                for(auto x : cp) vis[x] = true;
            }
        }
        cout << ans << "\n";
    }
}

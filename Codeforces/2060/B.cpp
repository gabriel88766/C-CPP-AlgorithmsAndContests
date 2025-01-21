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
        int n, m;
        cin >> n >> m;
        vector<int> c(n*m);
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                int x;
                cin >> x;
                c[x] = i;
            }
        }
        vector<int> ans;
        bool ok = true;
        for(int i=0;i<n*m;i+=n){
            vector<int> cur;
            for(int j=0;j<n;j++){
                cur.push_back(c[i+j]);
            }
            if(ans.size()){
                if(ans != cur){
                    ok = false;
                }
            }else ans = cur;
        }
        if(ok){
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}

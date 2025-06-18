#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int a[N], b[N], p[N], sn[N];
int vis[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        cin >> p[i];
        sn[p[i]] = i;
    }
    bool ok = true;
    vector<pair<int, int>> ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> perm;
            int cur = i;
            do{
                perm.push_back(cur);
                cur = p[cur];
            }while(cur != i);
            for(auto x : perm) vis[x] = true;
            if(perm.size() == 1) continue;
            else{
                bool cok = true;
                int mn = INF_INT;
                int imin = -1;
                for(auto x : perm){
                    if(b[p[x]] >= a[x]) cok = false; //can't even start swaping
                    if(b[x] < mn){
                        mn = b[x];
                        imin = x;
                    } 
                }  
                if(!cok) ok = false;
                else{
                    cur = sn[imin];
                    do{
                        ans.push_back({cur, sn[cur]});
                        cur = sn[cur];
                    }while(cur != imin);
                }
            }
        }
    }
    if(ok){
        cout << ans.size() << "\n";
        for(auto [a, b] : ans) cout << a << " " << b << "\n";
    }else cout << "-1\n";
}

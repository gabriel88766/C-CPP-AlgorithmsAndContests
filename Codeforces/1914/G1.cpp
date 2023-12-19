#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


bitset<2005> bs[2005];
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
        vector<int> v(2*n), locl(n+1, -1), locr(n+1, -1);
        for(int i=0;i<2*n;i++){
             cin >> v[i];
             if(locl[v[i]] == -1) locl[v[i]] = i;
             else locr[v[i]] = i;
        }
        int p1 
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++) bs[i][j] = 0;
            vector<bool> vis(n+1, false);
            vis[v[i]] = true;
            queue<int> q;
            q.push(v[i]);
            int l = r = i;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                if(locl[u] < l){
                    for(int i=locl[u];i<l;i++){
                        if(!vis[v[i]]){
                            q.push(v[i]);
                            vis[v[i]] = true;
                        }
                    }
                    l = locl[u];
                }
                if(locr[u] > r){
                    for(int i=r+1;i<=locr[i];i++){
                        if(!vis[v[i]]){
                            q.push(v[i]);
                            vis[v[i]] = true;
                        }
                    }
                    r = locr[u];
                }
            }
            if(l == 0 && r )
        }
    }
}

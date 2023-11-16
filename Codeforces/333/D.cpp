#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool vis[1005][1005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
    int lo = 0, hi = 1e9;
    while(lo != hi){
        memset(vis, 0, sizeof(vis));
        int mid = lo + (hi - lo + 1) / 2;
        bool ok = false;
        for(int i=0;i<n;i++){
            vector<int> aux;
            for(int j=0;j<m;j++){
                if(v[i][j] >= mid) aux.push_back(j);
            }
            for(int j=0;j<aux.size();j++){
                for(int k=j+1;k<aux.size();k++){
                    if(vis[aux[j]][aux[k]]){
                        ok = true;
                        break;
                    }else vis[aux[j]][aux[k]] = 1;
                }
                if(ok) break;
            }
            if(ok) break;
        }
        if(ok) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<int, int> bst[256];

int v[300005][8];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    for(int msk=0;msk<(1 << m);msk++){
        bst[msk] = {-1, -1};
        for(int i=1;i<=n;i++){
            int cur = INF_INT;
            for(int x=0;x<m;x++){
                if(msk & (1 << x)){
                    cur = min(cur, v[i][x]);
                }
            }
            if(cur > bst[msk].first){
                bst[msk] = {cur, i};
            }
        }
    }
    int ansm = -1;
    pair<int,int> ans = {-1, -1};
    int aux = (1 << m) - 1;
    for(int msk=0;msk<(1 << m); msk++){
        int om = msk ^ aux;
        if(min(bst[msk].first, bst[om].first) > ansm){
            ansm = min(bst[msk].first, bst[om].first);
            ans = {bst[msk].second, bst[om].second};
        }
    }
    cout << ans.first << " " << ans.second << "\n";
}

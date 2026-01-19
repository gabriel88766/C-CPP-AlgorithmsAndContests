#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int nxt[100005][8];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in",     "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1), vx(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        vx[v[i]] = i;
    }
    for(int j=0;j<8;j++){
        for(int i=1;i<=n;i++){
            if(j == 0) nxt[i][j] = v[i];
            else nxt[i][j] = nxt[nxt[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=q;i++){
        int tq, x, y;
        cin >> tq >> x >> y;
        if(tq == 1){
            swap(v[x], v[y]);
            vx[v[x]] = x;
            vx[v[y]] = y;
            for(int j=0;j<8;j++){
                int u = x;
                for(int i=1;i<=130;i++){ //130 ftw;
                    if(j == 0) nxt[u][j] = v[u];
                    else nxt[u][j] = nxt[nxt[u][j-1]][j-1];
                    u = vx[u];
                }
                
            }
            for(int j=0;j<8;j++){
                int u = y;
                for(int i=1;i<=130;i++){ //130 ftw;
                    if(j == 0) nxt[u][j] = v[u];
                    else nxt[u][j] = nxt[nxt[u][j-1]][j-1];
                    u = vx[u];
                }
                u = vx[u];
            }
        }else{
            for(int j=7;j>=0;j--){
                while(y >= (1 << j)){
                    y -= (1 << j);
                    x = nxt[x][j];
                }
            }
            cout << x << "\n";
        }
    }
}

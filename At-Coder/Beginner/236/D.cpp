#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int a[17][17];

bool in[17];
vector<pair<int,int>> cur;
vector<vector<pair<int,int>>> vp;
void genall(int tt, int ct){
    if(ct == tt){
        vp.push_back(cur);
        return;
    }
    int f;
    for(int i=1;i<=tt;i++){
        if(!in[i]){
            f = i;
            break;
        }
    }
    in[f] = true;
    for(int i=f+1;i<=tt;i++){
        if(!in[i]){
            cur.push_back({f, i});
            in[i] = true;
            genall(tt, ct + 2);
            in[i] = false;
            cur.pop_back();
        }
    }
    in[f] = false;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int p = 2*n;
    genall(p, 0);
    for(int i=1;i<=p;i++){
        for(int j=i+1;j<=p;j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(auto v : vp){
        int cur = 0;
        for(auto [x, y] : v){
            cur ^= (a[x][y]);
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}

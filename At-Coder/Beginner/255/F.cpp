#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int l[N], r[N], pre[N], in[N], inv[N];
bool solve(int pl, int pr, int il, int ir){

    int cx = pre[pl];
    int id = inv[cx];
    int tt = id - il;
    // cout << pl << " " << pr << " " << il << " " << ir << " " << tt << endl;
    if(id < il || id  > ir) return false;
    
    bool ok = true;
    if(tt != 0){
        l[cx] = pre[pl+1];
        ok &= solve(pl+1, pl + tt, il, il + tt - 1);
    }
    if(tt != ir - il){
        r[cx] = pre[pl + tt + 1];
        ok &= solve(pl + tt + 1, pr, il + tt + 1, ir);
    }
    return ok;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;;
    for(int i=0;i<n;i++) cin >> pre[i];
    for(int i=0;i<n;i++){
        cin >> in[i];
        inv[in[i]] = i;
    }
    if(pre[0] == 1 && solve(0, n-1, 0, n-1)){
        for(int i=1;i<=n;i++){
            cout << l[i] << " " << r[i] << "\n";
        }
    }else cout << "-1\n";
}

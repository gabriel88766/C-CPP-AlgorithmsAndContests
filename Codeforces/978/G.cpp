#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n, m;
const int N = 105;
int s[N], d[N], c[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n >> m;
    map<int,int> exd;
    for(int i=1;i<=m;i++){
        cin >> s[i] >> d[i] >> c[i];
        exd[d[i]] = i;
    }
    vector<int> ans(n+1);
    bool ok = true;
    c[0] = 105;
    for(int i=1;i<=n;i++){
        int ibest=0, nxtex = 101;
        if(exd[i]){
            if(c[exd[i]]){
                ok = false;
                break;
            }else{
                ans[i] = m+1;
                continue;
            }
        }
        for(int j=1;j<=m;j++){
            if(s[j] > i) continue;
            if(c[j] == 0) continue;
            if(d[j] < nxtex){
                ibest = j;
                nxtex = d[j];
            }
        }
        ans[i] = ibest;
        c[ibest]--;
    }
    if(ok) for(int i=1;i<=n;i++) cout << ans[i] << " ";
    else cout << "-1";
}

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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i<m;i++) cin >> v[i];
    vector<int> ans(n+1);
    vector<int> used(n+1, 0);
    bool ok = true;
    for(int i=1;i<m;i++){
        int dif = v[i] - v[i-1];
        if(dif <= 0) dif += n;
        if((ans[v[i-1]] && ans[v[i-1]] != dif) || (used[dif] && used[dif] != v[i-1])){
            ok = false;
            break;
        }else{
            ans[v[i-1]] = dif;
            used[dif] = v[i-1];
        }
    }
    if(ok){
        int p = 1;
        for(int i=1;i<=n;i++){
            if(!ans[i]){
                while(used[p]) p++;
                ans[i] = p;
                used[p] = true;
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }else cout << "-1\n";
}

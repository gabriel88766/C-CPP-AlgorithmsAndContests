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
    bool h1 = false, hn = false;
    int n, m;
    cin >> n >> m;
    vector<bool> is(n+1);
    for(int i=1;i<=m;i++){
        int x;
        cin >> x;
        is[x] = true;
    }
    if(is[1] || is[n]) cout << "-1\n";
    else{
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            ans[i] = i;
        }
        for(int i=1;i<=n;i++){
            if(is[i]) swap(ans[i], ans[i+1]);
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}

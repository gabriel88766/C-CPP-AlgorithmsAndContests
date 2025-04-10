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
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<bool> h1(k+1, false), h2(k+1, false);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x <= k) h1[x] = true;
        }
        for(int i=0;i<m;i++){
            int x;
            cin >> x;
            if(x <= k) h2[x] = true;
        }
        bool ok = true;
        int c1 = 0, c2 = 0;
        for(int i=1;i<=k;i++){
            if(!h1[i] && !h2[i]) ok = false;
            else{
                if(h1[i] && h2[i]);
                else{
                    if(!h1[i]) c2++;
                    else c1++;
                } 
            }
        }
        if(c1 > k/2 || c2 > k/2) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

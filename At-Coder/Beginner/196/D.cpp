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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int ans = 0;
    for(int i=0;i<(1 << (h*w));i++){
        if(__builtin_popcount(i) != a) continue;
        for(int j = 0; j < (1 << a); j++){
            vector<int> mkd(h*w, 0);
            bool ok = true;
            int bt = 0;
            for(int u=0;u<h*w;u++){
                if(i & (1 << u)){
                    mkd[u]++;
                    if(j & (1 << bt)){
                        if(u % w == w-1) ok = false;
                        else mkd[u+1]++;
                    }else{
                        if(u + w >= h*w) ok = false;
                        else mkd[u+w]++;
                    }
                    bt++;
                }
            }
            if(*max_element(mkd.begin(), mkd.end()) > 1) ok = false;
            if(ok) ans++;
            // cout << i << " " << j << " " << ans << "\n";
        }
        // cout << i << " " << ans << "\n";
    }
    cout << ans << "\n";
}

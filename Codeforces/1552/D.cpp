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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        bool ok = false;
        for(int i=0;i<n;i++){
            for(int m=0;m<(1 << n);m++){
                if(m & (1 << i)) continue;
                for (int s=m;; s=(s-1)&m){ 
                    int curs = 0;
                    for(int b=0;b<n;b++){
                        if(m & (1 << b)){
                            if(s & (1 << b)) curs += v[b];
                            else curs -= v[b];
                        }
                    }
                    if(curs == v[i]) ok = true;
                    if(s == 0) break;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

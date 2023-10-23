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
    int m;
    cin >> m;
    vector<string> v(3);
    for(int i=0;i<3;i++) cin >> v[i];
    
    vector<int> perm = {0, 1, 2};
    int ans = INF_INT;
    do{
        for(int i=0;i<=9;i++){
            int cur = -1;
            bool ok = true;
            for(int j=0;j<3;j++){
                //perm[j]
                cur++;
                vector<int> nxt;
                for(int k=0;k<m;k++){
                    if(v[perm[j]][k] == '0'+i){
                        nxt.push_back(k);
                    }
                }
                if(nxt.size() == 0){
                    ok = false;
                    break;
                }else{
                    int mod = cur % m;
                    auto it = lower_bound(nxt.begin(), nxt.end(), mod);
                    if(it != nxt.end()){
                        cur += *it - mod;
                    }else{
                        cur += *nxt.begin() + m - mod;
                    }
                }
                
            }
            if(ok) ans = min(ans, cur);
        }
    }while(next_permutation(perm.begin(), perm.end()));
    if(ans == INF_INT) cout << "-1\n";
    else cout << ans << "\n";
}

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int val[51];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    val[0] = 0;
    for(int i=1;i<=n;i++) cin >> val[i];
    if(n >= 24){
        //pigeonhole, there is at least 2 in same hour.
        cout << "0\n";
    }else{
        int ans = 0;
        //2^23 * 23
        for(int i = 1; i < (1 << 24); i+=2){
            if(__builtin_popcount(i) != (n+1)) continue;
            int msk = i;
            bool ok = true;
            for(int j=0;j<=n;j++){
                if(msk & (1 << val[j])) msk ^= (1 << val[j]);
                else if(msk & (1 << (24 - val[j]))) msk ^= (1 << (24 - val[j]));
                else ok = false;
            }
            if(ok){
                msk = i ^ (1 << 24);
                int cur = 12;
                int lj = 0;
                for(int j=1;j<=24;j++){
                    if(msk & (1 << j)){
                        cur = min(cur, j - lj);
                        lj = j;
                    }
                }
                if(cur > ans) ans = cur;
            }
        }
        cout << ans << "\n";
    }
}

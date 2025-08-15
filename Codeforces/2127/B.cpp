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
        int n, x;
        cin >> n >> x;
        int ans = 0;
        string s;
        cin >> s;
        s = " " + s;
        for(int i=0;i<2;i++){
            int i1 = (i == 0 ? -1 : 1);
            string cs = s;
            int px = x + i1;
            while(px > 0 && px <= n && cs[px] == '#') px += i1;
            if(px > 0 && px <= n) cs[px] = '#';
            int cans = INF_INT;
            for(int j=0;j<2;j++){
                auto xs = cs;
                int pj = x;
                int i2 = (j == 0 ? -1 : 1);
                int cnt = 0;
                int pk = x;
                while(pj > 0 && pj <= n){
                    cnt++;
                    while(pj > 0 && pj <= n && xs[pj] == '.'){
                        xs[pj] = ',';
                        pj += i2;
                    }
                    while(pk > 0 && pk <= n && xs[pk] != '.') pk += i2;
                    if(pk > 0 && pk <= n) xs[pk] = '#';
                    xs[pj] = '.';
                }
                cans = min(cans, cnt);
            }
            ans = max(ans, cans);
        }
        cout << ans << "\n";
    }
}

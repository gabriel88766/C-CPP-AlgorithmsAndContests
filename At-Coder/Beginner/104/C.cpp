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
    int d, g;
    cin >> d >> g;
    vector<pair<int,int>> vp(d);
    for(int i=0;i<d;i++){
        int x, s;
        cin >> x >> s;
        vp[i] = {x, s};
    }
    ll ans = INF_LL;
    for(int m=0;m<(1 << d);m++){
        //this msk is completed
        ll curp = 0, curs = 0;
        for(int j=0;j<d;j++){
            if(m & (1 << j)){
                curp += (j+1) * 100 * vp[j].first + vp[j].second;
                curs += vp[j].first;
            }
        }
        for(int j=d-1;j>=0;j--){
            if(!(m & (1 << j))){
                int pts = (j+1) * 100;
                int qtd = (g - curp + pts - 1) / pts;
                if(qtd < 0) break;
                if(qtd < vp[j].first) curs += qtd;
                else curs = INF_LL;
                break;
            }
        }
        ans = min(ans, curs);
    }
    cout << ans << "\n";
}

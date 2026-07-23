#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> sdiv(30001);
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=30000;i++){
        for(int j=2*i;j<=30000;j+=i){
            sdiv[j] += i;
        }
    }
    vector<int> aln;
    for(int i=1;i<=28122;i++){
        if(sdiv[i] > i) aln.push_back(i);
    }
    vector<bool> isp(28123, false);
    for(auto x : aln){
        for(auto y : aln){
            if(x + y < 28123) isp[x + y] = true;
            else break;
        }
    }
    ll ans = 0;
    for(int i=1;i<=28122;i++) if(!isp[i]) ans += i;
    cout << ans << "\n";
}

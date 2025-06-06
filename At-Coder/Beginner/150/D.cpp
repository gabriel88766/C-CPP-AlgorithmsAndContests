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
    ll lc = 1;
    bool notok = false;
    int qm = -1;
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;
        int aux = x;
        int cur = 0;
        while(aux % 2 == 0){
            aux /= 2;
            cur++;
        }
        if(qm == -1) qm = cur;
        else if(qm != cur) notok = true;
        lc = min((ll)INF_INT, lcm(x/2, lc));
    }
    if(notok) cout << "0\n";
    else{
        int ans = m/lc - m/(2*lc);
        cout << ans << "\n";
    }

}

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
    int n, q;
    cin >> n >> q;
    vector<bool> cl(n+2, false);
    int ans = 0;
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        if(!cl[x]){
            if(cl[x-1] && cl[x+1]) ans--;
            else if(cl[x-1] == false && cl[x+1] == false) ans++;
            cl[x] = true;
        }else{
            if(cl[x-1] && cl[x+1]) ans++;
            else if(cl[x-1] == false && cl[x+1] == false) ans--;
            cl[x] = false;
        }
        cout << ans << "\n";
    }
}

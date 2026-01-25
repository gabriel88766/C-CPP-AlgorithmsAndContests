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
    int q;
    cin >> q;
    int st = 0, vol = 0;
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1) vol++;
        else if(tq == 2) vol = max(vol - 1, 0);
        else st ^= 1;
        if(st == 1 && vol >= 3) cout << "Yes\n";
        else cout << "No\n";
    }
}

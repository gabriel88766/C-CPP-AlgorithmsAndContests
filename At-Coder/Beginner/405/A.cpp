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
    int r, x;
    cin >> r >> x;
    if(x == 1){
        if(r >= 1600 && r <= 2999) cout << "Yes\n";
        else cout << "No\n";
    }else{
        if(r >= 1200 && r <= 2399) cout << "Yes\n";
        else cout << "No\n";
    }
}

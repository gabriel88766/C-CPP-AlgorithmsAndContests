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
    map<int, int> mpx, mpy;
    for(int i=0;i<3;i++){
        int a, b;
        cin >> a >> b;
        mpx[a]++;
        mpy[b]++;
    }
    int x, y;
    for(auto [k, v] : mpx) if(v == 1) x = k;
    for(auto [k, v] : mpy) if(v == 1) y = k;
    cout << x << " " << y << "\n";
}

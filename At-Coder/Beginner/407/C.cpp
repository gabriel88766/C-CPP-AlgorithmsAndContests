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
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int ans = 0;
    int mv = 0;
    for(auto &x : s){
        int cur = (x - '0' - mv + 10) % 10;
        ans += cur + 1;
        mv = (mv + cur) % 10;
    }
    cout << ans << "\n";
}

// 1984
// 1984 <- 7540 <- 754 <- 310 <- 31 <- 20 <- 2 <- 0

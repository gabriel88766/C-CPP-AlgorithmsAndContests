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
        int ans = 0;
        int a = 0, b = 0, c = 0;
        int x;
        cin >> x;
        while(a != x || b != x || c != x){
            if(a > b) swap(a, b);
            if(a > c) swap(a, c);
            if(b > c) swap(b, c);
            a = min(2*b + 1, x);
            ans++;
        }
        cout << ans << "\n";
    }
}

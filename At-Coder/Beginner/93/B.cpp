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
    int a, b, k;
    cin >> a >> b >> k;
    set<int> s;
    for(int i=b;i>=max(a, b-k+1);i--) s.insert(i);
    for(int i=a;i<=min(b, a+k-1);i++) s.insert(i);
    for(auto x : s) cout << x << "\n";

}

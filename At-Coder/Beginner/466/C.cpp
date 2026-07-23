#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    string s;
    cin >> s;
    if(s == "Yes") return true;
    else return false;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int p = 2;
    ll ans = 0;
    for(int i=1;i<n;i++){
        if(i == p) p++;
        while(p <= n && ask(i, p)) p++;
        ans += p - i - 1;
    }
    cout << "! " << ans << "\n";
    cout.flush();
}

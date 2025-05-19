#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    int p1 = 1;
    ll ans = 0;
    while(p1 < n){
        if(v[p1] < v[p1+1]) p1++;
        else{
            int p2 = p1;
            while(p2 + 1 <= n && v[p2+1] < v[p2]) p2++;
            int p3 = p1;
            int p4 = p2;
            while(p4 + 1 <= n && v[p4+1] > v[p4]) p4++;
            while(p3 - 1 >= 1 && v[p3] > v[p3-1]) p3--;
            ll cur = p1 - p3;
            cur *= (p4 - p2);
            ans += cur;
            p1 = p2;
        }
    }
    cout << ans << "\n";
}

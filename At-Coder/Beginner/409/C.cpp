#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int cp = 0;
    int n, l;
    cin >> n >> l;
    cnt[0] = 1;
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        cp += x;
        cp %= l;
        cnt[cp]++;
    }
    if(l % 3) cout << "0\n";
    else{
        ll ans = 0;
        for(int i=0;i<l/3;i++){
            ll a = cnt[i];
            ll b = cnt[i+l/3];
            ll c = cnt[i+(2*l)/3];
            ans += a*b*c;
        }
        cout << ans << "\n";
    }
}

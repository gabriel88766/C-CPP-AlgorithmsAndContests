#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll v[N];
ll s[2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int bg;
    if(n % 2) bg = 1;
    else bg = 2;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(i == 1) s[i] = v[1];
        else{
            s[i&1] = max({s[i&1], s[i&1] + v[i] + v[i-1], s[(i&1)^1] + v[i]});
        }
    }
    cout << s[n&1] << "\n";
}

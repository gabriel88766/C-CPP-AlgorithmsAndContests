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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    s += ('a'+26);
    vector<bool> forb(27, true);
    for(int i=0;i<k;i++){
        char c;
        cin >> c;
        forb[c-'a'] = false;
    }
    vector<bool> use(n+2, false);
    ll ans = 0;
    ll lst = 0;
    for(ll i=1;i<=(n+1);i++){
        if(forb[s[i]-'a']){
            ans += ((i-1-lst)*(i-lst))/2;
            lst = i;
        }
    }
    cout << ans << "\n";
}

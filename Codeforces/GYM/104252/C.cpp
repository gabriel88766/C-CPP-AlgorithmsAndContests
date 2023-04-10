#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll pot[61];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, p, h;
    pot[0] = 1;
    for(int i=1;i<=60;i++) pot[i] = 2*pot[i-1];
    cin >> n >> p >> h;
    string ans;
    vector<ll> hs;
    hs.push_back(h);
    for(ll i=n;i>=1;i--){
        if(h > pot[i-1]){
            h = pot[i] - h+1;
        }
        hs.push_back(h);
    }
    reverse(hs.begin(), hs.end());
    char reg;
    for(int i=0;i<hs.size()-1;i++){
        if(p <= pot[n-i-1]) reg = 'L';
        else reg = 'R';


        if(hs[i+1] == hs[i]){
            ans += (reg == 'L'? 'R' : 'L');
            if(p > pot[n-i-1]) p -= pot[n-i-1];
        }
        else {
            ans += reg;
            if(p <= pot[n-i-1]) p = pot[n-i-1] - p + 1;
            else p = 2*pot[n-i-1]-p+1; 
        }
    }
    cout << ans;
}

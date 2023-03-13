#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s, t;
    cin >> n >> s >> t;
    int bp = 0;
    vector<int> tp;
    while(bp < n){
        if(s[bp] == t[bp]){
            tp.push_back(1);
            bp++;
        }else{
            tp.push_back(2);
            bp+=2;
        }
    }
    ll ans;
    if(tp[0] == 1) ans = 3;
    else ans = 6;
    for(int i=1;i<tp.size();i++){
        if(tp[i-1] == 1){
            ans = (ans * 2) % MOD;
        }else if(tp[i] == 2){
            ans = (ans * 3) % MOD;
        }
    }
    cout << ans;
    
}

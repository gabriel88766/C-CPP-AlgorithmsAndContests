#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<string> v;

void init(){
    ll x = 1;
    v.push_back(to_string(x));
    for(int i=1;i<=60;i++){
        x *= 2;
        v.push_back(to_string(x));
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s = to_string(n);
        int ans = 100;
        for(auto x : v){
            int c = 0, p = 0;
            for(int i=0;i<s.size();i++){
                if(p < x.size() && x[p] == s[i]){
                    p++;
                }else c++;
            }
            int dif = x.size() - p;
            ans = min(ans, dif + c);
        }
        cout << ans << "\n";

    }
}

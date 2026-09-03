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
    int n;
    bool ok = true;
    map<string, int> mp;
    cin >> n;
    for(int i=0;i<n;i++){
        string a, b;
        cin >> a >> b;
        if(a == "pickup"){
            if(mp.count(b)) ok = false;
            else mp[b] = 1;
        }else{
            if(!mp.count(b) || mp[b] != 1) ok = false;
            else mp[b] = 2;
        }
    }
    for(auto [k, v] : mp) if(v == 1) ok = false;
    if(ok) cout << "yes\n";
    else cout << "no\n";

}

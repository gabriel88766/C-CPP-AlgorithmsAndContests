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
    string x;
    string s;
    int n;
    cin >> n >> s;
    if(s.size() == 1){
        if(s[0] == '1') cout << 20'000'000'000LL << "\n";
        else cout << 10'000'000'000LL << "\n";
    }else if(s.size() == 2){
        if(s == "00") cout << "0\n";
        else if(s == "01") cout << 9999999999LL << "\n";
        else cout << 10'000'000'000LL << "\n";
    }else{
        for(int i=0;i<n;i++) x += "110";
        
        if(s == x.substr(0, s.size())){
            ll ans = (30'000'000'003LL - s.size())/3;
            cout << ans << "\n";
        }else if(s == x.substr(1, s.size())){
            ll ans = (30'000'000'002LL - s.size())/3;
            cout << ans << "\n";
        }else if(s == x.substr(2, s.size())){
            ll ans = (30'000'000'001LL - s.size())/3;
            cout << ans << "\n";
        }else cout << "0\n";
    }
}

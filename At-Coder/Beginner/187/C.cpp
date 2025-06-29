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
    map<string, bool> mp1, mp2;
    int n;
    cin >> n;
    string ans = "satisfiable";
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        if(s[0] == '!'){
            mp2[s.substr(1, s.size()-1)] = true;
            if(mp1.count(s.substr(1, s.size() - 1))) ans = s.substr(1, s.size() - 1);
        }else{
            mp1[s] = true;
            if(mp2.count(s)) ans = s;
        } 
    }
    cout << ans << "\n";
}

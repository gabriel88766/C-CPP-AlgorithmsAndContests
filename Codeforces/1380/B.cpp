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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cr = 0, cs = 0, cp = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'R') cr++;
            else if(s[i] == 'S') cs++;
            else cp++;
        }
        string ans;
        if(cr >= cs && cr >= cp){
            ans = string(s.size(), 'P');
        }else if(cs >= cr && cs >= cp){
            ans = string(s.size(), 'R');
        }else{
            ans = string(s.size(), 'S');
        }
        cout << ans << "\n";
    }
}

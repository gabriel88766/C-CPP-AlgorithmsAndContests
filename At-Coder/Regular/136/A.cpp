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
    string s, ans;
    int n;
    cin >> n >> s;
    int cb = 0;
    for(auto c : s){
        if(c == 'A') cb += 2;
        else if(c == 'B') cb++;
        else{
            for(int i=0;i<cb/2;i++) ans += 'A';
            if(cb % 2) ans += 'B';
            ans += 'C';
            cb = 0;
        }
    }
    for(int i=0;i<cb/2;i++) ans += 'A';
    if(cb % 2) ans += 'B';
    cout << ans << "\n";
}

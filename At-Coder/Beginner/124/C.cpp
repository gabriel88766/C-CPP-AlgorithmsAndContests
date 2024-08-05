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
    string s;
    cin >> s;
    int ans = INF_INT;
    for(int b=0;b<2;b++){
        int cur = 0;
        for(int i=0;i<s.size();i++){
            if((i+b)%2){
                if(s[i] == '0') cur++;
            }else if(s[i] == '1') cur++;
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}

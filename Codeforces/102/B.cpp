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
    if(s.size() == 1) cout << 0;
    else{
        int sd = 0;
        for(int i=0;i<s.size();i++) sd += (s[i]-'0');
        int ans = 1;
        while(sd >= 10){
            ans++;
            int nsd = 0;
            while(sd){
                nsd += sd % 10;
                sd /= 10;
            }
            sd = nsd;
        }
        cout << ans;
    }
}

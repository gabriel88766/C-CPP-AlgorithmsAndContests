#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string myitoa(int a){
    string ans;
    while(a){
        ans += ('0' + (a % 10));
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i=a;i<=b;i++){
        string s = myitoa(i);
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t) ans++;
    }
    cout << ans << "\n";
}

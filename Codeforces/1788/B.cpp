#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int sumdig(int n){
    int ans = 0;
    while(n){
        ans += n%10;
        n/=10;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int a=0, b=0, diff = 0, aux, bp = 0;
        while(bp < n){
            int cur = (s[bp]-'0') % 10;
            a *= 10;
            b *= 10;
            a += cur/2;
            b += cur/2;
            if(cur%2){
                if(diff == 0){
                    a += 1;
                    diff = 1;
                }else{
                    b += 1;
                    diff = 0;
                }
            }
            bp++;
        }
        cout << a << " " << b << "\n";
    }
}

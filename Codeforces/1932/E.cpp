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
        int n;
        string s;
        cin >> n >> s;
        vector<int> ps(n);
        string ans = "";
        int carry = 0;
        for(int i=0;i<n;i++){
            if(i != 0) ps[i] = ps[i-1];
            ps[i] += s[i] - '0';
        }
        for(int i=n-1;i>=0;i--){
            int d = (carry + ps[i]) % 10;
            ans += (char)(d + '0');
            carry = (carry + ps[i]) / 10;
        }
        while(carry){
            int d = carry % 10;
            ans += (char)(d + '0');
            carry /= 10;
        }
        while(ans.back() == '0') ans.pop_back();

        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}

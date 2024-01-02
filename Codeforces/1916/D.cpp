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
        cin >> n;
        if(n == 1){
            cout << "1\n";
            continue;
        }
        //169, 961
        string ans;
        for(int i=0;i<n;i++) ans += '0';

        for(int i=1;i<=n/2;i++){
            auto s = ans;
            s[0] = '1';
            s[i] = '6';
            s[2*i] = '9';
            cout << s << "\n";
        }
        for(int i=1;i<=n/2;i++){
            auto s = ans;
            s[0] = '9';
            s[i] = '6';
            s[2*i] = '1';
            cout << s << "\n";
        }
        auto s = ans;
        s[0] = '1';
        s[1] = '9';
        s[2] = '6';
        cout << s << "\n";
    }
}

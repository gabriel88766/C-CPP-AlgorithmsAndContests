#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool isdiv(int n){
    string s = to_string(n);
    int sd = 0;
    for(auto c : s) sd += (c - '0');
    return !(n % sd);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    if(s.size() <= 6){
        int N = stoi(s);
        bool ok = false;
        for(int i=N;i<2*N;i++){
            if(isdiv(i) && isdiv(i+1)){
                ok = true;
                cout << i << "\n";
                break;
            }
        }
        if(!ok) cout << "-1\n";
    }else{
        int cur = 10*(s[0] - '0') + (s[1] - '0');
        if(cur >= 55){
            string ans(s.size() + 1, '0');
            ans[0] = '1';
            ans[2] = '7';
            cout << ans << "\n";
        }else{
            string ans(s.size(), '0');
            if(cur < 17){
                ans[0] = '1';
                ans[1] = '7';
            }else if(cur < 26){
                ans[0] = '2';
                ans[1] = '6';
            }else if(cur < 35){
                ans[0] = '3';
                ans[1] = '5';
            }else if(cur < 44){
                ans[0] = '4';
                ans[1] = '4';
            }else if(cur < 53){
                ans[0] = '5';
                ans[1] = '3';
            }else if(cur < 62){
                ans[0] = '6';
                ans[1] = '2';
            }else{
                assert(false);
            }
            cout << ans << "\n";
        }
    }
}

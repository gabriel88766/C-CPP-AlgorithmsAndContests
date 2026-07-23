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
        //suffix, eliminate all
        char x = s.back();
        while(s.size() && s.back() == x) s.pop_back();
        s += x;
        //prefix, 00000 is good, 1111 is bad, eliminate all 0;
        string rs;
        bool l0 = false;
        for(auto x : s){
            if(x == '0'){
                if(!l0){
                    l0 = true;
                    rs += x;
                }
            }else{
                l0 = false;
                rs += x;
            }
        }
        for(auto &x : rs){
            if(x == '0') x = '1';
            else x = '0';
        }
        cout << rs << "\n";
    }
}

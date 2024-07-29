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
        string x1 = "";
        x1 += s[0];
        x1 += s[1];
        string x2 = "";
        x2 += s[3];
        x2 += s[4];
        if(s[0] >= '2' || (s[0] == '1' && s[1] >= '2')){
            int val = stoi(x1) - 12;
            if(val == 0) val += 12;
            x1 = to_string(val);
            if(x1.size() == 1) x1 = "0" + x1;
            cout << x1 << ":" << x2 << " PM\n";
        }else{
            if(x1[0] == '0' && x1[1] == '0') x1 = "12";
            cout << x1 << ":" << x2 << " AM\n";
        }
    }
}

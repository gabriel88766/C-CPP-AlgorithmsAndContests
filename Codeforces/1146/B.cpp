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
    string an;
    for(int i=0;i<s.size();i++){
        if(s[i] != 'a') an += s[i];
        if(i + an.size() == s.size() - 1){
            if(s.substr(i+1, an.size()) == an || (an.size() == 0 && i + 1 == s.size())){
                cout << s.substr(0, i+1) << "\n";
                return 0;
            }
            break;
        }
    }
    cout << ":(\n";
}

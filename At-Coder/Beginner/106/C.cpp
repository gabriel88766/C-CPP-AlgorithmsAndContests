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
    ll k;
    cin >> k;
    int fn1 = -1;
    for(int i=0;i<s.size();i++){
        if(s[i] != '1'){
            fn1 = i;
            break;
        }
    }
    if(fn1 == -1){
        assert(k <= s.size());
        cout << "1\n";
    }else{
        if(k <= fn1) cout << "1\n";
        else cout << s[fn1] << "\n";
    }
}

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
    bool ok = true;
    for(int i=0;i<s.size();i++){
        if(i % 2){
            if(s[i] >= 'A' && s[i] <= 'Z');//ok
            else ok = false;
        }else{
            if(s[i] >= 'a' && s[i] <= 'z');//ok
            else ok = false;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}

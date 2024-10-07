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
    int l = -1, r = -1;
    bool ok1 = false;
    for(int i=0;i<s.size();i++){
        if(s[i] == '[') ok1 = true;
        if(s[i] == ':' && ok1){
            l = i;
            break;
        }
    }
    ok1 = false;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] == ']') ok1 = true;
        if(s[i] == ':' && ok1){
            r = i;
            break;
        }
    }
    if(l != -1 && r != -1 && r > l){
        //then its ok
        int tt = 4;
        for(int i=l;i<=r;i++) if(s[i] == '|') tt++;
        cout << tt << "\n";
    }else cout << "-1\n";
}

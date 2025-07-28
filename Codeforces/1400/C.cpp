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
        int x;
        cin >> x;
        int n = s.size();
        string w(n, '1');
        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                if(i-x >= 0) w[i-x] = '0';
                if(i+x < w.size()) w[i+x] = '0';
            }
        }
        bool ok = true;
        //check if w makes both 1 and 2 false for some s[i] = '1'
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                if(i-x >= 0 && w[i-x] == '1');//ok
                else if(i+x < w.size() && w[i+x] == '1'); //ok
                else ok = false;
            }
        }
        if(ok) cout << w << "\n";
        else cout << "-1\n";
    }
}

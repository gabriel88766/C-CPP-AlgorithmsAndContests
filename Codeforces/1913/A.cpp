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
        int ind = 1;
        while(ind < s.size() && s[ind] == '0') ind++;
        if(ind == s.size()) cout << "-1\n";
        else{
            string s1 = s.substr(0, ind);
            string s2 = s.substr(ind, s.size()-ind);
            if(s1.size() < s2.size()) cout << s1 << " " << s2 << "\n";
            else if(s1.size() == s2.size() && s1 < s2) cout << s1 << " " << s2 << "\n";
            else cout << "-1\n";
        }
    }
}

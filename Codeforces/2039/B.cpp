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
        //if s = "ab" -> a, ab, b
        //if s = "abc" -> a, ab, abc, b, bc, c //OK
        //if s = "aa" -> a, aa //OK
        //if s = "aba" -> a, ab, aba, b, ba
        //if s = "abab"
        bool ok = false;
        for(int i=1;i<s.size();i++){
            if(s[i] == s[i-1]){
                cout << s[i] << s[i] << "\n";
                ok = true;
                break;
            }
        }
        if(!ok){
            for(int i=2;i<s.size();i++){
                if(s[i-2] != s[i-1] && s[i-2] != s[i] && s[i-1] != s[i]){
                    cout << s.substr(i-2, 3) << "\n";
                    ok = true;
                    break;
                }
            }
        }
        if(!ok){
            //the string is "bababababa"
            cout << "-1\n";
        }
    }
}

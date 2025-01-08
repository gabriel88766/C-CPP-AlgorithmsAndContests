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
    int k;
    string s, t;
    cin >> k >> s >> t;
    if(s == t) cout << "Yes\n";
    else{
        if(s.size() == t.size()){
            //need to be replace..
            int cnt = 0;
            for(int i=0;i<s.size();i++){
                if(s[i] != t[i]) cnt++;
            }
            if(cnt <= 1) cout << "Yes\n";
            else cout << "No\n";
        }else if(s.size() < t.size()){
            //need to be insert
            int p = 0;
            for(int i=0;i<t.size();i++){
                if(p < s.size() && t[i] == s[p]) p++;
            }
            if(p == s.size()) cout << "Yes\n";
            else cout << "No\n";
        }else{
            //need to delete
            int p = 0;
            for(int i=0;i<s.size();i++){
                if(p < t.size() && s[i] == t[p]) p++;
            }
            if(p == t.size()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

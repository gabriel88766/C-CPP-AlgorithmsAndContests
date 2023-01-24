#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    cin >> s;
    for(int j=0;j<26;j++){
        for(int i=0;i<s.size();i++){
            if(i < s.size() - 1 && s[i] == s[i+1]){
                cout << i+1 << " " << i+2;
                return 0;
            }
            if(i < s.size() -2 && s[i] == s[i+2]){
                cout << i+1 << " " << i+3;
                return 0;
            }
        }
    }
    cout << "-1 -1";
}

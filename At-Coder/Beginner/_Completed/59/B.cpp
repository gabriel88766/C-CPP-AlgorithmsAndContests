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
    string s1, s2;
    cin >> s1 >> s2;
    bool ok = false;
    if(s1.size() != s2.size()){
        ok = true;
        if(s1.size() < s2.size()) cout << "LESS";
        else cout << "GREATER";
    }
    if(!ok){
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                ok = true;
                if(s1[i] < s2[i]) cout << "LESS";
                else cout << "GREATER";
                break;
            }
        }
    }
    if(!ok) cout << "EQUAL";
}

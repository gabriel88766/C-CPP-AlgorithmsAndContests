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
    string s1 = "()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()";
    int t;
    cin >> t;
    while(t--){
        string t;
        cin >> t;
        if(t == s1.substr(0, size(t)) || t == s1.substr(1, size(t))){
            if((size(t) == 2) && (t[0] != ')')){
                cout << "NO\n";
            }else {
                cout << "YES\n";
                for(int i=0;i<size(t);i++) cout << "(";
                for(int i=0;i<size(t);i++) cout << ")";
                cout << "\n";
            }
        }else{
            cout << "YES\n";
            cout << s1.substr(0, 2*size(t)) << "\n";
        }
    }
}

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string ss = "abc";
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s, t;
    cin >> n >> s >> t;
    cout << "YES\n";
    if(s[0] != s[1] && t[0] != t[1] && (s[0] == t[0] || s[1] == t[1] || (s[0] == t[1] && s[1] == t[0]))){
        do{
            if(s != ss.substr(0, 2) && s != ss.substr(1, 2) && t != ss.substr(0, 2) && t != ss.substr(1, 2)){
                for(int i=0;i<n;i++) cout << ss[0];
                for(int i=0;i<n;i++) cout << ss[1];
                for(int i=0;i<n;i++) cout << ss[2];
                break;
            }
        }while(next_permutation(ss.begin(), ss.end()));
    }else{
        do{
            string aux = ss + ss[0];
            if(s != aux.substr(0, 2) && s != aux.substr(1, 2) && s != aux.substr(2, 2) &&\
                t != aux.substr(0, 2) && t != aux.substr(1, 2) && t != aux.substr(2, 2)){
                for(int i=0;i<n;i++) cout << ss;
                break; 
            }
        }while(next_permutation(ss.begin(), ss.end()));
    }
}

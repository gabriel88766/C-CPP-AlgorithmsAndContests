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
        string s1, s2;
        cin >> s1 >> s2;
        set<char> s;
        for(auto c : s1) s.insert(c);
        for(auto c : s2) s.insert(c);
        if(s.size() == 4) cout << "3\n";
        else if(s.size() == 3){
            cout << "2\n";
        }else if(s.size() == 2){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }
}

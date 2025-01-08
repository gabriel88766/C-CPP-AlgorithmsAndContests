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
        vector<int> p, s;
        string str;
        int n;
        cin >> n >> str;
        for(int i=0;i<n;i++){
            if(str[i] == 'p') p.push_back(i);
            else if(str[i] == 's') s.push_back(i);
        }
        if(s.size() == 0 || p.size() == 0) cout << "YES\n";
        else if(p[0] < s.back()) cout << "NO\n";
        else{
            //sss...ppp
            if(s.size() != 1 && p.size() != 1) cout << "NO\n";
            else{
                if(s.size() == 1 && s[0] == 0) cout << "YES\n";
                else if(p.size() == 1 && p[0] == n-1) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}
 
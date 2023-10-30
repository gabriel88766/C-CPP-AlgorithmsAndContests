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
        int m;
        cin >> m;
        string s1, s2;
        cin >> s1 >> s2;
        int p = 0;
        bool inited = false;
        set<char> pos;
        for(int i=0;i<s.size();i++){
            if(!inited){
                inited = true;
                if(p < m){
                    for(int j=s1[p];j<=s2[p];j++){
                        pos.insert(j);
                    }
                }else break;
            }
            if(pos.count(s[i])){
                pos.erase(s[i]);
            }
            if(pos.size() == 0){
                inited = false;
                p++;
            }
        }
        if(p < m) cout << "YES\n";
        else cout << "NO\n";
    }
}

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
    // t = 1;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        bool ok = true;
        vector<int> ind[26];
        for(int i=0;i<s.size();i++){
            ind[s[i]-'a'].push_back(i);
        }
        for(int i=0;i<26;i++){
            for(int j=1;j<ind[i].size();j++){
                if(ind[i][j]%2 != ind[i][j-1] % 2) ok = false;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

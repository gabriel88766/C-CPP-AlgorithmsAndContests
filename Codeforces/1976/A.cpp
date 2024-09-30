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
    vector<char> ord;
    for(char c='0';c<='9';c++) ord.push_back(c);
    for(char c='a';c<='z';c++) ord.push_back(c);
    map<char,int> mp;
    int cnt = 0;
    for(auto c : ord) mp[c] = ++cnt;
    int t;
    cin >> t;
    while(t--){
        string pass;
        int n;
        cin >> n >> pass;
        int l = 0;
        bool ok = true;
        for(auto c : pass){
            if(mp[c] >= l) l = mp[c];
            else ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

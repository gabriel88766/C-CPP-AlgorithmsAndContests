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
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for(auto &x : s) cnt[x-'a']++;
    for(char c = 'a'; c <= 'z'; c++){
        if(cnt[c-'a'] == 0){
            cout << c << "\n";
            break;
        }
    }
}
    
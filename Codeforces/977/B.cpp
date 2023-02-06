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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxqt = 0;
    string ans;
    map<string, int> mp;
    for(int i=1;i<n;i++){
        string cur = s.substr(i-1, 2);
        mp[cur]++;
        if(mp[cur] > maxqt){
            ans = cur;
            maxqt = mp[cur];
        }
    }
    cout << ans;
}

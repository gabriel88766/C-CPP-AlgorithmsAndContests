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
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    vector<int> d;
    int c = 0;
    for(int i=0;i<k;i++){
        int d1 = s[i] - 'a';
        int d2 = t[i] - 'a';
        int res = d1 + d2 + c;
        if(res >= 26 && i != (k-1)){
            res -= 26;
            c = 1;
        }else c = 0;
        d.push_back(res);
    }
    string ans;
    for(int i=k-1;i>=0;i--){
        int x = d[i]/2;
        ans += 'a' + x;
        if(i && d[i] % 2) d[i-1] += 26;
    }
    cout << ans << "\n";
}

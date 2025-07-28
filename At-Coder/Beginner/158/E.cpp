#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int qnt[10001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    qnt[0] = 1;
    reverse(s.begin(), s.end());
    if(p != 2 && p != 5){
        ll ans = 0;
        int m10 = 1, cur = 0;
        for(auto c : s){
            int d = c - '0';    
            cur += m10 * d;
            cur %= p;
            ans += qnt[cur]++;
            m10 = (m10 * 10) % p;
        }
        cout << ans << "\n";
    }else{
        vector<int> sp;
        if(p == 2) sp = {0, 2, 4, 6, 8};
        else sp = {0, 5};
        ll ans = 0;
        for(int j=0;j<s.size();j++){
            int tn = s.size() - j;
            bool ok = false;
            for(auto x : sp) if(x == s[j]-'0') ok = true;
            if(ok) ans += tn;
        }
        cout << ans << "\n";
    }

}

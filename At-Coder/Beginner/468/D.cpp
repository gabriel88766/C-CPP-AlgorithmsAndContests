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
    int ans = 0;
    //odd palin
    int n = s.size();
    for(int i=0;i<n;i++){
        ans++;
        int cc = 0;
        for(int j=1;;j++){
            if(i + j >= n || i - j < 0) break;
            if(s[i+j] != s[i-j])cc++;
            if(cc == 2) break;
            ans++;
        }
    }
    //even palin
    for(int i=0;i<n;i++){
        int cc = 0;
        for(int j=0;;j++){
            if(i + j + 1 >= n || i - j < 0) break;
            if(s[i + j + 1] != s[i - j]) cc++;
            if(cc == 2) break;
            ans++;
        }
    }
    cout << ans << "\n";
}

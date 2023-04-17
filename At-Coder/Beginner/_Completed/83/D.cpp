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
    int n = s.size(), p1, p2, ans;
    char x = s[n/2];
    if(n % 2){
        ans = (n+1)/2;
        p1 = n/2-1;
        p2 = n/2+1;
    }else{
        ans = n/2;
        p2 = n/2;
        p1 = n/2-1;
    }
    while(p1 >= 0){
        if(s[p1] == s[p2] && s[p1] == x){
            p2++;
            p1--;
            ans++;
        }else break;
    }
    cout << ans;
}

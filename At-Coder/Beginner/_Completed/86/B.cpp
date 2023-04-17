#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int toInt(string s){
    int ans = 0;
    for(int i=0;i<s.size();i++){
        ans *= 10;
        ans += (s[i]-'0');
    }
    return ans;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string a, b;
    cin >> a >> b;
    int ans = toInt(a+b);
    int c = sqrt(ans);
    while(c*c <= ans){
        if(c*c == ans){
            cout << "Yes\n";
            return 0;
        }
        c++;
    }
    cout << "No\n";
}

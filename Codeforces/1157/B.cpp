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
    int n;
    string s;
    bool st = false;
    vector<int> f(10);
    cin >> n;
    cin >> s;
    for(int i=1;i<=9;i++) cin >> f[i];
    for(int i=0;i<s.size();i++){
        int cn = s[i] - '0';
        if(f[cn] > cn){
            st = true;
            s[i] += (f[cn]-cn);
        }else if(f[cn] < cn && st) break;
    }
    cout << s;
}

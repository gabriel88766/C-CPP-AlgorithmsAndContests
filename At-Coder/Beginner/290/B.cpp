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
    int n, k, cnt = 0;
    string s;
    cin >> n >> k >> s;
    for(int i=0;i<n;i++){
        if(s[i] == 'o'){
            if(cnt == k) s[i] = 'x';
            else cnt++;
        }
    }
    cout << s;
}

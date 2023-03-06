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
    string s;
    cin >> s;
    int n = s.size();
    int mina = n-1, maxz = 0;

    for(int i=(n-1);i>=0;i--) if(s[i] == 'A') mina =i;
    for(int i=0;i<n;i++) if(s[i] == 'Z') maxz = i;
    cout << maxz-mina+1;
}

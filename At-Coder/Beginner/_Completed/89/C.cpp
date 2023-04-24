#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char m[] = {'M', 'A', 'R', 'C', 'H'};
ll v[5];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<5;j++){
            if(s[0] == m[j]) v[j]++;
        }
    }
    ll ans = 0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
               ans += v[i]*v[j]*v[k]; 
            }
        }
    }
    cout << ans;
}

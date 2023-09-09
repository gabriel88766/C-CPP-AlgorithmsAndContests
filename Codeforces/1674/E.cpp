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
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = INF_INT;
    //1st pos  o...OXO..OXOO..
    vector<int> qt;
    for(int i=0;i<n;i++){
        qt.push_back(v[i]/2 + v[i]%2);
    }
    sort(qt.begin(), qt.end());
    ans = min(ans, qt[0] + qt[1]);
    //2nd pos O...OXXO....O
    for(int i=1;i<n;i++){
        int dif = abs(v[i] - v[i-1]);
        if(v[i] > v[i-1]){
            if(v[i] <= 2*dif){
                ans = min(ans, v[i] %)
            }
        }else{

        }
    }
}

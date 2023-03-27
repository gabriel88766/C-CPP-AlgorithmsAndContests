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
    ll maxv = 0, sum1 = 0, sum2 = 0;
    int bp = 0, ep = n-1;
    while(bp <= ep){
        if(sum1 == sum2){
            maxv = sum1;
            sum1 += v[bp++];
        }else if(sum1 < sum2) sum1 += v[bp++];
        else sum2 += v[ep--];
    }
    if(sum1 == sum2) maxv = sum1;
    cout << maxv;
}

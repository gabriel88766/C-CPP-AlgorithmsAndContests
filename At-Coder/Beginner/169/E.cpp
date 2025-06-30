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
    vector<int> v1(n), v2(n);
    for(int i=0;i<n;i++){
        cin >> v1[i] >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int m1, m2;
    if(n % 2){
        m1 = v1[n/2];
        m2 = v2[n/2];
    }else{
        m1 = v1[n/2] + v1[n/2 - 1];
        m2 = v2[n/2] + v2[n/2 - 1];
    }
    cout << m2-m1+1 << "\n";
}

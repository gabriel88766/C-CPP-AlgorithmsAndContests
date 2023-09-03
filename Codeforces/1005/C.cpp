#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

map<int, int> mp;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0; j<= 30; j++){
            int d = 1 << j;
            if(d <= v[i]) continue;
            int x = d-v[i];
            if(mp.count(x)){
               if(v[i] != x){
                    ans++;
                    break;
               }else if(mp[x] >= 2){ ans++; break;}
            }
        }
    }
    cout << n-ans;

}

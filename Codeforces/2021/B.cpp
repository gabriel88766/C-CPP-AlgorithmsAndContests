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
    int t;
    cin >> t;
    while(t--){
        map<int,int> mp;
        int n, x;
        cin >> n >> x;
        for(int i=0;i<n;i++){
            int k;
            cin >> k;
            mp[k]++;
        }
        for(int i=0;;i++){
            if(!mp.count(i)){
                cout << i << "\n";
                break;
            }else{
                if(mp[i] > 1) mp[i+x] += mp[i] - 1;
            }
        }
    }
}

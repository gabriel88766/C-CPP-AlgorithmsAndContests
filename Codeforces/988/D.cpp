#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int MaxInt = 1e9+1;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    map<int, int> mp;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        mp[v[i]] = 1;
    }
    bool ok2 = false, ok3 = false;
    int ans2[2], ans3[3];
    //check for pair
    for(int i=0;i<n;i++){
        if(ok2) break;
        for(int j=1; j + v[i] <= MaxInt; j <<= 1){
            if(mp.count(v[i] + j)){
                ans2[0] = v[i];
                ans2[1] = v[i] + j;
                ok2 = true;
                break; 
            }
        }
    }
    //check for three
    for(int i=0;i<n;i++){
        if(ok3) break;
        for(int j=1; (2*j + v[i]) <= MaxInt; j <<= 1){
            if(mp.count(v[i] + j) && mp.count(v[i] + 2*j)){
                ans3[0] = v[i];
                ans3[1] = v[i] + j;
                ans3[2] = v[i] + 2*j;
                ok3 = true;
                break; 
            }
        }
    }

    if(ok3){
        cout << 3 << "\n" << ans3[0] << " " << ans3[1] << " " << ans3[2];
    }else if(ok2){
        cout << 2 << "\n" << ans2[0] << " " << ans2[1];
    }else{
        cout << 1 << "\n" << v[0];
    }
}

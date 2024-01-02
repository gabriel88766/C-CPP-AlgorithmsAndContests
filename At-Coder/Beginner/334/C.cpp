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
    int k, n;
    cin >> n >> k;
    vector<int> cnt(n+1, 2);
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        cnt[x]--;
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(cnt[i] == 1) v.push_back(i);
        else if(cnt[i] == 2){
            v.push_back(i);
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    if(!(v.size() % 2)){
        ll ans = 0;
        for(int i=1;i<v.size();i+=2) ans += v[i] - v[i-1];
        cout << ans << "\n";
    }else{
        //exclude 1 sock
        ll cans = 0, ans;
        for(int i=2;i<v.size();i+=2) cans += v[i] - v[i-1];
        ans = cans;
        for(int i=1;i<v.size();i++){
            // 1 in place of 0, and so on
            if(i % 2){
                cans -= v[i+1] - v[i];
                cans += v[i+1] - v[i-1];
            }else{
                cans -= v[i] - v[i-2];
                cans += v[i-1] - v[i-2];
            }
            ans = min(ans, cans);
        }
        cout << ans << "\n";
    }
}

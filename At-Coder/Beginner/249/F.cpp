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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> vp(n+1);
    vp[0] = {1, 0};
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b};
    }
    int crp = 0;
    for(int i=0;i<=n;i++) if(vp[i].first == 1) crp++;
    ll ans = -INF_LL;
    multiset<int> s1, s2;
    ll sum = 0;
    for(int i=0;i<=n;i++){
        if(vp[i].first == 2){
            sum += vp[i].second;
            s1.insert(vp[i].second);
        }
    }
    for(int i=0;i<=n;i++){
        if(vp[i].first == 1){
            crp--; //replaces to skip.
            // i is the last replace.
            // i operations not skipped.
            // skip all replaces from [i+1, n]
            // skip the lowest add, up to 0
            ll cur = vp[i].second;
            if(crp > k) continue; //cant be last replace;
            while(crp + s2.size() < k){
                if(s1.size() && *s1.begin() < 0){
                    sum -= *s1.begin();
                    s2.insert(*s1.begin());
                    s1.erase(s1.begin());
                }else break;
            }
            ans = max(ans, cur + sum);
        }else{
            
            if(s1.find(vp[i].second) != s1.end()){ 
                sum -= vp[i].second;
                s1.erase(s1.find(vp[i].second));
            }else s2.erase(s2.find(vp[i].second));
        }
    }
    cout << ans << "\n";
}

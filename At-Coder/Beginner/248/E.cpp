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
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    int ans = 0;
    if(k == 1) cout << "Infinity\n";
    else{
        for(int i=0;i<n;i++){
            map<pair<int,int>, int> mp;
            set<pair<int,int>> st;
            for(int j=0;j<i;j++){
                int dx = vp[i].first - vp[j].first;
                int dy = vp[i].second - vp[j].second;
                if(dx == 0 || dy == 0){
                    if(dx == 0){
                        st.insert({0, 1});
                    }else{
                        st.insert({1, 0});
                    }
                }else{
                    if(dx < 0){
                        dx = -dx;
                        dy = -dy;
                    }
                    int g = gcd(abs(dx), abs(dy));
                    dx /= g;
                    dy /= g;
                    st.insert({dx, dy});
                }
            }
            for(int j=i+1;j<n;j++){
                int dx = vp[i].first - vp[j].first;
                int dy = vp[i].second - vp[j].second;
                if(dx == 0 || dy == 0){
                    if(dx == 0){
                        mp[{0, 1}]++;;
                    }else{
                        mp[{1, 0}]++;
                    }
                }else{
                    if(dx < 0){
                        dx = -dx;
                        dy = -dy;
                    }
                    int g = gcd(abs(dx), abs(dy));
                    dx /= g;
                    dy /= g;
                    mp[{dx, dy}]++;
                }
            }
            for(auto [key, v] : mp){
                if(v >= k-1 && (!st.count(key))) ans++;
            }
        }
        cout << ans << "\n";
    }
}

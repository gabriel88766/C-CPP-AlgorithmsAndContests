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
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    vector<pair<int, int>> vx;
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pair<int, int> cp;
            if(v[j].first == v[i].first) cp = {0, 1};
            else if(v[j].second == v[i].second) cp = {1, 0};
            else{
                cp = {v[i].first - v[j].first, v[i].second - v[j].second};
                if(cp.first < 0){
                    cp.first = -cp.first;
                    cp.second =  -cp.second;
                }
                int g = gcd(abs(cp.first), abs(cp.second));
                cp.first /= g;
                cp.second /= g;
            }
            // ans += mp[cp]++;
            vx.push_back(cp);
        }
    }
    sort(vx.begin(), vx.end());
    int cc = 1;
    for(int i=1;i<vx.size();i++){
        if(vx[i] == vx[i-1]) cc++;
        else cc = 1;
        ans += (cc-1);
    }
    ll cnt2 = 0;
    vx.clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            pair<int, int> cp = {v[i].first - v[j].first, v[i].second - v[j].second};
            vx.push_back(cp);
        }
    }
    sort(vx.begin(), vx.end());
    cc = 1;
    for(int i=1;i<vx.size();i++){
        if(vx[i] == vx[i-1]) cc++;
        else cc = 1;
        cnt2 += (cc-1);
    }
    cnt2 /= 4;
    cout << ans - cnt2 << "\n";
}

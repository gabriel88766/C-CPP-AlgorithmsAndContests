#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Triple{
    int x, y, z;
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<Triple> v(n);
    int ans1 = -1, ans2 = -1, r = 0;
    map<pair<int,int>, pair<int,int>> mp;
    for(int i=0;i<n;i++){
        cin >> v[i].x >> v[i].y >> v[i].z;
        int val = min(v[i].x, min(v[i].y, v[i].z));
        pair<int,int> p1 = {max(v[i].x, v[i].y), min(v[i].x, v[i].y)};
        pair<int,int> p2 = {max(v[i].x, v[i].z), min(v[i].x, v[i].z)};
        pair<int,int> p3 = {max(v[i].y, v[i].z), min(v[i].y, v[i].z)};
        if(val > r){
            ans1 = i+1;
            ans2 = -1;
            r = val;
        }
        if(mp.count(p1)){
            int minv = min(mp[p1].first + v[i].z, p1.second);
            if(minv > r){
                r = minv;
                ans1 = mp[p1].second;
                ans2 = i+1;
            }
        }
        mp[p1] = max(mp[p1], make_pair(v[i].z, i+1));
        if(mp.count(p2)){
            int minv = min(mp[p2].first + v[i].y, p2.second);
            if(minv > r){
                r = minv;
                ans1 = mp[p2].second;
                ans2 = i+1;
            }
        }
        mp[p2] = max(mp[p2], make_pair(v[i].y, i+1));
        if(mp.count(p3)){
            int minv = min(mp[p3].first + v[i].x, p3.second);
            if(minv > r){
                r = minv;
                ans1 = mp[p3].second;
                ans2 = i+1;
            }
        }
        mp[p3] = max(mp[p3], make_pair(v[i].x, i+1));
    }
    if(ans2 == -1){
        cout << "1\n";
        cout << ans1 << "\n";
    }else{
         cout << "2\n";
         cout << ans1 << " " << ans2 << "\n";
    }
}

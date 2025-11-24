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
        pair<ll, ll> pts[4];
        vector<ll> v1, v2;
        for(int i=0;i<4;i++){
            cin >> pts[i].first >> pts[i].second;
            v1.push_back(pts[i].first);
            v2.push_back(pts[i].second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        ll X = v1[1], Y = v2[1];
        ll total = 0;
        for(int i=0;i<4;i++){
            total += abs(pts[i].first - X);
            total += abs(pts[i].second - Y);
        }
        ll ans = INF_LL;
        vector<int> perm = {0, 1, 2, 3};
        do{ //24 possibilities, solve in O(24*t)
            //2  3
            //
            //0  1
            ll cur = total;
            ll t2x = 0, t1x = 0;
            ll t2y = 0, t1y = 0;
            if(max(pts[perm[0]].first, pts[perm[2]].first) <= X){
                ll cur = X - max(pts[perm[0]].first, pts[perm[2]].first);
                t2x += cur;
                t1x += X - min(pts[perm[0]].first, pts[perm[2]].first);
                t1x -= cur;
            }else if(min(pts[perm[0]].first, pts[perm[2]].first) <= X){
                t1x += X - min(pts[perm[0]].first, pts[perm[2]].first);
            }

            if(min(pts[perm[1]].first, pts[perm[3]].first) >= X){
                ll cur = min(pts[perm[1]].first, pts[perm[3]].first) - X;
                t2x += cur;
                t1x += max(pts[perm[1]].first, pts[perm[3]].first) - X;
                t1x -= cur;
            }else if(max(pts[perm[1]].first, pts[perm[3]].first) >= X){
                t1x += max(pts[perm[1]].first, pts[perm[3]].first) - X;
            }


            // NOW Y
            if(max(pts[perm[0]].second, pts[perm[1]].second) <= Y){
                ll cur = Y - max(pts[perm[0]].second, pts[perm[1]].second);
                t2y += cur;
                t1y += Y - min(pts[perm[0]].second, pts[perm[1]].second);
                t1y -= cur;
            }else if(min(pts[perm[0]].second, pts[perm[1]].second) <= Y){
                t1y += Y - min(pts[perm[0]].second, pts[perm[1]].second);
            }

            if(min(pts[perm[2]].second, pts[perm[3]].second) >= Y){
                ll cur = min(pts[perm[2]].second, pts[perm[3]].second) - Y;
                t2y += cur;
                t1y += max(pts[perm[2]].second, pts[perm[3]].second) - Y;
                t1y -= cur;
            }else if(max(pts[perm[2]].second, pts[perm[3]].second) >= Y){
                t1y += max(pts[perm[2]].second, pts[perm[3]].second) - Y;
            }

            if(t2x >= t2y){
                cur -= t2y * 4;
                cur -= 2*min(t2x - t2y, t1y);
            }else{
                cur -= t2x * 4;
                cur -= 2*min(t2y - t2x, t1x);
            }
            ans = min(ans, cur);


        }while(next_permutation(perm.begin(), perm.end()));
        cout << ans << "\n";
    }
}

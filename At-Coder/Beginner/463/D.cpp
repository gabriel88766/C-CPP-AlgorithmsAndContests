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
    vector<pair<int, int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), [&](pair<int, int> &p, pair<int, int> &q){
        if(p.second != q.second) return p.second < q.second;
        else return p.first < q.first;
    });
    reverse(vp.begin(), vp.end());
    auto check = [](vector<pair<int, int>> vec, int gap){
        int cnt = 0;
        int bg = 0;
        while(vec.size()){
            if(vec.back().first < bg) vec.pop_back();
            else{
                cnt++;
                bg = vec.back().second + gap;
                vec.pop_back();
            }
        }
        return cnt;
    };
    ll lo = 0, hi = INF_INT;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        //check if mid is ok
        int cnt = check(vp, mid);
        if(cnt >= k) lo = mid;
        else hi = mid - 1;
    }
    if(lo != 0) cout << lo << "\n";
    else cout << "-1\n";
}

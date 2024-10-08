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
    //waf
    int n, r;
    cin >> n >> r;
    vector<pair<int,int>> pos, neg;
    for(int i=1;i<=n;i++){
        int mr, rg;
        cin >> mr >> rg;
        if(rg >= 0){
            pos.push_back({mr, rg});
        }else {
            neg.push_back({mr, rg});
        }
    }
    sort(pos.begin(), pos.end(), [&](pair<int,int> &u, pair<int,int> &v){
        return u.first < v.first;
    });
    //positive, trivial
    int cnt = 0;
    for(auto [x, y] : pos){
        if(r >= x){
            r += y;
            cnt++;
        }
    }
    if(cnt < pos.size()) cout << "NO\n";
    else{
        int rl = 0;
        for(auto x: neg) rl -= x.second;
        if(rl > r) cout << "NO\n";
        else{
            //how to solve this  S*** here ???
            sort(neg.begin(), neg.end(), [&](const pair<int,int> &u, const pair<int,int> &v){
                return u.first + u.second > v.first + v.second;
            });
            for(auto [x, y] : neg){
                if(r >= x){
                    cnt++;
                    r += y;
                }
            }
            if(cnt == n) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

//Unsolved!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
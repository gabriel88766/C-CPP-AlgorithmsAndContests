#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


bool solve(multiset<pair<int,int>> s, int r){
    if(s.size() <= 1){
        if(s.size() == 0) return true;
        else if(r + s.begin()->second >= 0 && r >= s.begin()->first) return true;
        else return false;
    }
    multiset<pair<int,int>> s1, s2;
    auto beg = prev(s.end());
    int oldr = r;
    for(auto it = prev(beg); ; --it){
        if(r+beg->second < it->first){
             s1.insert(*it);
             r += it->second;
        }else s2.insert(*it);
        if(it == s.begin()) break;
    }
    if(!solve(s1, oldr)) return false;
    if(r < beg->first || (r+beg->second) < 0) return false;
    r += beg->second;
    return solve(s2, r);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //waf
    int n, r;
    cin >> n >> r;
    multiset<pair<int,int>> pos, neg;
    for(int i=1;i<=n;i++){
        int mr, rg;
        cin >> mr >> rg;
        if(rg >= 0){
            pos.insert({mr, rg});
        }else {
            neg.insert({mr, rg});
        }
    }
    //positive, trivial
    int cnt = 0;
    while(pos.size()){
        if(pos.begin()->first <= r){
            cnt++;
            r += pos.begin()->second;
            pos.erase(pos.begin());
        }else break;
    }
    //negative *O*
    if(pos.size()) cout << "NO\n";
    else{
        int rl = 0;
        for(auto x: neg) rl -= x.second;
        if(rl > r) cout << "NO\n";
        else{
            //how to solve this  S*** here ???
            if(solve(neg, r)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

//Unsolved!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
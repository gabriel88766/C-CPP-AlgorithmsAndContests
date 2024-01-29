#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int k;
bool insert(multiset<pair<int,int>> &ms, int num){
    auto it = ms.lower_bound({num, 0});
    if(it != ms.end() && it->first == num && it->second < k){
        auto p = *it;
        p.second++;
        ms.erase(it);
        ms.insert(p);
        return false;
    }else{
        ms.insert({num, 1});
        return true;
    }
}

bool erase(multiset<pair<int,int>> &ms, int num){
    auto it = ms.lower_bound({num, 0});
    if(it != ms.end() && it->first == num){
        auto p = *it;
        p.second--;
        if(p.second == 0){
            ms.erase(it);
            return true;
        }else{
            ms.erase(it);
            ms.insert(p);
            return false;
        }
    }else{
        assert(1 == 0);
        return false;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m >> k;
    vector<int> v(n);
    vector<int> cnt(n+1);
    for(int i=0;i<n;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    int tt = 0;
    for(int i=1;i<=n;i++) tt += (cnt[i] + k-1)/k;
    if(tt <= m){
        for(int i=0;i<n;i++) cout << n << "\n";
        return 0;
    }
    vector<int> ans(n);
    int p = 0;
    multiset<pair<int,int>> curs;
    int cans = 0;
    vector<int> ins(n+1);
    for(int i=0;;i++){
        int np = i % n;
        //check if v[np] will make the mset grows
        if(insert(curs, v[np])){
            while(curs.size() > m){
                ans[p] = cans;
                if(erase(curs, v[p])){
                    ins[v[p]]--;
                    int dif = min(cnt[v[p]] - ins[v[p]] * k, k);
                    cans -= dif;
                }
                p++;
                if(p == n) break;
            }
            if(p == n) break;
            int dif = min(cnt[v[np]] - ins[v[np]] * k, k);
            cans += dif;
            ins[v[np]]++;
        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << "\n";
}

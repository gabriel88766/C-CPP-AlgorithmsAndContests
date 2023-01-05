#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    set<int> s;
    set<int> maxl;
    map<int,int> mp;
    int n, x;
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    maxl.insert(x);
    mp[x]++;

    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        auto it = s.upper_bound(aux);
        int high = *it--;
        int lo = *it;
        s.insert(aux);
        mp[aux-lo]++;
        maxl.insert(aux-lo);
        mp[high-aux]++;
        maxl.insert(high-aux);
        
        mp[high-lo]--;
        if(!mp[high-lo]) maxl.erase(high-lo);

        cout << *maxl.rbegin() << " ";
    }
}

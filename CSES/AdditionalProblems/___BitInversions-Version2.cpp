#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

set<int> diff;
multiset<int> ms;
int n;


void modify(int i){
    if(i == 0 || i == n) return;
    auto it = diff.find(i);
    if(it != diff.end()){
        int a = *next(it), b = *prev(it), c = *it;
        ms.erase(ms.find(a - c)), ms.erase(ms.find(c - b));
        ms.insert(a - b);
        diff.erase(c);
    }else{
        diff.insert(i);
        it = diff.find(i);
        int a = *next(it), b = *prev(it), c = *it;
        ms.erase(ms.find(a - b));
        ms.insert(a - c), ms.insert(c - b);
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    int q;
    cin >> s >> q;
    n = s.size();
    //initial set
    
    diff.insert(0), diff.insert(n);
    for(int i=1;i<n;i++) if(s[i] != s[i-1]) diff.insert(i);
    for(auto it = diff.begin(); next(it) != diff.end(); it++){
        ms.insert(*next(it) - *it);
    }
    for(int i=1;i<=q;i++){
        int cur;
        cin >> cur;
        modify(cur-1);
        modify(cur);
        cout << *ms.rbegin() << " ";
    }
}

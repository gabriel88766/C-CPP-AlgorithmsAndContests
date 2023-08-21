#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
 
ll bit[N];
ll v[N];
ll mp[N];
int n;
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
 
void add(int b, ll value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    int qt1 = 0;
    int rl = 0;
    set<int> aux;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            qt1++;
        }
        aux.insert(i+1);
    }
    //string t processing
    vector<int> order;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        queue<int> rml;
        for(auto it = aux.lower_bound(a); it != aux.end(); ++it){
            if(*it > b) break;
            order.push_back(*it);
            rml.push(*it);
        }
        while(!rml.empty()){
            aux.erase(rml.front());
            rml.pop();
        }
    }
    rl = order.size();
    for(int i=0;i<order.size();i++){
        mp[order[i]] = i+1;
        if(s[order[i]-1] == '1') add(i+1, 1);
    }
    //queries
    for(int i=0;i<q;i++){
        int sx;
        cin >> sx;
        if(s[sx-1] == '0'){
            s[sx-1] = '1';
            qt1++;
        }else{
            s[sx-1] = '0';
            qt1--;
        }
        if(mp[sx]){
            if(s[sx-1] == '1') add(mp[sx], 1);
            else add(mp[sx], -1);
        }
        int tt1 = min(qt1, rl);
        cout << tt1-query(tt1) << "\n";
    }



}

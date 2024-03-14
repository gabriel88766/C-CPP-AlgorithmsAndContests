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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> seq;
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]) seq.insert(i+1);
    }
    for(int i=0;i<q;i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            if(l != 1){
                if(seq.count(l-1)){
                    seq.erase(l-1);
                }else{
                    seq.insert(l-1);
                }
            }
            if(r != n){
                if(seq.count(r)){
                    seq.erase(r);
                }else{
                    seq.insert(r);
                }
            }
        }else{
            auto it = seq.lower_bound(l);
            if(it == seq.end() || *it >= r) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

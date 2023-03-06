#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+6;
 
ll bit[N][3];
int n;
 
ll query(int b, int t){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i][t];
    }
    return ans;
}
 
ll query(int a, int b, int t){
    return query(b,t) - query(a-1,t);
}

void add(int b, ll value, int t){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i][t] += value;
    }
}

void destroy(){
    for(int i=1;i<=n;i++) for(int j=0;j<3;j++) bit[i][j] = 0;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> n >> s >> t;
        for(int i=(n-1);i>=0;i--){
            if(s[i] == 'c') add(i+1, 1, 2);
            else if(s[i] == 'b') add(i+1, 1, 1);
            else add(i+1, 1, 0);
        }
        bool ok = true;
        int pa = n, pb = n;
        for(int i=(n-1);i>=0;i--){
            if(t[i] == s[i]) continue;
            else{
                pa = min(pa, i);
                pb = min(pb, i);
                if(t[i] > s[i]){
                    ok = false;
                    break;
                }else if(t[i] == 'b'){
                    while(pb > 0 && s[pb] != 'b') pb--;
                    if(query(pb+1, i+1, 0) > 0){
                        ok = false;
                        break;
                    }
                    if(s[pb] != 'b'){
                        ok = false;
                        break;
                    }
                    swap(s[pb], s[i]);
                    add(pb+1, 1, s[pb]-'a');
                }else{
                    while(pa > 0 && s[pa] != 'a') pa--;
                    if(query(pa+1, i+1, 2) > 0){
                        ok = false;
                        break;
                    }
                    if(s[pa] != 'a'){
                        ok = false;
                        break;
                    }
                    swap(s[pa], s[i]);
                    add(pa+1, 1, s[pa]-'a');
                }
                
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        destroy();
    }
}

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
set<int> s[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x; 
        s[i].insert(x);
    }
    for(int i=0;i<q;i++){
        //merge a and b
        int a, b;
        cin >> a >> b;
        if(s[a].size() > s[b].size()){
            s[a].swap(s[b]);
        }
        for(auto x : s[a]) s[b].insert(x);
        s[a].clear();
        cout << s[b].size() << "\n";
    }
}   

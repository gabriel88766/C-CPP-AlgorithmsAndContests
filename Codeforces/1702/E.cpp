#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
multiset<int> ms[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool ok = true;
        vector<int> cnt(n+1, 0);
        vector<bool> okv(n+1, false);
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            cnt[a]++, cnt[b]++;
            ms[a].insert(b);
            ms[b].insert(a);
            if(a == b) ok = false;
        }
        for(int i=1;i<=n;i++) if(cnt[i] >= 3){ok = false; break;}
        if(!ok){
            cout << "NO\n";
            for(int i=1;i<=n;i++) ms[i].clear();
            continue;
        }

    }
}

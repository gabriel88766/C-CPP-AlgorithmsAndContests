#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int a[N], b[N];
int sza[N], szb[N];
int na[N], nb[N];
bool oksz[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(a[i]);
        sza[i] = s.size();
        if(sza[i] != sza[i-1]) na[sza[i]] = a[i];
    }
    s.clear();
    for(int i=1;i<=n;i++){
        s.insert(b[i]);
        szb[i] = s.size();
        if(szb[i] != szb[i-1]) nb[szb[i]] = b[i];
    }
    int mx;
    for(int i=1;i<=n;i++){
        if(na[i] && nb[i]) mx = i;
        else break;
    }
    set<int> sa, sb;
    for(int i=1;i<=mx;i++){
        if(na[i] == nb[i]);
        else{
            if(sb.count(na[i])) sb.erase(na[i]);
            else sa.insert(na[i]);
            if(sa.count(nb[i])) sa.erase(nb[i]);
            else sb.insert(nb[i]);
        }
        assert(sa.size() == sb.size());
        if(sa.size() == 0){
            oksz[i] = true;
        }
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int x, y;
        cin >> x >> y;
        if(sza[x] == szb[y]){
            if(oksz[sza[x]]) cout << "Yes\n";
            else cout << "No\n";
        }else cout << "No\n";
    }
}

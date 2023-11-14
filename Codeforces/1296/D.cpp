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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<int> sk;
    int c = a+b;
    for(int i=0;i<n;i++){
        int lh = h[i] - (h[i]/c)*c;
        if(lh == 0) lh += c;
        sk.push_back((lh-1)/a);
    }
    sort(sk.begin(), sk.end());
    //for(auto x : sk) cout << x << " ";
    //cout << "\n";
    int ans = 0;
    while(ans < sk.size() && k >= sk[ans]){
        k -= sk[ans++];
    }
    cout << ans << "\n";
}

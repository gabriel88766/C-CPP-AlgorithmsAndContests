#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> odd[N], even[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i % 2) odd[v[i]].push_back(i);
        else even[v[i]].push_back(i);
    }
    bool oddv = false;
    if(k % 2) oddv = true;
    ll ans = 0;
    for(int i=0;i<n;i++){
        int l1, r1;
        l1 = max(0, k-n+i);
        r1 = min(k-1, i);
        if(l1 >= k/2) break; 
        int l = max(0,k-1-2*r1);
        int r = min(k-1, k-1-2*l1);
        if(oddv) l = max(l, 2);
        else l = max(l, 1);
        
        int cnt;
        if(oddv ^ !(i%2)){
            auto it = lower_bound(odd[v[i]].begin(), odd[v[i]].end(), i+l);
            cnt = upper_bound(odd[v[i]].begin(), odd[v[i]].end(), i+r) - it;
        }else{
            auto it = lower_bound(even[v[i]].begin(), even[v[i]].end(), i+l);
            cnt = upper_bound(even[v[i]].begin(), even[v[i]].end(), i+r) - it;
        }
        ans += (r-l)/2+1- cnt;
    }
    cout << ans;
}   

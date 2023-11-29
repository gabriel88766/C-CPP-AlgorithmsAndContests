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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    multiset<ll> gr, ls;
    int k, l;
    ll sum1 = 0, sum2 = 0;
    cin >> k >> l;
    for(int i=0;i<k;i++){
        sum1 += a[i];
        if(gr.size() < l){
            sum2 += b[i];
            gr.insert(b[i]);
        }else{
            if(b[i] > *gr.begin()){
                sum2 += b[i] - *gr.begin();
                ls.insert(*gr.begin());
                gr.erase(gr.begin());
                gr.insert(b[i]);
            }else ls.insert(b[i]);
        }
    }
    ll ans = sum1 + sum2;
    //Sliding window;
    for(int i=n-1;i>=n-k;i--){
        //erase p = k-1 - ((n-1) - i) = k-1-n+1+i = k+i-n 
        int p = k+i-n;
        sum1 -= a[p];
        sum1 += a[i];
        if(*gr.begin() > b[p]){//b[p] in ls
            ls.erase(ls.lower_bound(b[p]));
        }else{
            sum2 -= b[p];
            gr.erase(gr.lower_bound(b[p]));
            if(ls.size()){
                auto val = *prev(ls.end());
                sum2 += val;
                gr.insert(val);
                ls.erase(prev(ls.end()));
            }
        }
        if(gr.size() < l){
            sum2 += b[i];
            gr.insert(b[i]);
        }else{
            if(b[i] > *gr.begin()){
                sum2 += b[i] - *gr.begin();
                ls.insert(*gr.begin());
                gr.erase(gr.begin());
                gr.insert(b[i]);
            }else ls.insert(b[i]);
        }
        ans = max(ans, sum1 + sum2);
    }
    cout << ans << "\n";
}

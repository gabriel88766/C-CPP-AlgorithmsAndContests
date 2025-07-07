#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        //if a number is not greater than or equal the kth smallest, then it is not removable.
        //mark all removable numbers. 
        //remember you can't remove more than n-k+1 numbers
        //try to make palindrome
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        auto x = v;
        sort(x.begin(), x.end());
        int kth = x[k-1];
        vector<int> vx;
        for(int i=0;i<n;i++){
            if(v[i] < kth) vx.push_back(v[i]);
        }
        auto aux = vx;
        reverse(aux.begin(), aux.end());
        if(aux == vx){
            int p0 = 0, p1 = n-1;
            int mxs = vx.size();
            while(p0 <= p1){
                int f0 = -1, f1 = -1;
                for(int j=p0;j<=p1;j++){
                    if(v[j] < kth){
                        f0 = j;
                        break;
                    }
                }
                for(int j=p1;j>=p0;j--){
                    if(v[j] < kth){
                        f1 = j;
                        break;
                    }
                }
                if(f0 == -1){
                    int cnt = 0;
                    for(int i=p0;i<=p1;i++) if(kth == v[i]) cnt++;
                    mxs += cnt;
                    p1 = p0 - 1;
                }else{
                    int px1 = 0, px2 = 0;
                    if(p0 != f0 && p1 != f1){
                        for(int j=p0;j<f0;j++){
                            if(kth == v[j]) px1++;
                        }
                        for(int j=f1+1;j<=p1;j++){
                            if(kth == v[j]) px2++;
                        }
                    }
                    mxs += 2*min(px1, px2);
                    p0 = f0 + 1;
                    p1 = f1 - 1;
                }
                
            }
            if(mxs + 1 >= k) cout << "YES\n";
            else cout << "NO\n";
        }else cout << "NO\n";
    }
}

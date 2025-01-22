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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int j=0;j<m;j++) cin >> b[j];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ma = n/2, mb = m/2;
        vector<ll> Sa(ma + 1), Sb(mb + 1);
        vector<ll> ca(ma + 1), cb(mb + 1);
        for(int i=1;i<=ma;i++){
            Sa[i] = Sa[i-1];
            ca[i] = a[n-i] - a[i-1];
            Sa[i] += ca[i];
        }
        for(int i=1;i<=mb;i++){
            Sb[i] = Sb[i-1];
            cb[i] = b[m-i] - b[i-1];
            Sb[i] += cb[i];
        }
        vector<int> mxb(ma+1);
        vector<int> mxal(ma + 1, -1);
        for(int i=0;i<=ma;i++){
            int kb = m - i;
            if(kb < 0) mxb[i] = -1; //impossible;
            else mxb[i] = min(kb/2, n - 2*i);
            if(mxb[i] != -1) mxal[i] = mxb[i] + i;
            else mxal[i] = -INF_INT;
        }
        int kmax = 0;
        int mi = 0;
        for(int i=0;i<=ma;i++){
            if(mxb[i] != -1){
                kmax = max(kmax, mxb[i] + i);
                if(kmax == mxb[i] + i) mi = i;
            }
        }
        cout << kmax << "\n";
        //solve?
        int p1 = 0, p2 = 0;
        bool flag = false;
        int type;
        ll ans = 0;
        for(int i=1;i<=kmax;i++){
            if(!flag){
                if(p1 + 1 <= ma && p2 + 1 <= mb){
                    if(ca[p1+1] >= cb[p2+1]){
                        ans += ca[p1+1];
                        p1++;
                    }else{
                        ans += cb[p2+1];
                        p2++;
                    }
                }else if(p1 + 1 <= ma){
                    ans += ca[p1+1];
                    p1++;
                }else{
                    ans += cb[p2+1];
                    p2++;
                }
                if(mxb[p1] < p2){
                    flag = true;
                    if(p1 < mi) type = 1; //increase p1 decrease p2
                    else type = 2; //increase p2 decrease p1
                    if(type == 1){
                        while(p1 + mxb[p1] < i) p1++;
                    }else{
                        while(p1 + mxb[p1] < i) p1--;
                    }
                    assert(mxb[p1] >= 0);
                    cout << Sa[p1] + Sb[i-p1] << " ";
                }else cout << ans << " ";
            }else{
                if(type == 1){
                    while(p1 + mxb[p1] < i) p1++;
                }else{
                    while(p1 + mxb[p1] < i) p1--;
                }
                assert(mxb[p1] >= 0);
                cout << Sa[p1] + Sb[i-p1] << " ";
            }
        }
        cout << "\n";
    }
}   

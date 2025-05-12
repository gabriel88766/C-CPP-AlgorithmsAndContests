#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int x){
    cout << "? " << x << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n == 2*k){
            cout << "! " << k << " " << k << "\n";
            cout.flush();
            continue;
        }
        vector<int> a(k), b(k);
        vector<bool> df(k, false);
        for(int i=1;i<=k;i++){
            a[i%k] = query(i);
        }
        for(int i=n;i>=n-k+1;i--){
            b[i%k] = query(i);
        }
        bool ok = false;
        vector<int> di;
        for(int i=0;i<k;i++){
            if(a[i] != b[i]){
                ok = true;
                di.push_back(i);
                df[i] = true;
            }
        }
        if(ok){
            //bin search first different indx;
            auto findk = [&](int x){
                x--;
                if(di[0] == 0) x++;
                int res = (x / di.size()) * k;
                res += di[x % di.size()];
                return res;
            };
            int p = 1;
            for(int jp = n-1;jp>=1;jp>>=1){
                while(findk(p + jp) <= n && query(findk(p + jp)) == a[findk(p + jp) % k]) p += jp;
            }
            int idx = findk(p);
            int nidx = findk(p + 1);
            if(idx + 1 == nidx){
                cout << "! " << idx << " " << n-idx << "\n";
                cout.flush();
            }else if(nidx - 1 == k){
                cout << "! " << k << " " << n-k << "\n";
                cout.flush();
            }else if(k + idx == n){
                cout << "! " << idx << " " << k << "\n";
                cout.flush(); 
            }else{
                cout << "! -1 " << "\n";
                cout.flush();
            }
        }else{
            cout << "! -1\n";
            cout.flush();
        }
    }
}

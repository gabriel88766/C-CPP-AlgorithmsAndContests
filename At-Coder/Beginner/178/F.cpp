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
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<int> c1(n+1), c2(n+1), c3(n+1);
    for(int i=0;i<n;i++) c1[a[i]]++;
    for(int i=0;i<n;i++) c2[b[i]]++;
    for(int i=1;i<=n;i++) c3[i] = c1[i] + c2[i];
    bool ok = true;
    for(int i=1;i<=n;i++) if(c3[i] > n) ok = false;
    if(ok){
        cout << "Yes\n";
        vector<int> aa(n), bb(n);
        int p = 0, p1 = 0, p2 = 0;
        int fu = 0, fd = 0;
        for(int i=1;i<=n;i++){
            if(c1[i] + c2[i] + p <= n){
                for(int j=p;j<p+c1[i];j++) aa[j] = i;
                for(int j=p+c1[i];j<p+c1[i]+c2[i];j++) bb[j] = i;
                p += c1[i] + c2[i];
                fu += c2[i];
                fd += c1[i];
            }else if(p < n){
                //HARD!!
                while(c1[i] + c2[i] + p > n){
                    if(c1[i] > 0 && fu > 0){
                        while(aa[p1] != 0) p1++;
                        aa[p1] = i;
                        c1[i]--;
                        fu--;
                        continue;
                    }
                    if(c2[i] > 0 && fd > 0){
                        while(bb[p2] != 0) p2++;
                        bb[p2] = i;
                        c2[i]--;
                        fd--;
                    }
                }
                --i; //repeat i;
            }else{
                while(p1 < n && c1[i] > 0){
                    while(aa[p1] != 0) p1++;
                    aa[p1] = i;
                    c1[i]--;
                }
                while(p2 < n && c2[i] > 0){
                    while(bb[p2] != 0) p2++;
                    bb[p2] = i;
                    c2[i]--;
                }
            }
        }
        map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[aa[i]].push_back(bb[i]);
        }
        for(int i=0;i<n;i++){
            cout << mp[a[i]].back() << " ";
            mp[a[i]].pop_back();
        }
        cout << "\n";
    }else cout << "No\n";
}

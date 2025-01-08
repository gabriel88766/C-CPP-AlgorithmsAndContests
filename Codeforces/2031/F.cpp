#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
int a1, a2;
int qr = 0;
void ask1(int a, int b){
    qr++;
    if(qr > 80) exit(0);
    cout << "? " << n-2 << " ";
    for(int i=1;i<=n;i++){
        if(i != a && i != b) cout << i << " ";
    }
    cout << "\n";
    cout.flush();
    cin >> a1 >> a2;
}
void ask2(int a, int b, int c, int d){
    qr++;
    if(qr > 80) exit(0);
    cout << "? " << 4 << " " << a << " " << b << " " << c << " " << d;
    cout << "\n";
    cout.flush();
    cin >> a1 >> a2;
}
//cout << fixed << setprecision (6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while(t--){
        qr = 0;
        cin >> n;
        int x1 = n/2;
        int x2 = x1 + 1;
        bool ok = false;
        int m1, m2;
        map<pair<int,int>, bool> mp;
        while(!ok){
            m1 = uniform_int_distribution<int>(1, n)(rng);
            m2 = uniform_int_distribution<int>(1, n)(rng);
            while(m1 == m2) m2 = uniform_int_distribution<int>(1, n)(rng);
            if(m1 > m2) swap(m1, m2);
            if(mp.count({m1, m2})) continue;
            mp[{m1, m2}] = true;
            ask1(m1, m2);
            if(a1 == x1 && a2 == x2){
                ok = true;
                break;
            }
        }
        vector<int> vx;
        for(int i=1;i<=n;i++){
            if(i != m1 && i != m2) vx.push_back(i);
        }
        assert(vx.size() == n-2);
        int na = -1;
        vector<int> ans;
        ask2(m1, m2, vx[0], vx[1]);
        if(a1 == x1 || a2 == x1 || a1 == x2 || a2 == x2){
            ask2(m1, m2, vx[1], vx[2]);
            if(a1 == x1 || a2 == x1 || a1 == x2 || a2 == x2){
                ask2(m1, m2, vx[2], vx[3]);
                if(a1 == x1 || a2 == x1 || a1 == x2 || a2 == x2){
                    //1 and 3 or 0 and 2 or 1 and 2
                    ask2(m1, m2, vx[0], vx[2]);
                    if(a1 == x1 && a2 == x2){
                        ans.push_back(vx[0]);
                        ans.push_back(vx[2]);
                    }else{
                        ask2(m1, m2, vx[1], vx[3]);
                        if(a1 == x1 && a2 == x2){
                            ans.push_back(vx[1]);
                            ans.push_back(vx[3]);
                        }else{
                            ans.push_back(vx[1]);
                            ans.push_back(vx[2]);
                        }
                    }
                }else{
                    // 1 is ok but 2 and 3 are not and 0 is maybe
                    ans.push_back(vx[1]);
                    na = 2;
                    ask2(m1, m2, vx[0], vx[2]);
                    if(a1 == x1 || a2 == x1 || a1 == x2 || a2 == x2){
                        ans.push_back(vx[0]);
                    }
                }
            }else{
                ans.push_back(vx[0]);
                na = 1;
            }
        }else na = 0;

        for(int i=2;i<vx.size();i+=2){
            if(ans.size() == 2) break;
            ask2(m1, m2, vx[i], vx[i+1]);
            if(a1 == x1 || a2 == x1 || a1 == x2 || a2 == x2){
                ask2(m1, m2, vx[na], vx[i]);
                if(a1 == x1 || a2 == x1 || a1 == x2 || a2 == x2){
                    ans.push_back(vx[i]);
                }
                ask2(m1, m2, vx[na], vx[i+1]);
                if(a1 == x1 || a2 == x1 || a1 == x2 || a2 == x2){
                    ans.push_back(vx[i+1]);
                }
            }
        }
        assert(ans.size() == 2);
        cout << "! " << ans[0] << " " << ans[1] << "\n";
        cout.flush();
    }
    
}

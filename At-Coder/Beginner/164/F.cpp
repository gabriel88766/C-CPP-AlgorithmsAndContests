#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
ull s[N], t[N], u[N], v[N];
ull ans[N][N];
ull xtra[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> s[i];
    for(int i=1;i<=n;i++) cin >> t[i];
    for(int i=1;i<=n;i++) cin >> u[i];
    for(int i=1;i<=n;i++) cin >> v[i];
    bool ok = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i] == 0 && t[j] == 0) ans[i][j] = u[i] | v[j];
            else if(s[i] == 1 && t[j] == 1) ans[i][j] = u[i] & v[j];
            else if(s[i] == 1 && t[j] == 0){
                if((v[j] & u[i]) != v[j]) {
                    ok = false;
                }else{
                    ans[i][j] = v[j];
                    xtra[i][j] = u[i] ^ v[j];
                }
            }else{
                if((u[i] & v[j]) != u[i]){
                    ok = false;
                }else{
                    ans[i][j] = u[i];
                    xtra[i][j] = u[i] ^ v[j];
                }
            }
        }
    }
    auto check = [&](){
        bool ok = true;
        for(int i=1;i<=n;i++){
            if(s[i] == 0){
                ull cur = ~0ULL;
                for(int j=1;j<=n;j++) cur &= ans[i][j];
                if(cur != u[i]) ok = false;
            }else{
                ull cur = 0;
                for(int j=1;j<=n;j++) cur |= ans[i][j];
                if(cur != u[i]) ok = false;
            }
        }
        for(int j=1;j<=n;j++){
            if(t[j] == 0){
                ull cur = ~0ULL;
                for(int i=1;i<=n;i++) cur &= ans[i][j];
                if(cur != v[j]) ok = false;
            }else{
                ull cur = 0;
                for(int i=1;i<=n;i++) cur |= ans[i][j];
                if(cur != v[j]) ok = false;
            }
        }
        return ok;
    };  
    auto print = [&](){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    };
    auto transverse = [&](){
        for(int i=1;i<=n;i++){
            swap(s[i], t[i]);
            swap(u[i], v[i]);
            for(int j=i+1;j<=n;j++){
                swap(ans[i][j], ans[j][i]);
                swap(xtra[i][j], xtra[j][i]);
            }
        }
    };

    auto fix_column = [&](){
        vector<int> r1, c0;
        for(int i=1;i<=n;i++){
            if(s[i] == 1) r1.push_back(i);
        }
        for(int j=1;j<=n;j++){
            if(t[j] == 0) c0.push_back(j);
        }
        if(c0.size() >= 2){
            if(r1.size() >= 2){
                //that's ok!
                for(int x=0;x<r1.size();x++){
                    auto i = r1[x];
                    if(x % 2 == 0){
                        ans[i][c0[0]] |= xtra[i][c0[0]];
                    }else{
                        ans[i][c0[1]] |= xtra[i][c0[1]];
                    }
                }
            }else if(r1.size() == 1){
                //check if row is ok
                ull cur = 0;
                for(int j=1;j<=n;j++) cur |= ans[r1[0]][j];
                ull nd = cur ^ u[r1[0]];
                if(nd){
                    for(auto &j : c0){
                        ull cnd = ~0ULL;
                        for(int i=1;i<=n;i++){
                            if(i == r1[0]){
                                cnd &= (ans[i][j] | nd);
                            }else cnd &= ans[i][j];
                        }
                        if(cnd == v[j]){
                            ans[r1[0]][j] |= nd;
                        }
                    }
                }
            }
        }else if(c0.size() == 1){
            ull cur = ~0ULL;
            for(int i=1;i<=n;i++){
                if(s[i] == 0) cur &= ans[i][c0[0]];
                else cur &= (ans[i][c0[0]] | xtra[i][c0[0]]);
            }
            ull nd = cur ^ v[c0[0]];
            //nd is what needs to be zeroed
            if(nd){
                for(auto &i : r1){
                    ull cnd = 0;
                    for(int j=1;j<=n;j++){
                        if(j == c0[0]){
                            cnd |= (ans[i][j] | (nd ^ xtra[i][j]));
                        }else{
                            cnd |= ans[i][j];
                        }
                    }
                    if(cnd == u[i]){
                        ans[i][c0[0]] |= (nd ^ xtra[i][c0[0]]);
                    }
                }
            }

        }   
    };

    if(ok){
        fix_column();
        transverse();
        fix_column();
        transverse();
        if(check()) print();
        else cout << "-1\n";
    }else cout << "-1\n";
}

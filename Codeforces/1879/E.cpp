#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int p[105];
vector<int> c[105];
int h[105];
bool spc[2];
int bg[105];
int ans[105];

void dfs1(int u = 1, int p = 0){
    for(auto x : c[u]){
        h[x] = h[u] + 1;
        dfs1(x);
    }
}

void dfs2(int u = 1){
    if(u != 1){
        ans[u] = (ans[p[u]]+1);
        if(ans[u] == 4) ans[u] = 1;
    }
    for(auto x : c[u]){
        dfs2(x);
    }
}

void dfs3(int u = 1){
    if(u != 1){
        if(p[u] != 1){
            ans[u] = (ans[p[u]]+1);
            if(ans[u] == 3) ans[u] = 1;
        }else{
            if(bg[u]) ans[u] = bg[u];
            else ans[u]  = 1;
        }
    }
    for(auto x : c[u]){
        dfs3(x);
    }
}

void dfs4(int u = 1, int p = 0){
    if(u != 1 && c[u].size() == 1){
        if(h[u] % 2){
            if(bg[p] != 2){
                spc[0] = true;
                bg[p] = 1;
            }else spc[1] = true;
        }else{
            if(bg[p] != 1){
                spc[0] = true;
                bg[p] = 2;
            }else spc[1] = true;
        }
    }
    for(auto x : c[u]){
        if(u != 1) dfs4(x, p);
        else dfs4(x, x);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        cin >> p[i];
        c[p[i]].push_back(i);
    }
    dfs1();
    int qt = 1;
    for(int i=2;i<=n;i++) qt = max(qt, min(3, h[i]));

    if(qt == 1){
        cout << "1\n";
        for(int i=2;i<=n;i++) cout << 1 << " ";
        cout << "\n";
        cout.flush();
        cin >> qt >> qt;
        cout << "1\n";
        cout.flush();
        cin >> qt;
    }else if(qt == 2){
        cout << "2\n";
        for(int i=2;i<=n;i++){
            if(p[i] == 1) cout << "1 ";
            else cout << "2 ";
        }
        cout << "\n";
        cout.flush();
        int a, b;
        cin >> a >> a >> b;
        if(a != 0 && b != 0){
            cout << "1\n"; cout.flush();
            cin >> a;
        }else{
            if(b != 0){
                cout << "2\n"; cout.flush();
                cin >> a >> a >> b;
                cout << "1\n"; cout.flush();
                cin >> a;
            }else{
                cout << "1\n"; cout.flush();
                cin >> a;
            }
        }
    }else{
        //2 or 3
        dfs4();
        if(!spc[0] || !spc[1]){
            dfs3();
            cout << 2 << "\n";
            for(int i=2;i<=n;i++) cout << ans[i] << " ";
            cout << "\n";
            cout.flush();
            int nowv;
            cin >> nowv;
            int cur = 0;
            while(nowv == 0){
                int a, b;
                cin >> a >> b;
                if(cur == 0){
                    if(a == 1 && b == 1){
                        cur = 1;
                    }else if(a == 1) cur = 1;
                    else cur = 2;
                }else{
                    if(cur == 1) cur = 2;
                    else cur = 1;
                }
                cout << cur << "\n";
                cout.flush();
                cin >> nowv;
            }
        }else{
            dfs2();
            cout << "3\n";
            for(int i=2;i<=n;i++) cout << ans[i] << " ";
            cout << "\n";
            cout.flush();
            int nowv;
            cin >> nowv;
            while(nowv == 0){
                int a, b, c;
                cin >> a >> b >> c;
                if(a == 0 && b == 0 && c == 1) cout << 3 << "\n";
                if(a == 0 && b == 1 && c == 0) cout << 2 << "\n";
                if(a == 1 && b == 0 && c == 0) cout << 1 << "\n";
                if(a == 1 && b >= 1 && c == 0) cout << 1 << "\n";
                if(a == 0 && b == 1 && c >= 1) cout << 2 << "\n";
                if(a >= 1 && b == 0 && c == 1) cout << 3 << "\n"; 
                cout.flush();
                cin >> nowv;
            }
        }
    }
}

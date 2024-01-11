#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], his[N];
int tim = 0;
void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int find(int a, int t){
    if(p[a] == a) return a;
    if(his[a] > t) return a;
    else return find(p[a], t);
}


void unite(int a, int b){
    a = find(a, tim);
    b = find(b, tim);
    ++tim;
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    his[b] = tim; 
    sz[a] += sz[b];
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        if(find(a, tim) != find(b, tim)) cout << "-1\n";
        else{
            int ans = 0;
            while(a != b){
                if(his[a] == 0 || his[b] == 0){
                    if(his[a] != 0){
                        ans = his[a];
                        a = p[a];
                    }else{
                        ans = his[b];
                        b = p[b];
                    }
                }
                if(his[a] < his[b]){
                    ans = his[a];
                    a = p[a];
                
                }else{
                    ans = his[b];
                    b = p[b];
                }
            }
            cout << ans << "\n";
        }
    }
}

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int M = 5e6+5;
int phi[M];
void euler(){
    for(ll i=1;i<M;i++) phi[i] = i;
    for(ll i=2; i < M; i++){
        if(phi[i] == i){
            for(ll j = i; j < M; j += i){
                phi[j] -= phi[j]/i; 
            }
        }
    }
}
 
const int N = 1e5+6;
int st1[4*N], st2[4*N];
int v[N];
int n;
 
void build(int l = 1, int r = n, int p = 1){
    if(l == r){ 
        st1[p] = v[l];
        int cnt = 0;
        int aux = v[l];
        while(aux != 1){
            cnt++;
            aux = phi[aux];
        } 
        st2[p] = cnt;
        return; 
    }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    int aux1 = st1[2*p];
    int aux2 = st1[2*p+1];
    while(aux1 != aux2){
        if(aux1 < aux2) aux2 = phi[aux2];
        else aux1 = phi[aux1];
    }
    st1[p] = aux1;
    st2[p] = st2[2 * p] + st2[2 * p + 1]; 
}
 
int query1(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; 
    if(j >= r && i <= l) return st1[p];
    int aux1 = query1(i, j, l, (l + r)/2, 2 * p);
    int aux2 = query1(i, j, (l + r)/2 + 1, r, 2 * p + 1);
    if(aux1 == 0){
        swap(aux2, aux1);
    }else if(aux2 != 0){
        while(aux1 != aux2){
            if(aux1 < aux2) aux2 = phi[aux2];
            else aux1 = phi[aux1];
        }
    }
    return aux1; 
}
 
int query2(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; 
    if(j >= r && i <= l) return st2[p];
    return query2(i, j, l, (l + r)/2, 2 * p) + query2(i, j, (l + r)/2 + 1, r, 2 * p + 1); 
}
 
void update(int i, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) { st1[p] = phi[st1[p]]; st2[p]--; return;}
    update(i, l, (l + r)/2, 2 * p);
    update(i, (l + r)/2 + 1, r, 2 * p + 1);
    int aux1 = st1[2*p];
    int aux2 = st1[2*p+1];
    while(aux1 != aux2){
        if(aux1 < aux2) aux2 = phi[aux2];
        else aux1 = phi[aux1];
    }
    st1[p] = aux1; 
    st2[p] = st2[2*p] + st2[2*p+1];
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    euler();
    set<int> n1;
    int m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i] != 1) n1.insert(i);
    }
    build();
    for(int i=1;i<=m;i++){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 1){
            queue<int> rml;
            for(auto it = n1.lower_bound(a); it != n1.end(); ++it){
                if(*it > b) break;
                update(*it);
                v[*it] = phi[v[*it]];
                if(v[*it] == 1){
                    rml.push(*it);
                }
            }
            while(!rml.empty()){
                n1.erase(rml.front());
                rml.pop();
            }
        }else{
            int ans = query2(a,b);
            int lca = query1(a,b);
            int cnt = 0;
            while(lca != 1){
                cnt++;
                lca = phi[lca];
            }
            cout << ans-(b-a+1)*cnt << "\n";
        }
    }
}
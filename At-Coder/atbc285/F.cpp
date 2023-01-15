#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 1e5+6;
int st[4*N][26], invt[4*N];
int v[N];
int n;
string s;

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ 
        st[node][s[l-1]-'a'] = 1;
        invt[node] = v[l];
        return; 
    }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    for(int i=0;i<26;i++) st[node][i] = st[2 * node][i] + st[2 * node + 1][i];
    invt[node] = invt[2 * node] + invt[2 * node + 1];
}

int query(int i, int j, int letter, int l = 1, int r = n, int node = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[node][letter];
    return query(i, j, letter, l, (l + r)/2, 2 * node) + query(i, j, letter, (l + r)/2 + 1, r, 2 * node + 1); //some operation
}

int queryinv(int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return invt[node];
    return queryinv(i, j, l, (l + r)/2, 2 * node) + queryinv(i, j, (l + r)/2 + 1, r, 2 * node + 1); //some operation
}

void updateinv(int pos, int val, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {invt[node] = val; return;}
    updateinv(pos, val, l, (l + r)/2, 2 * node);
    updateinv(pos, val, (l + r)/2 + 1, r, 2 * node + 1);
    invt[node] = invt[2 * node] + invt[2 * node + 1];
}


void update(int pos, int letter, int val, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node][letter] = val; return;}
    update(pos, letter, val, l, (l + r)/2, 2 * node);
    update(pos, letter, val, (l + r)/2 + 1, r, 2 * node + 1);
    st[node][letter] = st[2 * node][letter] + st[2 * node + 1][letter]; //some operation
}

//another segtree to see inversions? not really



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n >> s >> q;
    for(int i=2;i<n;i++) if(s[i-2] > s[i-1]) v[i] = 1;
    build();
    int ss[26], ts[26];
    int  maxc, minc;
    while(q--){
        int a, b;
        char c;
        cin >> a;
        if(a == 1 ){
            cin >> a >> c;
            char oldc = s[a-1];
            s[a-1] = c;
            update(a, oldc - 'a', 0);
            update(a, c - 'a', 1);
            if(a > 1 && s[a-2] > s[a-1]) updateinv(a, 1);
            else updateinv(a, 0);
            if(a < n && s[a-1] > s[a]) updateinv(a+1, 1);
            else updateinv(a+1, 0);
        }else {
            cin >> a >> b;
            if(queryinv(a+1, b)){
                cout << "No\n";
            }else{
                maxc = s[b-1] - 'a';
                minc = s[a-1] - 'a';
                for(int i=minc; i<=maxc; i++) ss[i] = query(a,b, i);
                for(int i=minc; i<=maxc; i++) ts[i] = query(1,n, i);
                char ispos = true;
                for(int i=(minc+1); i< maxc;i++){
                    if(ss[i] < ts[i]) ispos= false;
                }
                if(ispos) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
}

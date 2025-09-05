#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 7000000, M = 31; // log aMax * Q (2e5 * 19, for example)
int cnt = 0;
int trie[N][2];
int sz[N];

bool get(int num){
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else return false;
    }
    return true;
}
void insert(int num){
    if(get(num)) return;
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        sz[cur]++;
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else cur = trie[cur][(num & (1 << i)) >> i] = ++cnt;
    }
    sz[cur]++;
}

void remove(int num){
    if(!get(num)) return;
    int cur = 0;
    for(int i=M-1;i>=0;i--){
        sz[cur]--;
        cur = trie[cur][(num & (1 << i)) >> i];
    }
    sz[cur]--;
    cur = 0;
    for(int i=M-1;i>=0;i--){
        int nxt = trie[cur][(num & (1 << i)) >> i];
        if(sz[nxt] == 0){
            trie[cur][(num & (1 << i)) >> i] = 0;
        }
        cur = nxt;
    }
}


int getLower(int val){ //get quantity of values lower than val
    int ans = 0;
    int cur = 0;
    for(int i=M-1;i>=0;i--){
        if(val & (1 << i)){
            if(trie[cur][0]) ans += sz[trie[cur][0]];
            cur = trie[cur][1]; 
        }else cur = trie[cur][0];
        if(!cur) break;
    }
    return ans;
}




int maxxor2(int num, int lv = M-1, int cx = 0, int p = 0){
    if(cx > num) assert(false);
    // assert(sz[p]);
    if(lv == -1) return cx ^ num;
    int nn = cx | (1 << lv);
    if(nn > num) return maxxor2(num, lv-1, cx, trie[p][0]);
    if(num & (1 << lv)){
        if(trie[p][0]) return maxxor2(num, lv-1, cx, trie[p][0]);
        else return maxxor2(num, lv-1, nn, trie[p][1]);
    }else{
        if(trie[p][1]) return maxxor2(num, lv-1, nn, trie[p][1]);
        else return maxxor2(num, lv-1, cx, trie[p][0]);
    }

}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1), vx;
    int ans = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }


    for(int i=n;i>=1;i--){
        //check if there is any number less than  v[i]
        if(getLower(v[i])){
            ans = max(ans, maxxor2(v[i]));
        }
        while(vx.size() && vx.back() < v[i]){
            remove(vx.back());
            vx.pop_back();
        }
        vx.push_back(v[i]);
        insert(vx.back());
    }
    for(int i=1;i<=n;i++){
        remove(v[i]);
    }
    vx.clear();
    for(int i=1;i<=n;i++){
        //check if there is any number less than  v[i]
        if(getLower(v[i])){
            ans = max(ans, maxxor2(v[i]));
        }
        while(vx.size() && vx.back() < v[i]){
            remove(vx.back());
            vx.pop_back();
        }
        vx.push_back(v[i]);
        insert(vx.back());
    }
    cout << ans << "\n";
}

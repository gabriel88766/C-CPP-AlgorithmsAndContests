#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n);
    }
    void build(vector<T> &v){
        for(int i=n;i<2*n;i++) st[i] = v[i-n];
        for(int i=n-1;i>=1;i--) st[i] = op(st[2*i], st[2*i+1]); //merge op
    }
    T query(int l, int r){
        T ans = nullel();
        l += n, r += n;
        while(l <= r){
            int no = l, c = 1;
            while(!(no & 1) && (r-l+1) >= (c << 1)){
                c <<= 1;
                no >>= 1;
            }
            ans = op(ans, st[no]); //merge op
            l += c;
        }
        return ans;
    }
    void update(int l, T val){
        l += n;
        st[l] += val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}

const int N = 10015;
vector<pair<int, int>> vx[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> cds;
    for(int i = 1; i<= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cds.push_back(a);
        vx[c].push_back({a, b});
    }
    for(int i=1;i<=10000;i++) sort(vx[i].begin(), vx[i].end());
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    SegmentTree<int, op, el> st(cds.size());
    //Ok
    ll ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=1;i<=10000;i++){
        int li = max(1, i - k);
        int mj = i + k;
        int ki = mj - li;
        for(int j=i;j<=i+k;j++){
            int p0 = 0, p1 = 0;
            int x0 = -1, x1 = -1;
            if(i == j) p1 = INF_INT;
            while(true){
                if(p0 < vx[i].size()) x0 = vx[i][p0].first;
                else x0 = INF_INT;
                if(p1 < vx[j].size()) x1 = vx[j][p1].first;
                else x1 = INF_INT;  
                int id_in, id_out, id_lf;
                if(x0 < x1){
                    id_in =  lower_bound(cds.begin(), cds.end(), x0) - cds.begin();
                    id_out = upper_bound(cds.begin(), cds.end(), x0 + vx[i][p0].second) - cds.begin();
                    id_lf = lower_bound(cds.begin(), cds.end(), x0 - vx[i][p0].second) - cds.begin();
                    p0++;
                }else if(x1 != INF_INT){
                    id_in =  lower_bound(cds.begin(), cds.end(), x1) - cds.begin();
                    id_out = upper_bound(cds.begin(), cds.end(), x1 + vx[j][p1].second) - cds.begin();
                    id_lf = lower_bound(cds.begin(), cds.end(), x1 - vx[j][p1].second) - cds.begin();
                    p1++;
                }else break;
                while(pq.size() && pq.top().first <= id_in){
                    st.update(pq.top().second, -1);
                    pq.pop();
                }
                ans += st.query(id_lf, id_in) * (i == j ? -ki+1 : 1);
                st.update(id_in, 1);
                pq.push({id_out, id_in});
            }
            while(pq.size()){
                st.update(pq.top().second, -1);
                pq.pop();
            }
        }
    }
    cout << ans << "\n";
}

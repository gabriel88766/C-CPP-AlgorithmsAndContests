#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T>
struct Deque{
    T *dq = new T[1000005];
    int l_ptr = 500002, r_ptr = 500001;
    int szdq = 0;
    inline void push_back(const T& p){
        dq[++r_ptr] = p;
        szdq++;
    }

    inline void pop_back(){
        r_ptr--;
        szdq--;
    }

    inline void push_front(const T& p){
        dq[--l_ptr] = p;
        szdq++;
    }

    inline void pop_front(){
        l_ptr++;
        szdq--;
    }

    inline T at(int pos) const {
        return dq[l_ptr+pos];
    }

    T operator [](int i) const {
        return dq[l_ptr+i];
    }

    T front() const {
        return dq[l_ptr];
    }

    T back() const {
        return dq[r_ptr];
    }

    int size() const {
        return szdq;
    }

    void clear(){
        l_ptr = 500002;
        r_ptr = 500001;
        szdq = 0;
    }
};

Deque<pair<ll, ll>> v1, v2, v3;

const int N = 2e5+505;
const int sqrtN = 500; //200000 = 500*400
ll ansr[N];
int n;

pair<ll, ll> ops[N];
int opcnt = 0;

struct Query{
    int l, r, i;
    //MO G3
    bool operator< (const Query u) const {
        if(l/sqrtN != u.l/sqrtN) return l/sqrtN < u.l/sqrtN;
        else return r < u.r;
    }
};

ll ans[N];
// ll  ps[N];
vector<Query> vq;
//Key idea,
//Process queries that begin in block 1, then block 2, and so on...
//build array with the right position while the right position grow.
void Mo(){ //This is an example, function need to be changed, but idea remains.
    ll blk = -1, r = 0, cur = 0, sum = 0, cur2 = 0;
    for(auto x : vq){
        if((x.l/sqrtN)*sqrtN != blk){
            cur = cur2 = sum = 0;
            v1.clear();
            v2.clear();
            blk = r = (x.l/sqrtN)*sqrtN; //first element of block
            r += sqrtN;
        }
        if(x.r < blk+sqrtN){
            //Solve O(sqrtN);
            assert(v1.size() == 0);
            ll sum = 0, cur = 0;
            for(int i=x.l;i<=x.r;i++){
                while(v1.size() && ansr[i] <= v1.back().first){
                    int px = v1.size() - 1;
                    if(v1.size() == 1){
                        cur -= (v1[px].second - x.l + 1) * v1[px].first;
                    }else{
                        cur -= (v1[px].second - v1[px-1].second) * v1[px].first;
                    }
                    v1.pop_back();
                }
                v1.push_back({ansr[i], i});
                int px = v1.size() - 1;
                if(v1.size() == 1){
                    cur += (v1[px].second - x.l + 1) * v1[px].first;
                }else{
                    cur += (v1[px].second - v1[px-1].second) * v1[px].first;
                }
                sum += cur;
            }
            v1.clear();
            ans[x.i] = sum;
            continue;
        }
        while(r <= x.r){ //from 0 to n, sqrt(N) times
            while(v1.size() && ansr[r] <= v1.back().first){
                int px = v1.size() - 1;
                if(v1.size() == 1){
                    cur -= (v1[px].second - blk - sqrtN + 1) * v1[px].first;
                }else{
                    cur -= (v1[px].second - v1[px-1].second) * v1[px].first;
                }
                v1.pop_back();
            }
            if(v2.size() && v2.back().first > ansr[r]) v2.push_back({ansr[r], r});
            else if(!v2.size()) v2.push_back({ansr[r], r});
            cur2 += v2.back().first;
            v1.push_back({ansr[r], r});
            int px = v1.size() - 1;
            if(v1.size() == 1){
                cur += (v1[px].second - blk - sqrtN + 1) * v1[px].first;
            }else{
                cur += (v1[px].second - v1[px-1].second) * v1[px].first;
            }
            sum += cur;
            r++;
        }
        ans[x.i] = sum;
        //min queue with rollback...
        //this is O(sqrtN) because there is at most 1 pop each time, the value can't
        //increase or decrease more than 1
        // vector<tuple<int, int, int>> ops;//1 insert, 2 remove 
        ll aux = cur2;
        ll pn = 0;  
        for(int i=blk+sqrtN-1;i>=x.l;i--){
            while(v2.size() && v2.front().first >= ansr[i]){
                if(v2.size() == 1){
                    aux -= (x.r - v2.front().second + 1) * v2.front().first;
                }else{
                    aux -= (v2[1].second - v2.front().second) * v2.front().first;
                }
                v3.push_back(v2.front());
                v2.pop_front();
            }
            v2.push_front({ansr[i], i});
            v3.push_back({-1, -1}); //doesn't matter, its remove
            if(v2.size() == 1){
                aux += (x.r - v2.front().second + 1) * v2.front().first;
            }else{
                aux += (v2[1].second - v2.front().second) * v2.front().first;
            }
            ans[x.i] += aux;
        }
        while(v3.size()){
            auto [a, b] = v3.back();
            v3.pop_back();
            if(a == -1) v2.pop_front();
            else v2.push_front({a, b});
        }
        
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int k, q;
        cin >> n >> k >> q;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            v[i] += n-i;
        }
        vector<int> mp(2*n, 0);
        vector<int> cnt(n+1, 0);
        cnt[0] = 2*n;
        int mx = 0;
        for(int i=1;i<=n;i++){
            cnt[mp[v[i]]]--;
            cnt[++mp[v[i]]]++;
            if(i > k){ 
                cnt[mp[v[i-k]]]--;
                cnt[--mp[v[i-k]]]++;
            }
            if(mx != n && cnt[mx+1] != 0) mx++;
            else if(cnt[mx] == 0) mx--;
            if(i >= k){
                ansr[i] = k-mx;
            }else ansr[i] = 0;
        }
        //G3! MO!
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            vq.push_back({l+k-1, r, i});
        }
        sort(vq.begin(), vq.end());
        Mo();
        for(int i=0;i<q;i++) cout << ans[i] << "\n";
        vq.clear();
        for(int i=1;i<=n;i++) ansr[i] = 0;
    }
}
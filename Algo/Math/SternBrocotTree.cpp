#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


//inputs must satisfy 0 < a/b < ∞
vector<pair<char, ll>> find_path(ll a, ll b){
    ll g = gcd(a, b);
    a /= g, b /= g;
    vector<pair<char, ll>> path;
    ll a0 = 0, a1 = 1, b0 = 1, b1 = 0, n = 1, d = 1;
    while(n != a || b != d){
        __int128 f1 = a;
        __int128 f2 = n;
        f1 *= d;
        f2 *= b;
        if(f1 > f2){
            //then a/b > n/d, then move to right
            // make (n + x * b0) / (d + x * b1) >= a/b => nb + bb0 x >= ad + ab1 x
            //x (b * b0 - a * b1) >=  ad - nb;
            // x >= (ad - nb) / (b * b0 - a * b1);
            __int128 dx = f1 - f2;
            __int128 dy = ((__int128)b) * b0 - ((__int128)a) * b1;
            ll mtp = (dx + dy-1)/dy;
            path.push_back({'R', mtp});
            n += b0 * mtp;
            d += b1 * mtp;
            a1 = d - b1;
            a0 = n - b0;
        }else{
            //then move to left
            //(n + x * b0) / (d + x * b1)  <= a/b => nb + xbb0 <= ad + xb1a
            // x(b1 * a - b * b0) >= nb - ad
            __int128 dx = f2 - f1;
            __int128 dy = ((__int128)a) * a1 - ((__int128)b) * a0;
            ll mtp = (dx + dy - 1) / dy;
            path.push_back({'L', mtp});
            n += a0 * mtp;
            d += a1 * mtp;
            b0 = n - a0;
            b1 = d - a1;
        }
    }
    return path;
}

pair<ll, ll> recover_from_path(const vector<pair<char, ll>> &path){
    ll n = 1, d = 1, a0 = 0, a1 = 1, b0 = 1, b1 = 0;
    for(auto &[a, b] : path){
        if(a == 'L'){
            n += a0 * b;
            d += a1 * b;
            b0 = n - a0;
            b1 = d - a1;
        }else{
            n += b0 * b;
            d += b1 * b;
            a0 = n - b0;
            a1 = d - b1;
        }
    }
    return {n, d};
}

//this find the ancestor with k above the current node
pair<ll, ll> ancestor(ll k, ll a, ll b){
    auto path = find_path(a, b);
    while(path.size()){
        if(path.back().second <= k){
            k -= path.back().second;
            path.pop_back();
        }else{
            path.back().second -= k;
            k = 0;
            break;
        }
    }
    if(k) return {-1, -1};
    else return recover_from_path(path);
}

//this find the ancestor with depth d in the tree
pair<ll, ll> ancestor_depth(ll d, ll a, ll b){
    auto path = find_path(a, b);
    ll ttsz = 0;
    for(auto &[a, b] : path) ttsz += b;
    if(ttsz < d) return {-1, -1};
    else return ancestor(ttsz - d, a, b);
}

pair<ll, ll> lca(ll a, ll b, ll c, ll d){
    auto path1 = find_path(a, b);
    auto path2 = find_path(c, d);
    vector<pair<char, ll>> commonpath;
    for(int i=0;i<min(path1.size(), path2.size()); i++){
        if(path1[i].first == path2[i].first){
            if(path1[i].second == path2[i].second){
                commonpath.push_back(path1[i]);
            }else{
                commonpath.push_back({path1[i].first, min(path1[i].second, path2[i].second)});
                break;
            }
        }else break;
    }
    return recover_from_path(commonpath);
}

void range(ll a, ll b){
    auto path = find_path(a, b);
    ll n = 1, d = 1, a0 = 0, a1 = 1, b0 = 1, b1 = 0;
    for(auto &[a, b] : path){
        if(a == 'L'){
            n += a0 * b;
            d += a1 * b;
            b0 = n - a0;
            b1 = d - a1;
        }else{
            n += b0 * b;
            d += b1 * b;
            a0 = n - b0;
            a1 = d - b1;
        }
    }
    cout << a0 << " " << a1 << " " << b0 << " " << b1 << "\n";
}


pair<ll, ll> limit_denominator(ll aa, ll bb, ll mden){
    //2* mden * mden * bb <= 10^38. else = overflow.
    auto check_best = [&](__int128 a, __int128 b, __int128 c, __int128 d){
        __int128 den = 2 * b * d;
        __int128 num = a * d + c * b; 
        __int128 g = gcd(den, num);
        den /= g, num /= g;
        if(den == bb && num == aa){
            if(a*d < b*c) return make_pair(a, b);
            else return make_pair(c, d);
        }else{
            if(num * bb < den * aa){
                if(a * d < b * c) return make_pair(c, d);
                else return make_pair(a, b);
            }else{
                if(a * d < b * c) return make_pair(a, b);
                else return make_pair(c, d);
            }
        }
    };
    ll n = 1, d = 1, a0 = 0, a1 = 1, b0 = 1, b1 = 0;
    auto path = find_path(aa, bb);
    for(auto &[a, b] : path){
        if(a == 'L'){
            if(d + a1*b <= mden){
                n += a0 * b;
                d += a1 * b;
                b0 = n - a0;
                b1 = d - a1;
            }else{
                //assert(a1 != 0);check
                ll mx = (mden - d) / a1;
                n += a0 * mx;
                d += a1 * mx;
                return check_best(n, d, a0, a1);
            }
        }else{
            if(d + b1 * b <= mden){
                n += b0 * b;
                d += b1 * b;
                a0 = n - b0;
                a1 = d - b1;
            }else{
                //assert(b1 != 0); check
                ll mx = (mden - d) / b1;
                n += b0 * mx;
                d += b1 * mx;
                return check_best(n, d, b0, b1);
            }
        }
    }
    return {n, d};
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s == "DECODE_PATH"){
            int tt = 0;
            cin >> tt;
            vector<pair<char, ll>> path;
            for(int i=0;i<tt;i++){
                char c;
                int n;
                cin >> c >> n;
                path.push_back({c, n});
            }
            auto [a, b] = recover_from_path(path);
            cout << a << " " << b << "\n";
        }else if(s == "ENCODE_PATH"){
            ll a, b;
            cin >> a >> b;
            auto path = find_path(a, b);
            cout << path.size() << " ";
            for(auto &[a, b] : path) cout << a << " " << b << " ";
            cout << "\n";
        }else if(s == "LCA"){
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            auto [e, f] = lca(a, b, c, d);
            cout << e << " " << f << "\n";
        }else if(s == "RANGE"){
            ll a, b;
            cin >> a >> b;
            range(a, b);
        }else if(s == "ANCESTOR"){
            ll k, a, b;
            cin >> k >> a >> b;
            auto [c, d] = ancestor_depth(k, a, b);
            if(c == -1 && d == -1) cout << "-1\n";
            else cout << c << " " << d << "\n";
        }else{
            cerr << "UNINTENDED\n\n";
            return 1;
        }
    }
}

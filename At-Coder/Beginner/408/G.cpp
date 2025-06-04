#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>
typedef long long int ll;
using namespace std;

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
            __int128 dx = f1 - f2;
            __int128 dy = ((__int128)b) * b0 - ((__int128)a) * b1;
            ll mtp = (dx + dy-1)/dy;
            path.push_back({'R', mtp});
            n += b0 * mtp;
            d += b1 * mtp;
            a1 = d - b1;
            a0 = n - b0;
        }else{
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll g = gcd(a, b);
        a /= g, b /= g;
        g = gcd(c, d);
        c /= g, d /= g;
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
        auto [e, f] = recover_from_path(commonpath);
        if(e == c && f == d){
            swap(c, a);
            swap(d, b);
            swap(path1, path2);
        }
        
        if(e == a && f == b){
            ll nx = 1, dx = 1, a0 = 0, a1 = 1, b0 = 1, b1 = 0;
            for(auto &[a, b] : path1){
                if(a == 'L'){
                    nx += a0 * b;
                    dx += a1 * b;
                    b0 = nx - a0;
                    b1 = dx - a1;
                }else{
                    nx += b0 * b;
                    dx += b1 * b;
                    a0 = nx - b0;
                    a1 = dx - b1;
                }
            }
            reverse(path1.begin(), path1.end());
            reverse(path2.begin(), path2.end());
            while(path1.size()){
                if(path1.back() == path2.back()){
                    path1.pop_back();
                    path2.pop_back();
                }else{
                    assert(path1.back().first == path2.back().first);
                    assert(path1.back().second <= path2.back().second);
                    path2.back().second -= path1.back().second;
                    path1.pop_back();
                }
            }
            assert(dx == b);
            reverse(path2.begin(), path2.end());
            if(path2[0].second >= 2){
                if(path2[0].first == 'L') dx += a1;
                else dx += b1;
                cout << dx << "\n";
            }else{
                if(path2[0].first == 'L'){
                    b0 = nx;
                    b1 = dx;
                    nx += a0;
                    dx += a1;
                }else{
                    a0 = nx;
                    a1 = dx;
                    nx += b0;
                    dx += b1;
                }
                if(path2.size() == 1){
                    if(path2[0].first == 'L') dx += b1;
                    else dx += a1;
                    cout << dx << "\n";
                }else if(path2.size() == 2){
                    cout << b + d << "\n";
                }else{
                    dx += path2[1].second * (path2[1].first == 'L' ? a1 : b1);
                    cout << dx << "\n";
                }
            }
        }else{
            cout << f << "\n";
        }
    }
}

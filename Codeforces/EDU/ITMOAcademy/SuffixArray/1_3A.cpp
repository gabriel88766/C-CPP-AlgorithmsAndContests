#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//mp maps current position to original index, c is the class of the prefix

const int N = 3e5+3; 
int  n, c;

vector<int> suffix_array(string &s){
    s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n), cnt(max(n+1, 256)), mp2(256), aux(n); 
    vector<pair<int,int>> cs(n); // class,class <int,int>

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
        for(int j=0; j<n; j++) cnt[cs[j].first+1]++; 
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n;j++) mp[cnt[cs[aux[j]].first]++] = aux[j]; 
        //end raddix_sort
        aux[mp[0]] = c = 0;
        for(int j=1;j<n;j++){
            if(cs[mp[j]] == cs[mp[j-1]]) aux[mp[j]] = c;
            else aux[mp[j]] = ++c;
        }
        for(int j=0;j<n;j++) cs[j].first = aux[j];
    }
    return mp;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    int q;
    cin >> s >> q;
    vector<int> ind = suffix_array(s);
    for(int i=0;i<q;i++){
        string t;
        cin >> t;
        int lo = 0, hi = n-1, mid;
        char match = false;
        if(t.size() <= s.size()){ //
            while(lo != hi){
                mid = (lo+hi)/2;
                for(int j=0; j < t.size(); j++){
                    if(t[j] < s[ind[mid] + j]){
                        hi = mid; break;
                    }else if(t[j] > s[ind[mid] + j]){
                        lo = mid+1; break;
                    }else{
                        if(j == (t.size() - 1)){
                            match = true;
                            break;
                        }   
                    }
                }
                if(match) break;
            }
        }
        for(int j=0; j < t.size(); j++){
            if(t[j] == s[ind[lo] + j]){
                if(j == (t.size()-1)) match = true;
            }else break;
        }
        if(match) cout << "Yes\n";
        else cout << "No\n";
    }
    
}

//Make some xor related problems much easier
//can be used as ordered set too
//1895D 1658D2
const int N = 3800005, M = 19; // log aMax * Q (2e5 * 19, for example)
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

int minxor(int num){
    int cur = 0;
    int key = 0;
    for(int i=M-1;i>=0;i--){
        int b = (num & (1 << i)) >> i;
        if(trie[cur][b]){
            cur = trie[cur][b];
            if(b) key ^= (1 << i);
        }else{
            cur = trie[cur][b^1];
            if(b^1) key ^= (1 << i);
        }
    }
    return key ^ num;
}


int maxxor(int num){
    int cur = 0;
    int key = 0;
    for(int i=M-1;i>=0;i--){
        int b = (num & (1 << i)) >> i;
        if(trie[cur][b^1]){
            cur = trie[cur][b^1];
            if(b^1) key ^= (1 << i);
        }else{
            cur = trie[cur][b];
            if(b) key ^= (1 << i);
        }
    }
    return key ^ num;
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

int getK(int val){ //get quantity of values lower than val
    int ans = 0;
    int cur = 0;
    int curs = 0;
    for(int i=M-1;i>=0;i--){
        int sn = trie[cur][0] ? sz[trie[cur][0]] : 0;
        if(curs + sn < val){
            curs += sn;
            cur = trie[cur][1];
            ans |= (1 << i);
        }else cur = trie[cur][0];
    }
    return ans;
}


//findxor
//try to find the highest index with xor num^v[j] lower than mv
//idx is the highest index of some descendent of the current node
//binary search in trie.
int findxor(int mv, int num, int lv = M-1, int cx=0, int p=0){
    if(cx >= mv) return -1;
    int cur = (1 << (lv+1)) - 1 + cx;
    if(cur < mv) return idx[p];

    if(trie[p][0] && trie[p][1]){
        if(num & (1 << lv)) return max(findxor(mv, num, lv-1, cx | (1 << lv), trie[p][0]), findxor(mv, num, lv-1, cx, trie[p][1]));
        else return max(findxor(mv, num, lv-1, cx, trie[p][0]), findxor(mv, num, lv-1, cx | (1 << lv), trie[p][1]));
    }else if(trie[p][0]){
        if(num & (1 << lv)) return findxor(mv, num, lv-1, cx | (1 << lv), trie[p][0]);
        else return findxor(mv, num, lv-1, cx, trie[p][0]);
    }else{
        if(num & (1 << lv)) return findxor(mv, num, lv-1, cx, trie[p][1]);
        else return findxor(mv, num, lv-1, cx | (1 << lv), trie[p][1]);
    }
}



//THIS TRIE BELOW CAN BE MERGED
struct Trie{
    vector<pair<int, int>> trie;
    vector<int> nums;
    int cnt;
    Trie(){
        cnt = 0;
        trie.push_back({0, 0});
    }
    void insert(int num){
        int cur = 0;
        int ccn = cnt;
        for(int j=M-1;j>=0;j--){
            int l = (num & (1 << j));
            if(l){
                if(!trie[cur].second) {trie[cur].second = ++cnt; trie.push_back({0, 0});} 
                cur = trie[cur].second;
            }else{
                if(!trie[cur].first) {trie[cur].first = ++cnt; trie.push_back({0, 0});}
                cur = trie[cur].first;
            }
        }
        if(ccn != cnt) nums.push_back(num);
    }
    int maxxor(int num){
        int cur = 0;
        int key = 0;
        for(int i=M-1;i>=0;i--){
            int b = (num & (1 << i));
            if(b){
                if(trie[cur].first){
                    cur = trie[cur].first;
                }else{
                    cur = trie[cur].second;
                    key ^= (1 << i);
                }
            }else{
                if(trie[cur].second){
                    cur = trie[cur].second;
                    key ^= (1 << i);
                }else{
                    cur = trie[cur].first;
                }
            }
        }
        return key ^ num;
    }
    void clear(){
        trie.clear();
        nums.clear();
        trie.push_back({0, 0});
        cnt = 0;
    }
};

int cn = 0;
Trie tr[1000000];
//TODO : create new tries and merge small to large.
//example :
function<Trie *(int, int)> solve = [&](int l, int r){
    if(l >= r){ 
        tr[cn].insert(ps[l-1]);
        tr[cn].insert(ps[r]); //maybe r is l-1;
        return &tr[cn++];
    }
    int mx = st.query(l, r);
    int m = *mp[mx].lower_bound(l);
    auto x1 = solve(l, m - 1); // [l-1, m-1]
    auto x2 = solve(m+1, r); // [m, r];
    if(x1->nums.size() < x2->nums.size()){
        swap(x1->cnt, x2->cnt);
        x1->nums.swap(x2->nums);
        x1->trie.swap(x2->trie);
    }
    for(auto x : x2->nums){
        ans = max(ans, x1->maxxor(x ^ mx));
    }
    for(auto x : x2->nums){
        x1->insert(x);
    }
    return x1;
};
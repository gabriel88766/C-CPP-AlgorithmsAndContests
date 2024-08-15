//Untested :) (remove is working)
//Some bugs in insert were fixed (915E) continuous insert = abc168F
struct Intervals{
    set<pair<int,int>> s;
    int sz;
    Intervals(int n){
        s.insert({1, n});
        sz = n;
    }
    void remove(int l, int r){
        if(r < l) return;
        if(s.size() == 0) return;
        auto it = s.lower_bound({l, -INF_INT});
        vector<pair<int,int>> erl;
        if(it != s.begin()){
            auto it2 = prev(it);
            if(it2->second > r){
                pair<int,int> p1 = {it2->first, l-1}; //l and r if continuous and change sz +=
                pair<int,int> p2 = {r+1, it2->second};
                erl.push_back(*it2);
                sz += p1.second - p1.first + 1;
                sz += p2.second - p2.first + 1;
                s.insert(p1);
                s.insert(p2);
            }else if(it2->second >= l){
                pair<int,int> p1 = {it2->first, l-1}; //here too
                erl.push_back(*it2);
                sz += p1.second - p1.first + 1;
                s.insert(p1);
            }
        }
        while(it != s.end()){
            if(it->second <= r){
                erl.push_back(*it);
                ++it;
                continue;
            }else if(it->first <= r && it->second > r){
                pair<int,int> p = {r+1, it->second}; //and here
                erl.push_back(*it);
                sz += p.second - p.first + 1;
                s.insert(p);
            }
            break;
        }
        for(auto x : erl){
            sz -= x.second - x.first + 1;
            s.erase(x);
        }
    }

    void insert(int l, int r){
        if(r < l) return;
        auto it = s.lower_bound({l, -INF_INT});
        vector<pair<int,int>> erl;
        pair<int,int> p = {l, r};
        if(it != s.begin()){
            auto it2 = prev(it);
            if(it2->second >= r) return; //do nothing
            else if(it2->second >= (l-1)){ // l if segments continuous(also change sz if needed)
                p = {it2->first, r};
                erl.push_back(*it2);
            }
        }
        while(it != s.end()){
            if(it->second <= r){
                erl.push_back(*it);
                ++it;
                continue;
            }else if(it->first <= (r+1)){ // r if segments continuous
                p.second = it->second;
                erl.push_back(*it);
            }
            break;
        }
        for(auto x : erl){
            sz -= x.second - x.first + 1;
            s.erase(x);
        }
        sz += p.second - p.first + 1;
        s.insert(p);
    }
};
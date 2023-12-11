//Untested :) (remove is working)
struct Intervals{
    set<pair<int,int>> s;
    Intervals(int n){
        s.insert({1, n});
    }
    void remove(int l, int r){
        if(r < l) return;
        auto it = s.lower_bound({l, 0});
        vector<pair<int,int>> erl;
        if(it != s.begin()){
            auto it2 = prev(it);
            if(it2->second > r){
                pair<int,int> p1 = {it2->first, l-1};
                pair<int,int> p2 = {r+1, it2->second};
                erl.push_back(*it2);
                s.insert(p1);
                s.insert(p2);
            }else if(it2->second >= l){
                pair<int,int> p1 = {it2->first, l-1};
                erl.push_back(*it2);
                s.insert(p1);
            }
        }
        while(it != s.end()){
            if(it->second <= r){
                erl.push_back(*it);
                ++it;
                continue;
            }else if(it->first <= r && it->second > r){
                pair<int,int> p = {r+1, it->second};
                erl.push_back(*it);
                s.insert(p);
            }
            break;
        }
        for(auto x : erl) s.erase(x);
    }

    void insert(int l, int r){
        if(r < l) return;
        auto it = s.lower_bound({l, 0});
        vector<pair<int,int>> erl;
        pair<int,int> p = {l, r};
        if(it != s.begin()){
            auto it2 = prev(it);
            if(it2->second >= r); //do nothing
            else if(it2->second >= (l-1)){
                p = {it2->first, r};
                erl.push_back(*it2);
            }
        }
        while(it != s.end()){
            if(it->second <= r){
                erl.push_back(*it);
                ++it;
                continue;
            }else if(it->first <= r){
                p.second = it->second;
                erl.push_back(*it);
            }
            break;
        }
        s.insert(p);
        for(auto x : erl) s.erase(x);
    }


};
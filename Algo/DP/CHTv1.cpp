//Structure (add is O(1) amortized)
struct Frac{
    ll a, b;
    bool operator< (const Frac &c) const{
        return a*c.b < b*c.a;
    }
};

struct Line{
    Frac beg;
    ll x, C;
    bool operator< (const Line &c) const {
        return beg < c.beg;
    }
};

//Hint: above the curve: maximization; below the curve: minimization
struct ConvexHull{
    vector<Line> lines;
    void add(ll x, ll C){ //x is the slope (y1-y0)/(x1-x0) and C is the initial point at x = 0
        Frac beg = {0, 1};
        while(lines.size()){
            auto l = lines.back(); 
            if(l.x == x && C >= l.C) return; //above : l.C >= C, below C >= l.C
            else if(C <= l.C) lines.pop_back(); //above : l.C <= C below C <= l.C 
            else{
                //l.C - C > 0
                beg = { C - l.C, l.x-x}; //above: (l.C-C)/(x-l.x), below (C-l.C)/(l.x-x)
                if(beg < l.beg) lines.pop_back(); 
                else break;
            }
        }
        lines.push_back({beg, x, C});
    }
    ll get(ll val){
        Line cp = {{val, 1}, 0, 0};
        auto index = prev(upper_bound(lines.begin(), lines.end(), cp)) - lines.begin();
        return lines[index].x * val + lines[index].C;
    }
};
//DP-logic
//https://cses.fi/problemset/task/2084/ and https://atcoder.jp/contests/abc289/tasks/abc289_g
// a1 >= a2 >= a3 >= ... an
//and b1 <= b2 <= b3 ...
//for arbitrary insertions, TODO!
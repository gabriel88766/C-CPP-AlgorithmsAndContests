//min priority queue (dijkstra?)
priority_queue<int, vector<int>, greater<int>> pq;

int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x) << "\n"; // 19
cout << __builtin_ctz(x) << "\n"; // 4
cout << __builtin_popcount(x) << "\n"; // 5
cout << __builtin_parity(x) << "\n"; // 1

//Snippet cordinate compresion
sort(ind.begin(), ind.end());
ind.erase(unique(ind.begin(), ind.end()), ind.end());

//Struct with operator, remember const.
struct Edge {
	int a, b, w;
	bool operator< (const Edge &y) const { return w < y.w; }
};

//Tips, Binary Search
int mid = lo + (hi - lo) / 2; //when negative is allowed, 
if(something) hi = mid; else lo = mid+1;
//other type
int mid = (lo + hi + 1) / 2;
if(something) hi = mid-1, else lo = mid;

// unordered_map or set
struct custom_hash {
    size_t operator()(vector<int> const& vec) const {
    size_t seed = vec.size();
    for(auto& i : vec) {
        seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
    }
};

struct custom_hash {
    static ull splitmix64(ull x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ull x) const {
        static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
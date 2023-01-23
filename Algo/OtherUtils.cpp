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

//min priority queue (dijkstra?)
priority_queue<int, vector<int>, greater<int>> pq;

int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x) << "\n"; // 19
cout << __builtin_ctz(x) << "\n"; // 4
cout << __builtin_popcount(x) << "\n"; // 5
cout << __builtin_parity(x) << "\n"; // 1

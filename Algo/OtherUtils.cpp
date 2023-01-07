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
#include <bits/stdc++.h>

#ifndef _MOG_DSU_HPP_
#define _MOG_DSU_HPP_

#ifndef MOG_LIB
#define MOG_LIB
#endif

#ifndef _MOG_INTERNAL_DSU_HPP_
#define _MOG_INTERNAL_DSU_HPP_

#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

namespace mog::internal {

struct DSU {
	std::vector<int> parent;
	std::vector<int> size;

	DSU(int n) : parent(n), size(n, 1) {
		std::iota(parent.begin(), parent.end(), 0);
	}

	int root(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = root(parent[x]);
	}

	bool merge(int x, int y) {
		assert(0 <= x && x < std::ssize(parent));
		assert(0 <= y && y < std::ssize(parent));
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (size[x] < size[y]) {
			std::swap(x, y);
		}
		parent[y] = x;
		size[x] += size[y];
		return true;
	}

	bool same(int x, int y) {
		assert(0 <= x && x < std::ssize(parent));
		assert(0 <= y && y < std::ssize(parent));
		return root(x) == root(y);
	}
};

class DSURollback {
	std::vector<int> parent;
	std::vector<int> rank;

	struct MergeOperation {
		int y;
		int py;
		int x;
		int rx;
	};

	std::vector<MergeOperation> operations;

  public:
	DSURollback(int n) : parent(n), rank(n, 0) {
		std::iota(parent.begin(), parent.end(), 0);
	}

	int root(int x) {
		while (x != parent[x]) {
			x = parent[x];
		}
		return x;
	}

	bool merge(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (rank[x] < rank[y]) {
			std::swap(x, y);
		}
		operations.emplace_back(y, parent[y], x, rank[x]);
		parent[y] = x;
		if (rank[x] == rank[y]) {
			rank[x]++;
		}
		return true;
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	void rollback() {
		if (operations.empty()) {
			return;
		}
		auto [y, py, x, rx] = operations.back();
		operations.pop_back();
		parent[y] = py;
		rank[x] = rx;
	}
};

}; // namespace mog::internal

#endif

namespace mog {

using DSU = mog::internal::DSU;

};

#endif

using namespace std;

#if defined(MOG_LIB)
using namespace mog;
#endif

using ll = long long;

#define int ll

#if defined(MOG_LOCAL)

#else
#define dbg(...) 42
#define dbgif(...) 42
#endif

const int MOD = 1e9 + 7;

mt19937 rng(random_device{}());

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> l(m), r(m);
	vector<int> p(n + 2, -1);
	vector<int> pos(n);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	vector<vector<int>> pl(n + 2), pr(n + 2);
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		pl[l[i]].push_back(i);
		pr[r[i]].push_back(i);
	}
	DSU dsu(m);
	int L = 1, R = n;
	int ans = 0;
	vector<int> xl(n + 2, -1), xr(n + 2, -1);
	int xla = -1;
	int xra = -1;
	for (int cur = 0; cur < n; cur++) {
		for (; L < pos[cur]; L++) {
			for (int j: pr[L]) {
				// dbg(L, j, xla, cur);
				if (xla != -1) {
					if (!dsu.same(xla, j)) {
						dsu.merge(xla, j);
						ans += cur;
						// dbg(xla, j, cur);
					}
				}
				xla = j;
			}
			xl[L + 1] = xla;
		}
		for (; R > pos[cur]; R--) {
			for (int j: pl[R]) {
				// dbg(R, j, xra, cur);
				if (xra != -1) {
					if (!dsu.same(xra, j)) {
						ans += cur;
						dsu.merge(xra, j);
						// dbg(xra, j, cur);
					}
				}
				xra = j;
			}
			xr[R - 1] = xra;
		}
		if (xr[pos[cur]] != -1 && xl[pos[cur]] != -1) {
			if (!dsu.same(xl[pos[cur]], xr[pos[cur]])) {
				dsu.merge(xl[pos[cur]], xr[pos[cur]]);
				ans += cur;
			}
		}
	}
	for (int i = 1; i < m; i++) {
		if (!dsu.same(i, 0)) {
			dsu.merge(i, 0);
			ans += n;
		}
	}
	cout << ans << endl;
    return 0;
}
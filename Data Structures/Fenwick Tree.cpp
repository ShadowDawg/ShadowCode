struct BIT {
	// note: use only 1-based indexing
	vector <ll> tree;
	int n;
	BIT (int n) {
		this->n = n + 1;
		tree.resize(this->n);
	}
	void update (int idx,int d) {
		while (idx < n) {
			tree[idx] += d;
			idx += idx & (-idx);
		}
	}
	ll prefixSum (int n) {
		ll sum = 0;
		while (n > 0) {
			sum += tree[n];
			n -= n & (-n);
		}
		return sum;
	}
	ll rangeSum (int l,int r) {
		return prefixSum(r) - prefixSum(l - 1);
	}
};

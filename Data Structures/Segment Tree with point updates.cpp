struct SegTree {   // O-based indexin
	int N;
	vector <int> arr;
	vector <int> tree;
	SegTree (int n,vector <int> a) { 
		N = 4 * n;
		tree.resize(N);
		arr.resize(N);
		for (int i = 0;i < n;++i)
			arr[i] = a[i];
	}
	int build (int l,int r,int v) {
		if (l == r) {
			tree[v] = arr[l];
		}
		else {
			int mid = l + (r - l) / 2;
			tree[v] = build(l,mid,v * 2) + build(mid + 1,r,v * 2 + 1);
		}
		return tree[v];
	}
	void point_update (int l,int r,int v,int diff,int pos) {
		if (l == r) 
			tree[v] += diff;
		else {
			int mid = l + (r - l) / 2;
			if (pos <= mid)
				point_update(l,mid,v * 2,diff,pos);
			else 
				point_update(mid + 1,r,v * 2 + 1,diff,pos);
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}
	int range_sum (int l,int r,int tl,int tr,int v) {
		if (l >= tl && r <= tr) {
			return tree[v];
		}
		if (l > tr || r < tl)
			return 0;
		int mid = l + (r - l) / 2;
		return range_sum(l,mid,tl,tr,v * 2) + range_sum(mid + 1,r,tl,tr,v * 2 + 1);
	}
};

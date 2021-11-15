// this was used forhttps://codeforces.com/problemset/problem/242/E
// XOR + sum queries in range;
// this code actually uses 20 seg trees for each bit 


const int N = 100001;
int st[20][4 * N];
bool lazy[20][4 * N];
int a[20][N];
void build (int v,int tl,int tr,int i) {
	if (tl == tr)
		st[i][v] = a[i][tl];
	else {
		int tm = tl + (tr - tl) / 2;
		build(v * 2,tl,tm,i);
		build(v * 2 + 1,tm + 1,tr,i);
		st[i][v] = st[i][v * 2] + st[i][v * 2 + 1];
	}
}
void range_update (int v,int tl,int tr,int l,int r,int i) {
	if (lazy[i][v]) {
		st[i][v] = (tr - tl + 1) - st[i][v];   // relation for flipping [XOR, in this case]
		if (tl != tr) {
			lazy[i][2 * v] = !lazy[i][2 * v];
			lazy[i][2 * v + 1] = !lazy[i][2 * v + 1];
		}
		lazy[i][v] = false;
	}
	if (tl > tr || tl > r || tr < l)
		return;
	if (tl >= l && tr <= r) {
		st[i][v] = (tr - tl + 1) - st[i][v];
		if (tl != tr) {
			lazy[i][2 * v] = !lazy[i][2 * v];
			lazy[i][2 * v + 1] = !lazy[i][2 * v + 1];
		}
		return;
	}
	int tm = tl + (tr - tl) / 2;
	range_update(v * 2,tl,tm,l,r,i);
	range_update(v * 2 + 1,tm + 1,tr,l,r,i);
	st[i][v] = st[i][v * 2] + st[i][v * 2 + 1];
}
int range_sum (int v,int tl,int tr,int l,int r,int i) {
	if (tl > tr || tl > r || tr < l)
		return 0;
	if (lazy[i][v]) {
		st[i][v] = (tr - tl + 1) - st[i][v];
		if (tl != tr) {
			lazy[i][v * 2] = !lazy[i][v * 2];
			lazy[i][v * 2 + 1] = !lazy[i][v * 2 + 1];
		}
		lazy[i][v] = 0;
	}
	if (tl >= l && tr <= r) 
		return st[i][v];
	else {
		int tm = tl + (tr - tl) / 2;
		return range_sum(v * 2,tl,tm,l,r,i) + range_sum(v * 2 + 1,tm + 1,tr,l,r,i);
	}
}

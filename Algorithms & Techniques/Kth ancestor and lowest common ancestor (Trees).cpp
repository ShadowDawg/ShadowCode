const int N = 100001;
const int LOG = 17;
int depth[N];
int up[N][LOG];

struct Graph {
	int V;
	vector <int>* adj;
	Graph (int v) {
		V = v;
		adj =  new vector <int> [V];
	}
	void add_edge (int u,int v) {
		adj[u].pb(v);
		adj[v].pb(u);
	}
	void precomp_util (int node,bool visited[]) {
		visited[node] = true;
		for (auto val : adj[node]) {
			if (!visited[val]) {
				depth[val] = depth[node] + 1;
				up[val][0] = node;
				for (int j = 1;j < LOG;++j) {
					up[val][j] = up[ up[val][j - 1] ][j - 1];
				}
				precomp_util(val,visited);
			}
		}
	}
	void precomp () {
		bool visited[V];
		for (int j = 0;j < LOG;++j) 
			up[1][j] = 1;
		for (int i = 0;i < V;++i)
			visited[i] = false;
		precomp_util(1,visited);
	}
	int kth_ancestor (int a,int k) {
		for (int j = LOG;j >= 0;--j) {
			if (k & (1 << j)) {
				a = up[a][j];
			}
		}
		return a;
	}
	int lca (int a,int b) {
		if (depth[a] < depth[b])
			swap(a,b);
		int k = depth[a] - depth[b];
		a = kth_ancestor(a,k);
		if (a == b)
			return a;
		for (int j = LOG - 1;j >= 0;--j) {
			if (up[a][j] != up[b][j]) {
				a = up[a][j];
				b = up[b][j];
			}
		}
		return up[a][0];
	}	
};

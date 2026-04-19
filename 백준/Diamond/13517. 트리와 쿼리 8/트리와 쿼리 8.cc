#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAXN = 100005;
const int INF = 1e9 + 7;

struct Node {
    int l, r, v;
};

int n, m, cnt = 0;
vector<int> adj[MAXN], tour, n2s(1), firstTour(MAXN), root, d, par(MAXN), sorted_d;
vector<pii> range_val(MAXN);
vector<Node> st;
vector<int> st2;

// PST 초기화
int make_st(int start, int end) {
    int node = st.size();
    st.push_back({-1, -1, 0});
    if (start == end) return node;
    
    int mid = (start + end) / 2;
    int left = make_st(start, mid);
    int right = make_st(mid + 1, end);
    st[node].l = left;
    st[node].r = right;
    return node;
}

// PST 업데이트 (안전한 push_back 방식)
void update(int node, int start, int end, int index, int diff) {
    if (start == end) {
        st[node].v += diff;
        return;
    }
    int mid = (start + end) / 2;
    if (index <= mid) {
        int old_l = st[node].l;
        Node next_node = st[old_l]; // 복사본 생성 (참조 무효화 방지)
        st.push_back(next_node);
        st[node].l = st.size() - 1;
        update(st[node].l, start, mid, index, diff);
    } else {
        int old_r = st[node].r;
        Node next_node = st[old_r]; // 복사본 생성
        st.push_back(next_node);
        st[node].r = st.size() - 1;
        update(st[node].r, mid + 1, end, index, diff);
    }
    st[node].v = st[st[node].l].v + st[st[node].r].v;
}

// LCA를 위한 오일러 투어 세그먼트 트리
void make_st2(int node, int start, int end) {
    if (start == end) {
        st2[node] = tour[start];
        return;
    }
    int mid = (start + end) / 2;
    make_st2(node * 2, start, mid);
    make_st2(node * 2 + 1, mid + 1, end);
    st2[node] = min(st2[node * 2], st2[node * 2 + 1]);
}

int get2(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return INF;
    if (left <= start && end <= right) return st2[node];
    int mid = (start + end) / 2;
    return min(get2(node * 2, start, mid, left, right), get2(node * 2 + 1, mid + 1, end, left, right));
}

// K번째 수 찾기
int get_k(int start, int end, int a, int b, int lca, int lca2, int k) {
    if (start == end) return start;
    int diff = st[st[a].l].v + st[st[b].l].v - st[st[lca].l].v - st[st[lca2].l].v;
    int mid = (start + end) / 2;
    if (diff >= k) return get_k(start, mid, st[a].l, st[b].l, st[lca].l, st[lca2].l, k);
    else return get_k(mid + 1, end, st[a].r, st[b].r, st[lca].r, st[lca2].r, k - diff);
}

void dfs(int x, int p) {
    range_val[x].first = ++cnt;
    tour.push_back(range_val[x].first);
    n2s.push_back(x);
    par[x] = p;
    firstTour[x] = tour.size() - 1;

    // PST 경로 생성
    int prev_root = root[range_val[p].first];
    Node root_copy = st[prev_root];
    st.push_back(root_copy);
    root.push_back(st.size() - 1);
    
    // 좌표 압축된 값으로 업데이트
    int val_idx = lower_bound(sorted_d.begin(), sorted_d.end(), d[x]) - sorted_d.begin();
    update(root.back(), 0, sorted_d.size() - 1, val_idx, 1);

    for (int nxt : adj[x]) {
        if (nxt == p) continue;
        dfs(nxt, x);
        tour.push_back(range_val[x].first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;
    d.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> d[i];
    
    sorted_d = d;
    sort(sorted_d.begin() + 1, sorted_d.end());
    sorted_d.erase(unique(sorted_d.begin() + 1, sorted_d.end()), sorted_d.end());

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    st.reserve(4000000); // 메모리 재할당 방지
    int base_root = make_st(0, sorted_d.size() - 1);
    
    // root[0]은 비어있는 트리의 루트 (parent of root 처리에 사용)
    root.push_back(base_root);
    tour.push_back(0); // 1-based indexing을 위해 dummy 추가
    
    dfs(1, 0);

    st2.resize(tour.size() * 4);
    make_st2(1, 1, tour.size() - 1);

    cin >> m;
    while (m--) {
        int i, j, k; cin >> i >> j >> k;
        int ti = firstTour[i], tj = firstTour[j];
        if (ti > tj) swap(ti, tj);
        
        int lca_cnt = get2(1, 1, tour.size() - 1, ti, tj);
        int lca_node = n2s[lca_cnt];
        
        int ans_idx = get_k(0, sorted_d.size() - 1, 
                           root[range_val[i].first], root[range_val[j].first], 
                           root[range_val[lca_node].first], root[range_val[par[lca_node]].first], k);
        cout << sorted_d[ans_idx] << "\n";
    }

    return 0;
}
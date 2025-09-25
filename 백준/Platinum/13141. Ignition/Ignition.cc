#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e9;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  ll ans = INF;

  vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, INF));
  vector<ll> S(M + 1, 0);
  vector<ll> E(M + 1, 0);
  vector<ll> L(M + 1, 0);

  for (int i = 1; i <= N; i++) {
    dist[i][i] = 0;
  }

  for (int i = 1; i <= M; i++) {
    cin >> S[i] >> E[i] >> L[i];
    
    // 길이가 최소인 간선만 dist에 저장
    dist[S[i]][E[i]] = min(dist[S[i]][E[i]], L[i]);
    dist[E[i]][S[i]] = min(dist[E[i]][S[i]], L[i]);
  }
  
    // 플로이드 워셜
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
    
    // i번 정점에서 불을 붙일 때 모든 간선이 다 타는 시각 구하기
  for (int i = 1; i <= N; i++) {
    ll sum = 0;
    
      // 모든 간선 중 가장 오래동안 다 타지 않는 간선이 타는 시각 구하기
    for (int j = 1; j <= M; j++) {
      sum = max(sum, dist[i][S[j]] + dist[i][E[j]] + L[j]);
    }
    ans = min(ans, sum);
  }

  cout << ans / 2 << "." << (ans % 2 ? 5 : 0);

  return 0;
}
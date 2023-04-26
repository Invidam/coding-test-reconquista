

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// 작은 요소 먼저 pop (내림차순 정렬 후 인덱스 높은 것(큰거)부터 출력)
// a.first == b.first ? a.second > b.second;

priority_queue<pair<int, int>> pq;
// 큰 요소 먼저 pop (오름차 정렬 후 인덱스 높은 것(큰거)부터 출력 )

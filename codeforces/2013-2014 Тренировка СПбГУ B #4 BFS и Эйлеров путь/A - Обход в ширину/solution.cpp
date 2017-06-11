#include <cstdio>
#include <iostream>
#include <queue>

#define For(i, start, end) for (int (i) = (start); (i) < (end); (i)++)

using namespace std;

int main() {
	freopen("bfs.in","r",stdin);
	freopen("bfs.out","w",stdout);
	int n, s, f, arr[100][100], d[100] = {0}, used[100] = {0};

	cin >> n >> s >> f;
	For(i, 0, n)
		For(j, 0, n) 
			cin >> arr[i][j];

	queue<int> q;
	q.push(s-1);
	used[s-1] = 1;
	while (q.size() != 0) {
		int v = q.front();
		q.pop();
		For(i, 0, n) {
			if (!used[i] && arr[v][i]) {
				q.push(i);
				used[i] = 1;
				d[i] = d[v] + 1;
			}
		}	
	}

	cout << d[f-1];	
	
	return 0;
}
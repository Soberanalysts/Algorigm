#include<iostream>
#include<queue>

using namespace std;
#define MAX 51

int N, L, R, arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> q;
vector<pair<int, int>> v;

bool flag = true; //���տ���
int sum = 0; //����� ���ϱ� ���� ����

void bfs(pair<int, int> start) { //bfs
	q.push(start);
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int na = temp.first + dx[i];
			int nb = temp.second + dy[i];

			//���� �ȿ� �ְ� �α� ���̰� L �̻�, R ���� ���� üŷ
			if (na >= 0 && nb >= 0 && na < N && nb < N && !visited[na][nb]) {
				if (abs(arr[na][nb] - arr[temp.first][temp.second]) >= L &&
					abs(arr[na][nb] - arr[temp.first][temp.second]) <= R) {
					q.push({ na, nb });
					visited[na][nb] = true;

					v.push_back({ na, nb });
					sum += arr[na][nb]; //����� ���ϱ� ����
				}
			}
		}
	}
}

void clear() { //�湮 �ʱ�ȭ
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}

int main() {
	int days = 0; //��� �ʱ�ȭ

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) //�� �Է¹ޱ�
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	while (flag) { //������ �Ͼ�� ��� �ݺ�
		flag = false; //���� ���� �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) { //�湮�� �� �ߴٸ�
					v.clear();
					v.push_back({ i,j });
					sum = arr[i][j];
					bfs({ i, j });
				}

				//���� ����
				if (v.size() >= 2) {
					flag = true; //���� üũ
					for (int i = 0; i < v.size(); i++) {
						arr[v[i].first][v[i].second] = sum / v.size(); //��� ����
					}
				}
			}
		}
		if (flag) days++; //�ѹ���

		clear(); //�ʱ�ȭ
	}
	cout << days; //���
}
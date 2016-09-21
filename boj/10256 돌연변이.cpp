//���ڿ� �˻� ��ȣ �ڶ�� ����ȭ
// ��带 �߰��ҋ� �����Ÿ� ������ �ȵǳ�????
//���������� �絵 ���� ¤���̵� ���
//������ Ʈ���̳�Ʈ�� �����ϸ� �ð��ʰ��� ����
//����ϴ� ���ڴ� 4�����̹Ƿ� �����ִ� next�� 4���� �����
//���������� ����µ� �����Ѵ� �̶��� stl�� �߾��� ���ϰԵȴ�
//��ȣ �ڶ�Ŀ����� �ð����⵵�� ã�°� �Ӹ� �ƴ϶� Ʈ���̳�带 �����ϴµ��� 
//�ð��� ���� �ɸ��°��� ����Ѵ�

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

#define LL long long
#define pii pair < int,int>
#define si(a) scanf("%d",&(a))
#define ss(a) scanf("%s",(a))
#define sLL(a) scanf("%lld",&(a))
#define INF 1234567890
#define LLINF 12345678912345678
#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////////////
int T;
#define MAX_N 1000001
#define MAX_M 101
#define ALPHABETS 4
char str[MAX_N];
int n, m;
char temp[MAX_M];
// Ʈ������ �� ��带 ��Ÿ���� ��ü
int h[128];
struct TrieNode {
	TrieNode* children[ALPHABETS];
	int terminal;
	TrieNode* fail;
	bool output;

	TrieNode() : terminal(-1), output(false) {
		memset(children, 0, sizeof(children));
	}

	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++)
			if (children[i])
				delete children[i];
	}

	void insert(const string& key, int index) {
		if (key.size() == index)
			terminal = 1;
		else {
			int next = h[key[index]];
			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key, index + 1);
		}
	}
};
void computeFailFunc(TrieNode* root) {
	queue<TrieNode*> q;
	root->fail = root;
	q.push(root);

	while (!q.empty()) {
		TrieNode* here = q.front();
		q.pop();
		for (int edge = 0; edge < ALPHABETS; ++edge) {
			TrieNode* child = here->children[edge];
			if (!child) continue;
			if (here == root)
				child->fail = root;
			else {
				TrieNode* t = here->fail;
				while (t != root && t->children[edge] == NULL)
					t = t->fail;
				if (t->children[edge]) t = t->children[edge];
				child->fail = t;
			}
			child->output = child->fail->output;
			if (child->terminal != -1)
				child->output = true;
			q.push(child);
		}
	}
}
int ahoCorasick(const string& s, TrieNode* trie) {
	int ret = 0;

	TrieNode* state = trie;
	for (int i = 0; i < n; i++) {
		int chr = h[s[i]];
		while (state != trie && state->children[chr] == NULL)
			state = state->fail;
		if (state->children[chr]) state = state->children[chr];
		if (state->output)
			ret++;
	}
	return ret;
}
int main() {
	h['A'] = 0;
	h['C'] = 1;
	h['G'] = 2;
	h['T'] = 3;

	for (si(T); T>0; T--) {
		si(n); si(m);
		memset(str, 0, sizeof(str));
		memset(temp, 0, sizeof(temp));
		ss(str);
		ss(temp);
		TrieNode* root = new TrieNode();
		//trie ���� ����
		string mark(temp);
		vector<string> vs;
		vs.push_back(mark);
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j <= m; j++) {
				reverse(mark.begin() + i, mark.begin() + j);
				vs.push_back(mark);
				reverse(mark.begin() + i, mark.begin() + j);
			}
		}
		sort(all(vs));
		vs.erase(unique(all(vs)), vs.end());
		for (int i = 0; i < vs.size(); i++) {
			root->insert(vs[i], 0);
		}
		//�����Լ�����
		computeFailFunc(root);

		LL a = ahoCorasick(string(str), root);
		printf("%lld\n", a);
	}
}
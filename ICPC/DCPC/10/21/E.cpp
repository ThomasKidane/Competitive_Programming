#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	map<string, int> classes;
	bool isa[n][n];
	bool hasa[n][n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			isa[i][j] = false;
			hasa[i][j] = false;
		}

	int cls_count = 0;
	for (int i = 0; i < n; i++)
	{
		string a,k,b;
		cin >> a >> k >> b;
		if (!classes.contains(a))
		{
			classses[a] = cls_count;
			cls_count++;
		}
		if (!classes.contains(b))
		{
			classses[b] = cls_count;
			cls_count++;
		}
		if (k == "is-a")
			isa[classes[a]][classes[b]] = true;
		else if (k == "has-a")
			hasa[classes[a]][classes[b]] = true;
	}
	for (int i = 0; i < m; i++)
	{
		cout << "Query " << i + 1 << ": ";
		string a, k, b;
		// TODO: BFS/DFS to find path between a and b (directed)
		if (k == "is-a")
			cout << isa_path_exists(classes[a], classes[b], isa) << endl;
		if (k == "has-a")
			cout << hasa_path_exists(classes[a], classes[b], hasa, isa) << endl;
	}
	return 0;
}

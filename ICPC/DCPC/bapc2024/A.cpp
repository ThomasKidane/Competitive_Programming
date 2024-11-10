#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef struct two
{
    int rank, prob;
} two;

two find_ps(char** table, int n, int m)
{
    two res;
    res.prob = -1;
    res.rank = -1;
    for (int r = n - 1; r >= 0; r--)
        for (int p = 0; p < m; p++)
            if (table[r][p] == 'P')
            {
                res.prob = p;
                res.rank = r;
                return res;
            }
    return res;
}
int main()
{
    int n,m,r;
    cin >> n >> m >> r;
    char **table = (char **)malloc(n * sizeof(char *));

    // char table[n][n];
    int p_count =  0;
    int curr_prank = -1;
    for (int i = 0; i < n; i++)
    {
        table[i] = (char*)malloc(m);
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            table[i][j] = s[j];
	        cout << i << ' ' << j << ' ' << s[j] << endl;
            if (table[i][j] == 'P')
            {
                p_count++;
                curr_prank = i;
            }
        }
    }
    char *tmp = (char *)malloc(m);
    for (int i = 0; i < p_count; i++)
    {
        string oohs, aahs;
        cin >> oohs >> aahs;
        char res = aahs[3];
        two pos = find_ps(table, n, m);
	cout << pos.rank << pos.prob << endl;
        if (res == 'w')
            table[pos.rank][pos.prob] = 'R';
        else
        {
            int delta_rank = aahs.length() - 9;
            if (pos.rank == r)
		r -= delta_rank;
            else if (pos.rank > r && pos.rank - r < delta_rank)
                r++;
            
            memcpy(table[pos.rank], tmp, m);
            for (int r = pos.rank; r > pos.rank - delta_rank; r--)
            {
                memcpy(table[r - 1], table[r], m);
            }
            memcpy(tmp, table[pos.rank - delta_rank], m);
        }
    }
    cout << r;
    return 0;
}

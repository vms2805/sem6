#include <bits/stdc++.h>
using namespace std;
#define ll long long

class A_star_Algorithm
{
public:
    int Heuristicvalue(vector<vector<int>> &initial, vector<vector<int>> &target)
    {
        vector<pair<int, int>> a(9);
        vector<pair<int, int>> b(9);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int val = initial[i][j];
                a[val] = {i, j};
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int val = target[i][j];
                b[val] = {i, j};
            }
        }

        int cost = 0;
        for (int i = 0; i < 9; i++)
        {
            int inix = a[i].first;
            int iniy = a[i].second;
            int finx = b[i].first;
            int finy = b[i].second;

            cost += (abs(inix - finx));
            cost += (abs(iniy - finy));
        }
        return cost;
    }

    void solve(vector<vector<int>> &initial, vector<vector<int>> &target, int cost, int &f, vector<vector<vector<int>>> &ans)
    {
        if (initial == target)
        {
            f = cost;
            return;
        }

        if (cost >= 100)
        {
            f = -1;
            return;
        }

        int x, y;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (initial[i][j] == 0)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        vector<array<int, 3>> dummy;

        // moving down
        if (x + 1 < 3)
        {
            swap(initial[x][y], initial[x + 1][y]);
            int c = Heuristicvalue(initial, target);
            swap(initial[x][y], initial[x + 1][y]);
            array<int, 3> h = {c, x + 1, y};
            dummy.push_back(h);
        }

        // moving up
        if (x - 1 >= 0)
        {
            swap(initial[x][y], initial[x - 1][y]);
            int c = Heuristicvalue(initial, target);
            swap(initial[x][y], initial[x - 1][y]);
            array<int, 3> h = {c, x - 1, y};
            dummy.push_back(h);
        }

        // move right
        if (y + 1 < 3)
        {
            swap(initial[x][y], initial[x][y + 1]);
            int c = Heuristicvalue(initial, target);
            swap(initial[x][y], initial[x][y + 1]);
            array<int, 3> h{c, x, y + 1};
            dummy.push_back(h);
        }

        // move left
        if (y - 1 >= 0)
        {
            swap(initial[x][y], initial[x][y - 1]);
            int c = Heuristicvalue(initial, target);
            swap(initial[x][y], initial[x][y - 1]);
            array<int, 3> h{c, x, y - 1};
            dummy.push_back(h);
        }

        sort(dummy.begin(), dummy.end());

        int movex = dummy[0][1];
        int movey = dummy[0][2];

        swap(initial[x][y], initial[movex][movey]);
        ans.push_back(initial);
        solve(initial, target, cost + 1, f, ans);
    }
};

int main()
{
    vector<vector<int>> initial(3, vector<int>(3));
    vector<vector<int>> target(3, vector<int>(3));

label1:
    cout << "Enter the initial state of the puzzle: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            string s;
            cin >> s;

            for (int k = 0; k < s.length(); k++)
            {
                if (!isdigit(s[k]) or s[i] == '9')
                {
                    cout << "*Enter the correct input*" << endl;
                    goto label1;
                }
            }
            initial[i][j] = stoi(s);
        }
    }

label2:
    cout << "Enter the final state of the puzzle: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            string s;
            cin >> s;

            for (int k = 0; k < s.length(); k++)
            {
                if (!isdigit(s[k]) or s[i] == '9')
                {
                    cout << "*Enter the correct input*" << endl;
                    goto label2;
                }
            }
            target[i][j] = stoi(s);
        }
    }

    vector<vector<vector<int>>> ans;
    int f;
    A_star_Algorithm obj = A_star_Algorithm();
    obj.solve(initial, target, 0, f, ans);

    if (f == -1)
    {
        cout << "The Puzzle is unsolvable: " << endl;
    }
    else
    {
        cout << "The moves required are : " << f << endl;

        for (int i = 0; i < ans.size(); i++)
        {
            cout << "The " << (i + 1) << " move is" << endl;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    cout << ans[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
            cout << endl;
        }
    }

    return 0;
}
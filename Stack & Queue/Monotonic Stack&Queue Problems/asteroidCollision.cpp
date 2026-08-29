#include <bits/stdc++.h>
using namespace std;
// vector<int> asteroidCollision(vector<int> &asteroids)
// {
//     int i = 0;
//     vector<int> ans;

//     while (i < asteroids.size())
//     {
//         if (asteroids[i] > 0 && asteroids[i + 1] > 0)
//         {
//             ans.push_back(asteroids[i]);
//         }
//         else
//         {
//             if (abs(asteroids[i]) > abs(asteroids[i + 1]))
//             {
//                 ans.push_back(asteroids[i]);
//                 i++;
//             }
//             else if (abs(asteroids[i]) < abs(asteroids[i + 1]))
//             {
//                 ans.push_back(asteroids[i + 1]);
//                 i++;
//             }
//             else
//             {
//                 i++;
//             }
//         }
//         i++;
//     }
//     return ans;
// }

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> ans;

    for (int i = 0; i < asteroids.size(); i++)
    {
        int current = asteroids[i];

        while (!ans.empty() && ans.back() > 0 && current < 0)
        {
            int last = ans.back();

            if (abs(last) < abs(current))
            {
                ans.pop_back();
            }
            else if (abs(last) == abs(current))
            {
                ans.pop_back();
                current = 0;
                break;
            }
            else
            {
                current = 0;
                break;
            }
        }

        if (current != 0)
        {
            ans.push_back(current);
        }
    }
    return ans;
}

int main()
{
    vector<int> asteroids = {5, 10, -5};
    vector<int> ans = asteroidCollision(asteroids);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int romanToInt(string str)
{
    // for (auto &i : romanMap)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    // for (unordered_map<char, int>::iterator it = romanMap.begin(); it != romanMap.end(); ++it)
    // {
    //     cout << it->first << " : " << it->second << std::endl;
    // }

    // auto it = next(romanMap.begin(), 0);
    // auto it1 = next(romanMap.begin(), 1);
    // auto it2 = next(romanMap.begin(), 2);
    // auto it3 = next(romanMap.begin(), 3);
    // auto it4 = next(romanMap.begin(), 4);
    // auto it5 = next(romanMap.begin(), 5);
    // auto it6 = next(romanMap.begin(), 6);

    // // // To get the Key ('I', 'V', etc.)

    // // // To get the Value (1, 5, etc.)
    // // int value = it->second;

    // std::cout << "First Key: " << it->first << std::endl;
    // std::cout << "First Key: " << it1->first << std::endl;
    // std::cout << "First Key: " << it2->first << std::endl;
    // std::cout << "First Key: " << it3->first << std::endl;
    // std::cout << "First Key: " << it4->first << std::endl;
    // std::cout << "First Key: " << it5->first << std::endl;
    // std::cout << "First Key: " << it6->first << std::endl;

    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int totalSum = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (romanMap[str[i]] < romanMap[str[i + 1]])
        {
            totalSum -= romanMap[str[i]];
        }
        else
        {
            totalSum += romanMap[str[i]];
        }
    }
    return totalSum;
}

int main()
{
    string str;
    cout << "Enter a Roman numeral: ";
    cin >> str;
    for (char &c : str)
        c = toupper(c);
    int result = romanToInt(str);
    cout << "Roman to Int Sum: " << result;
    return 0;
}
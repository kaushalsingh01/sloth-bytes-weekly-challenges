#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sevenBoom(const vector<string> &arr)
{
    bool found = false;
    for (const auto &line : arr)
    {
        for (char ch : line)
        {
            if (ch == '7')
            {
                cout << "Boom! ";
                found = true;
            }
        }
    }
    if (!found)
    {
        cout << "there is no 7 in the input";
    }
}

int main()
{
    vector<string> arrLines;
    string line;

    // Press Enter on an empty line to stop input
    while (true)
    {
        getline(cin, line);
        if (line.empty())
            break;
        arrLines.push_back(line);
    }

    sevenBoom(arrLines);

    return 0;
}
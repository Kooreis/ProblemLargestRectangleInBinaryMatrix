```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxHist(int row[], int C)
{
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while (i < C)
    {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
        else
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty())
    {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(int A[][100], int R, int C)
{
    int result = maxHist(A[0], C);
    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            if (A[i][j])
                A[i][j] += A[i - 1][j];
        result = max(result, maxHist(A[i], C));
    }
    return result;
}

int main()
{
    int R, C;
    cin >> R >> C;
    int A[100][100];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> A[i][j];
    cout << "Area of maximum rectangle is " << maxRectangle(A, R, C);
    return 0;
}
```
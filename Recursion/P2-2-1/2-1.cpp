#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> shift_to_left(vector<int> numbers, int n)
{
    if (numbers.size() == (n+1)) return numbers;
    int shift_number = numbers.back();
    numbers.pop_back();
    int temp = numbers.back();
    numbers.pop_back();
    numbers.push_back(shift_number);
    numbers = shift_to_left(numbers,n);
    numbers.push_back(temp);
    return numbers;
}
vector<int> reverse(vector<int> numbers, int n)
{
    if (n == (numbers.size()-1))
        return numbers;
    numbers = shift_to_left(numbers, n);
    return reverse(numbers, n+1);
}
int main()
{
    vector<int> numbers, result;
    int number;
    while (cin >> number)
        numbers.push_back(number);
    result = reverse(numbers,0);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool sort_check(vector<int> numbers)
{
    if (numbers.size() == 1) return true;
    int last;
    last = numbers.back();
    numbers.pop_back();
    int temp = numbers.back();
    if (temp > last) return false;
    else return sort_check(numbers);

}
vector<int> bit_sort(vector<int> numbers)
{
    int last, second_to_last, temp;
    if (numbers.size() == 1) return numbers;
    last = numbers.back();
    numbers.pop_back();
    second_to_last = numbers.back();
    numbers.pop_back();
    if (last >= second_to_last)
    {
        numbers.push_back(second_to_last);
        numbers = bit_sort(numbers);
        numbers.push_back(last);
        return numbers;
    }
    else 
    {
        numbers.push_back(last);
        numbers = bit_sort(numbers);
        numbers.push_back(second_to_last);
        return numbers;
    }
}
vector<int> recursive_sort(vector<int> numbers)
{
    if (sort_check(numbers))
        return numbers;
    numbers = bit_sort(numbers);
    return numbers;
}
int main()
{
    vector<int> numbers, result;
    int number;
    while (cin >> number)
        numbers.push_back(number);
    result = recursive_sort(numbers);
    for (int i = 0; i < result.size(); i++)
         cout << result[i] << " ";
    cout << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int Maximum_Cells_Around = 8;
const int out_of_reach = -1;
int row_delta[Maximum_Cells_Around] = { 0, 1, 1, 1, 0,-1,-1,-1};
int col_delta[Maximum_Cells_Around] = { 1, 1, 0,-1,-1,-1, 0, 1};
int mine_calculator(vector <string> map, int x, int y)
{
	int count, num_of_rows, num_of_columns, new_row, new_column;
	num_of_rows = map.size();
	num_of_columns = map[0].size();
	count = 0;
	for (int i = 0; i < Maximum_Cells_Around; i++)
	{
		new_row = y + row_delta[i];
		new_column = x + col_delta[i];
		if ((new_row != out_of_reach) && (new_row != num_of_rows) && (new_column != out_of_reach) &&
        (new_column != num_of_columns) && (map[new_row][new_column] == 'M'))
			count ++;
	}
	return count;
}
vector<string> map_process(vector<string> map, int y, int x)
{
	int count, num_mines, num_of_rows, num_of_columns, new_row, new_column ;
	string s;
	char num_of_mines;
	num_of_rows = map.size();
	num_of_columns = map[0].size();
	num_mines = mine_calculator(map, x, y);
	num_of_mines = num_mines + '0';
    map[y][x] = num_of_mines;
	if (num_of_mines == '0')	
	    for (int i = 0; i < Maximum_Cells_Around; i++)
	    {
    		new_row = y + row_delta[i];
	    	new_column = x + col_delta[i];
		    if ((new_row != out_of_reach) && (new_row != num_of_rows) && (new_column != out_of_reach) &&
            (new_column != num_of_columns) && (map[new_row][new_column] == '.'))
			    map = map_process(map, new_row, new_column);
	    }
	return map;
}
vector<string> map_fill(vector<string> map)
{
	for (int i = 0; i < map.size(); i++)
		for (int j = 0; j < map[i].size(); j++)
			if ((map[i][j] == 'M') || (map[i][j] == '.'))
				map[i][j] = '*';
	return map;
}

int main()
{
	vector <string> map, updated_map;
	string row;
	int number_of_rows, number_of_columns, start_x, start_y; 
	cin >> number_of_rows >> number_of_columns >> start_x >> start_y;
    getline(cin, row);
	for (int i = 0; i < number_of_rows; i++)
	{	
		getline(cin, row);
		map.push_back(row);
	}
	updated_map = map_fill(map_process(map, start_y - 1 ,start_x - 1));
	for (int i = 0; i < updated_map.size(); i++)
		cout << updated_map[i] << endl;
}
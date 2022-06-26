#include <iostream>
#include <string>
#include "minesweeper.h"

using namespace std;
 
 int main() {
     srand(time(NULL));
	int h, w;
	cin >> h >> w;
	MineSweepeer M(h,w);
	vector<vector<char>> fr(h, vector<char>(w, '*'));
	vector<vector<char>> bck(h, vector<char>(w, '0'));
	M.SetMines(bck, 21);
	M.FillCells(bck);
	bool game = true;
	M.Print(fr);
	cout << "Free cells remainnig: " << M.GetFreeCells() << "\n";
	while (game)
	{
		int y, x;
		char z = 'o';
		cin >> z;
		cin >> y >> x;
		if (z == '|')
		{
			if (fr[y][x] == z) {
				fr[y][x] = '*';
				M.Print(fr);
				continue;
			}
			fr[y][x] = z;
			M.Print(fr);
			continue;
		}
		game = M.open(fr, bck, y, x);
		if (!game)
		{
			cout << "You lose T_T\n";
			return 0;
		}
		M.Print(fr);
		if (M.GetFreeCells() == 0 )
		{
			cout << "You win !!!\n";
			return 0;
		}
		cout << "Free cells remainnig: " << M.GetFreeCells() << "\n";

	}
	return 0 ;
 }

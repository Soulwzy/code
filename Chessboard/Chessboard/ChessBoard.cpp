#include <iostream>
#include <time.h>

#define SIZE 1024*16

using namespace std;

int Board[SIZE][SIZE] = {};
int tile = 1;

void ChessBoard(int br, int bc, int wr, int wc, int size)
{
	

	if (size == 1) return;

	int t = tile++;
	int s = size / 2;
	if (wr < br + s && wc < bc + s)
	{
		ChessBoard(br, bc, wr, wc, s);
	}
	else
	{
		Board[br + s - 1][bc + s - 1] = t;
		ChessBoard(br, bc, br + s - 1, bc + s - 1, s);
	}
	if (wr < br + s && wc >= bc + s)
	{
		ChessBoard(br, bc + s, wr, wc, s);
	}
	else
	{
		Board[br + s - 1][bc + s] = t;
		ChessBoard(br, bc + s, br + s - 1, bc + s, s);
	}
	if (wr >= br + s && wc < bc + s)
	{
		ChessBoard(br + s, bc, wr, wc, s);
	}
	else
	{
		Board[br + s][bc + s - 1] = t;
		ChessBoard(br + s, bc, br + s, bc + s - 1, s);
	}
	if (wr >= br + s && wc >= bc + s)
	{
		ChessBoard(br + s, bc + s, wr, wc, s);
	}
	else
	{
		Board[br + s][bc + s] = t;
		ChessBoard(br + s, bc + s, br + s, bc + s, s);
	}
}

int main()
{
	clock_t start_time = clock();

	{
		ChessBoard(0, 0, 3, 3, SIZE);
		/*for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				cout << Board[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;*/
	}

	clock_t end_time = clock();
	cout << "运行时间是: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;//输出运行时间
	//getchar();
	return 0;
}
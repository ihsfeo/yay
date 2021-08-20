#include <iostream>
#include <string>
using namespace std;
int x, y;
int n = 1, m = 1;
int b = 15, c = 15, d = 5, e = 22,f=21, g=34,h=4,i=35,j=8,k=7,l=35,o=10,p=19,q=23,r=35,s=35;
int as = 47, sa = 48;

void printmap (void)
{
	string array[40][40];

	for (x = 0;x < 40;x++)
	{
		for (y = 0;y < 40;y++)
		{
			if (x == 0)
			{
				array[x][y] = as;
				as++;
				if (as == 58)
				{
					as = 48;
				}

			}
			else if (y == 0)
			{
				array[x][y] = sa;
				sa++;
				if (sa == 58)
				{
					sa = 48;
				}
			}
			else if (y == 13&& x > 13 && x<17|| y == 17 && x > 13 && x < 17)
			{
				array[x][y] = "#";
			}
			else if(x == 13&&y>13&&y<17 || x == 17 && y > 13 && y < 17)
			{
				array[x][y] = "#";
			} //coordinates for L


			else if (y == 19 && x > 2 && x < 8 || y == 25 && x > 2 && x < 8)
			{
				array[x][y] = "#";
			}
			else if (x == 2 && y > 19 && y < 25 || x == 8 && y > 19 && y < 25)
			{
				array[x][y] = "#";
			} //coordinate for V


			else if (y == 32 && x > 17 && x < 24 || y == 36 && x > 17 && x < 24)
			{
				array[x][y] = "#";
			}
			else if (x == 24 && y > 32 && y < 36 || x == 17 && y > 32 && y < 36)
			{
				array[x][y] = "#";
			}//coordinate for G


			else if (y == 40 && x > 1 && x < 7 || y == 30 && x > 1 && x < 7)
			{
				array[x][y] = "#";
			}
			else if (x == 1 && y >30 && y < 40 || x == 7 && y > 30 && y < 40)
			{
				array[x][y] = "#";
			}//coordinate for I


			else if (y == 4 && x > 4 && x < 12 || y == 9 && x > 4 && x < 12)
			{
				array[x][y] = "#";
			}
			else if (x == 4 && y > 4 && y < 9 || x == 12 && y > 4 && y < 9)
			{
				array[x][y] = "#";
			}//coordinate for F


			else if (y == 5 && x >30 && x < 40 || y == 15 && x > 30 && x < 40)
			{
				array[x][y] = "#";
			}
			else if (x == 30 && y > 5 && y < 15 || x == 40 && y > 5 && y < 15)
			{
				array[x][y] = "#";
			}//coordinate for A


			else if (y == 20 && x > 15 && x < 23 || y == 26 && x > 15 && x < 23)
			{
				array[x][y] = "#";
			}
			else if (x == 15 && y > 20 && y < 26 || x == 23 && y > 20 && y < 26)
			{
				array[x][y] = "#";
			}// coordinate for H


			else if (y == 40 && x >30 && x <40 || y == 30 && x > 30 && x < 40)
			{
				array[x][y] = "#";
			}
			else if (x == 40 && y > 30 && y < 40 || x == 30 && y > 30 && y < 40)
			{
				array[x][y] = "#";
			}// coordinate for N


			else if (y == 5 && x > 12 && x < 16 || y == 8 && x > 12 && x < 15)
			{
				array[x][y] = "+";
			}
			else if (x == 14 && y > 8 && y < 13 || x == 16 && y > 4 && y < 13)
			{
				array[x][y] = "+";
			}// coordinate for route between F and L


			else if (y == 16 && x > 17 && x < 21 || y == 14 && x > 17 && x < 21 || y == 8 && x > 19 && x < 30 || y == 10 && x > 21 && x < 30)
			{
			array[x][y] = "+";
			}
			else if (x == 20 && y > 16 && y < 20 || x == 22 && y > 10 && y < 20|| x == 20 && y > 7 && y < 14)
			{
			array[x][y] = "+";
			}// coordinate for joint route between L,H and A


			else if (y == 21 && x > 8 && x < 15 || y == 24 && x > 8 && x < 15)
			{
			array[x][y] = "+";
			}// coordinate for route between H and V


			else if (x == 3 && y >25 && y < 30 || x == 6 && y > 25 && y < 30)
			{
			array[x][y] = "+";
			}// coordinate for route between V and I


			else if (x == 18 && y > 26 && y < 32 || x == 21 && y > 26 && y < 32)
			{
			array[x][y] = "+";
			}// coordinate for route between H and G


			else if (x == 34 && y > 15 && y < 30 || x == 37 && y > 15 && y < 30)
			{
			array[x][y] = "+";
			}// coordinate for route between A and N


			else if (y == 35 && x > 24 && x < 30 || y == 33 && x > 24 && x < 30)
			{
			array[x][y] = "+";
			}// coordinate for route between G and N


			else
			{
				array[x][y] = " ";

			}
		}
	}

	

array[n][m] = "P";
array[b][c] = "L";
array[d][e] = "F";
array[f][g] = "G";
array[h][i] = "I";
array[j][k] = "V";
array[l][o] = "A";
array[p][q] = "H";
array[r][s] = "N";

}

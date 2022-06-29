#include <iostream>
#include <Windows.h>

using namespace std;

static const unsigned int X = 21;
static const unsigned int Y = 41;
int polje[X][Y];

void inicijalizacijaPolja() {
	int n = 0;
	for (int i = 1; i < X; i++)
	{
		for (int j = 1; j < Y; j++)
		{
			polje[i][j] = n;
			n++;
		}
	}
}

void draw(int polje[X][Y], int redakA, int stupacA, int redakB, int stupacB, int redakCrticaX, int stupacCrticaX) {
	system("cls");
	for (int i = 1; i < X; i++)
	{
		for (int j = 1; j < Y; j++)
		{
			if (polje[i][j] == polje[redakA][stupacA])
			{
				cout << 'A';
			}
			else if (polje[i][j] == polje[redakCrticaX][stupacCrticaX])
			{
				cout << 'x';
			}
			else if (polje[i][j] == polje[redakB][stupacB])
			{
				cout << 'B';
			}
			else
			{
				cout << '-';
			}
		}
		cout << endl;
	}
}

void pathfinder(int polje[X][Y], int redakA, int stupacA, int redakB, int stupacB) {

	int visinaX = redakA;
	int sirinaX = stupacA;

	while (polje[visinaX][sirinaX] != polje[redakB][stupacB])
	{
		if (visinaX < redakB)
		{
			draw(polje, redakA, stupacA, redakB, stupacB, ++visinaX, sirinaX);
		}
		else if (visinaX > redakB)
		{
			draw(polje, redakA, stupacA, redakB, stupacB, --visinaX, sirinaX);
		}
		if (sirinaX < stupacB)
		{
			draw(polje, redakA, stupacA, redakB, stupacB, visinaX, ++sirinaX);
		}
		else if (sirinaX > stupacB)
		{
			draw(polje, redakA, stupacA, redakB, stupacB, visinaX, --sirinaX);
		}
		Sleep(100);
	}
}

int main() {

	inicijalizacijaPolja();

	int redakA, stupacA;
	int redakB, stupacB;

	bool dalje;
	do
	{
		system("cls");

		cout << "Redak A: ";
		cin >> redakA;
		cout << "Stupac A: ";
		cin >> stupacA;
		cout << "Redak B: ";
		cin >> redakB;
		cout << "Stupac B: ";
		cin >> stupacB;

		pathfinder(polje, redakA, stupacA, redakB, stupacB);

		cout << endl;

		cout << "Dalje(1-DA/0-NE): ";
		cin >> dalje;
	} while (dalje);


	return 0;
}
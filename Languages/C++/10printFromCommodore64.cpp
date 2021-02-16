/*
	
	I'm writing this program to spread awareness of the old tricks in the book
	 that people used to create art in a limited envoronment like a commandline
	 console.
	 
	 This specific program provides a demonstration of the "10print" art 
	 that first originated on the old tech machine "commodore64". This art
	 is generated on a command line by randomly outputting forward slashes
	 or backslashes continuously.
	 However, I've used bgi graphics here to obtain a picture perfect result.
	 
	 Also, a demonstration for function pointers
	 
	 while compiling, use linker options:
	 
	 	-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
makeway4pK
*/

#include <graphics.h>
#include <time.h>
using namespace std;
#define cell 25
class Slash
{
	int buf[682]; // increase buffer size if you increase cell size
public:
	Slash(void (*points)(int *buf))
	{
		points(buf); //using the function pointer
		cleardevice();
		fillpoly(6, buf);
		getimage(0, 0, cell, cell, buf);
	}
	void put(int x, int y) { putimage(x * cell, y * cell, buf, COPY_PUT); }
};
void forwSlash(int *), backSlash(int *);

//optional args : size of print
int main(int argc, char *argv[])
{
	srand(time(NULL));
	unsigned short size;
	if (argc < 2)
		size = 20 + rand() % 30;
	else
		size = stoi(argv[1]);
	if (size < 1)
		return 0;
	// int buf[12];
	int dimensions = cell * size;
	initwindow(dimensions, dimensions, "10Print inspired by commodore64");
	setbkcolor(COLOR(65, 48, 164));
	setfillstyle(SOLID_FILL, COLOR(123, 113, 213));
	setlinestyle(SOLID_LINE, 1, 1);
	setcolor(COLOR(123, 113, 213));
	// return imagesize(cell, cell, 0, 0); // check reqd. buffer if you change cell size
	Slash forw(forwSlash), back(backSlash); //passing functions as parameters

	// Generating the print
	for (int j = 0; j < size; j++)
		for (int i = 0; i < size; i++)
			if (rand() % 2)
				forw.put(i, j);
			else
				back.put(i, j);

	getch();
	closegraph();
	return 0;
}

void backSlash(int *buf)
{
	buf[0] = 0;
	buf[1] = 0;
	buf[2] = (cell - 1) / 4;
	buf[3] = 0;
	buf[4] = (cell - 1);
	buf[5] = (cell - 1) * 3 / 4;
	buf[6] = (cell - 1);
	buf[7] = (cell - 1);
	buf[8] = (cell - 1) * 3 / 4;
	buf[9] = (cell - 1);
	buf[10] = 0;
	buf[11] = (cell - 1) / 4;
}
void forwSlash(int *buf)
{
	buf[0] = (cell - 1);
	buf[1] = 0;
	buf[2] = (cell - 1) * 3 / 4;
	buf[3] = 0;
	buf[4] = 0;
	buf[5] = (cell - 1) * 3 / 4;
	buf[6] = 0;
	buf[7] = (cell - 1);
	buf[8] = (cell - 1) / 4;
	buf[9] = (cell - 1);
	buf[10] = (cell - 1);
	buf[11] = (cell - 1) / 4;
}

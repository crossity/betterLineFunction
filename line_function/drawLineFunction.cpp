#include <iostream>
#include <vector>

using namespace std;

void DrawLine(char screen[], int x1, int y1, int x2, int y2);

int Width = 80;
int Height = 24;

int main()
{
	char* screen = new char[Width * Height + 1];
	screen[Width * Height] = '\0';
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			DrawLine(screen, 0, 0, 6, 6);
			screen[i * Width + j] = ' ';
		}
	}
	printf(screen);
	getchar();
	return 0;
}

void DrawLine(char screen[], int x1, int y1, int x2, int y2)
{
	int deltaX = x1 - x2;
	int deltaY = y1 - y2;

	bool lineIsVertical = deltaX == 0 ? true : false;

	vector<float> points;

	float x = x1 < x2 ? x1 : x2;
	float y = y1 < y2 ? y1 : y2;

	if (!lineIsVertical)
	{
		float k = deltaY / deltaX;
		float b = y1 - k * x1;

		while ((int)x != (x1 < x2 ? x2 : x1) && (int)y != (y1 < y2 ? y2 : y1))
		{
			points.push_back((float)x);
			points.push_back((float)y);

			x += 0.1;

			y = (float)k * (float)x + (float)b;
		}
	}
	else 
	{
		while ((int)y < (y1 < y2 ? y2 : y1))
		{
			points.push_back((float)x);
			points.push_back((float)y);
			y++;
		}
	}
	for (int i = 0; i < points.size(); i += 2)
		{
			screen[(int)points[i] + (int)points[i + 1] * Width] = '@';
		}
		screen[(x1 < x2 ? x2 : x1) + (y1 < y2 ? y2 : y1) * Width] = '@';
}
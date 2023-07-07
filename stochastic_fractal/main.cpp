#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include<windows.h>
#include <time.h>
using namespace sf;
using namespace std;
void set_col(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int& width, Uint8*& pixels, int bias_color) {
	pixels[(x1 + y1 * width) * 4] = ((pixels[(x2 + y2 * width) * 4] + pixels[(x3 + y3 * width) * 4]
		+ pixels[(x4 + y4 * width) * 4]) / 3 + (rand() % bias_color)) % 256;
	pixels[(x1 + y1 * width) * 4 + 1] = ((pixels[(x2 + y2 * width) * 4 + 1] + pixels[(x3 + y3 * width) * 4 + 1]
		+ pixels[(x4 + y4 * width) * 4 + 1]) / 3 + rand() % bias_color) % 256;
	pixels[(x1 + y1 * width) * 4 + 2] = ((pixels[(x2 + y2 * width) * 4 + 2] + pixels[(x3 + y3 * width) * 4 + 2]
		+ pixels[(x4 + y4 * width) * 4 + 2]) / 3 + rand() % bias_color) % 256;
}
void set_col_m(int x1, int x2, int x3, int x4, int x5, int y1, int y2,
	int y3, int y4, int y5, int& width, Uint8*& pixels, int bias_color) {
	pixels[(x1 + y1 * width) * 4] = ((pixels[(x2 + y2 * width) * 4] + pixels[(x3 + y3 * width) * 4] +
		pixels[(x4 + y4 * width) * 4] + pixels[(x5 + y5 * width) * 4]) / 4 + rand() % bias_color) % 256;
	pixels[(x1 + y1 * width) * 4 + 1] = ((pixels[(x2 + y2 * width) * 4 + 1] + pixels[(x3 + y3 * width) * 4 + 1]
		+ pixels[(x4 + y4 * width) * 4 + 1] + pixels[(x5 + y5 * width) * 4 + 1]) / 4 + rand() % bias_color) % 256;
	pixels[(x1 + y1 * width) * 4 + 2] = ((pixels[(x2 + y2 * width) * 4 + 2] + pixels[(x3 + y3 * width) * 4 + 2]
		+ pixels[(x4 + y4 * width) * 4 + 2] + +pixels[(x5 + y5 * width) * 4 + 2]) / 4 + rand() % bias_color) % 256;
}
void set_col_sq(int x1, int x2, int y1, int y2, int& width, Uint8*& pixels, int bias_color) {
	set_col_m((x1 + (x1 + x2) / 2) / 2, x1, x1, (x1 + x2) / 2, (x1 + x2) / 2, ((y1 + y2) / 2 + y2) / 2,
		(y1 + y2) / 2, y2, (y1 + y2) / 2, y2, width, pixels, bias_color);
	set_col_m(((x1 + x2) / 2 + x2) / 2, (x1 + x2) / 2, (x1 + x2) / 2, x2, x2, ((y1 + y2) / 2 + y2) / 2,
		(y1 + y2) / 2, y2, (y1 + y2) / 2, y2, width, pixels, bias_color);
	set_col_m(((x1 + x2) / 2 + x2) / 2, (x1 + x2) / 2, (x1 + x2) / 2, x2, x2, (y1 + (y1 + y2) / 2) / 2,
		y1, (y1 + y2) / 2, y1, (y1 + y2) / 2, width, pixels, bias_color);
	set_col_m((x1 + (x1 + x2) / 2) / 2, x1, x1, (x1 + x2) / 2, (x1 + x2) / 2, (y1 + (y1 + y2) / 2) / 2,
		y1, (y1 + y2) / 2, y1, (y1 + y2) / 2, width, pixels, bias_color);
}
void set_col_mq(Uint8*& pixels, int x1, int x2, int y1, int y2, int& width, int bias_color) {
	set_col_m((x1 + (x1 + x2) / 2) / 2, x1, (x1 + (x1 + x2) / 2) / 2, (x1 + (x1 + x2) / 2) / 2, (x1 + x2) / 2,
		(y1 + y2) / 2, (y1 + y2) / 2, (y1 + (y1 + y2) / 2) / 2, ((y1 + y2) / 2 + y2) / 2, (y1 + y2) / 2, width, pixels, bias_color);
	set_col_m(((x1 + x2) / 2 + x2) / 2, (x1 + x2) / 2, ((x1 + x2) / 2 + x2) / 2, ((x1 + x2) / 2 + x2) / 2, x2,
		(y1 + y2) / 2, (y1 + y2) / 2, (y1 + (y1 + y2) / 2) / 2, ((y1 + y2) / 2 + y2) / 2, (y1 + y2) / 2, width, pixels, bias_color);
	set_col_m((x1 + x2) / 2, (x1 + (x1 + x2) / 2) / 2, (x1 + x2) / 2, (x1 + x2) / 2, ((x1 + x2) / 2 + x2) / 2,
		(y1 + (y1 + y2) / 2) / 2, (y1 + (y1 + y2) / 2) / 2, y1, (y1 + y2) / 2, (y1 + (y1 + y2) / 2) / 2, width, pixels, bias_color);
	set_col_m((x1 + x2) / 2, (x1 + (x1 + x2) / 2) / 2, (x1 + x2) / 2, (x1 + x2) / 2, ((x1 + x2) / 2 + x2) / 2,
		((y1 + y2) / 2 + y2) / 2, ((y1 + y2) / 2 + y2) / 2, (y1 + y2) / 2, y2, ((y1 + y2) / 2 + y2) / 2, width, pixels, bias_color);
}
bool fll = 1;
void rec(Uint8*& pixels, int x1, int x2, int y1, int y2, int& width, int bias_color) {
	if (bias_color <= 0) {
		bias_color = 1;
	}

	if (fll) {
		set_col_m((x1 + x2) / 2, x1, x1, x2, x2, (y1 + y2) / 2, y1, y2, y1, y2, width, pixels, bias_color);
		fll = 0;
	}
	if (pixels[(x1 + (y1 + y2) / 2 * width) * 4] + pixels[(x1 + (y1 + y2) / 2 * width) * 4 + 1]
		+ pixels[(x1 + (y1 + y2) / 2 * width) * 4 + 2] == 0) {
		set_col(x1, x1, x1, (x1 + x2) / 2, (y1 + y2) / 2, y1, y2, (y1 + y2) / 2, width, pixels, bias_color);
	}
	if (pixels[(x2 + (y1 + y2) / 2 * width) * 4] + pixels[(x2 + (y1 + y2) / 2 * width) * 4 + 1]
		+ pixels[(x2 + (y1 + y2) / 2 * width) * 4 + 2] == 0) {
		set_col(x2, x2, x2, (x1 + x2) / 2, (y1 + y2) / 2, y1, y2, (y1 + y2) / 2, width, pixels, bias_color);
	}
	if (pixels[((x1 + x2) / 2 + y1 * width) * 4] + pixels[((x1 + x2) / 2 + y1 * width) * 4 + 1]
		+ pixels[((x1 + x2) / 2 + y1 * width) * 4 + 2] == 0) {
		set_col((x1 + x2) / 2, x1, x2, (x1 + x2) / 2, y1, y1, y1, (y1 + y2) / 2, width, pixels, bias_color);
	}
	if (pixels[((x1 + x2) / 2 + y2 * width) * 4] + pixels[((x1 + x2) / 2 + y2 * width) * 4 + 1]
		+ pixels[((x1 + x2) / 2 + y2 * width) * 4 + 2] == 0) {
		set_col((x1 + x2) / 2, x1, x2, (x1 + x2) / 2, y2, y2, y2, (y1 + y2) / 2, width, pixels, bias_color);
	}

	set_col_sq(x1, x2, y1, y2, width, pixels, bias_color);
	set_col_mq(pixels, x1, x2, y1, y2, width, bias_color);
	if (x2 - x1 > 1 || y2 - y1 > 1) {
		rec(pixels, (x1 + x2) / 2, x2, (y1 + y2) / 2, y2, width, bias_color / 2.1);
		rec(pixels, x1, (x1 + x2) / 2, y1, (y1 + y2) / 2, width, bias_color / 2.1);
		rec(pixels, (x1 + x2) / 2, x2, y1, (y1 + y2) / 2, width, bias_color / 2.1);
		rec(pixels, x1, (x1 + x2) / 2, (y1 + y2) / 2, y2, width, bias_color / 2.1);
	}
}
int main()
{
	srand(time(0));
	int width = 1800, height = 1000, bias_color = 50;
	sf::RenderWindow wnd(sf::VideoMode(1000, 1000), "SFML", Style::Fullscreen);
	sf::Uint8* pixels = new sf::Uint8[width * height * 4];
	for (int xx = 0; xx < height; xx++) {
		for (int yy = 0; yy < width; yy++) {
			pixels[(xx * width + yy) * 4] = 0;
			pixels[(xx * width + yy) * 4 + 1] = 0;
			pixels[(xx * width + yy) * 4 + 2] = 0;
		}
	}
	bool contin = 1;
	bool fl_paint = 1;
	while (wnd.isOpen())
	{
		if (fl_paint) {
			wnd.clear();
			pixels[0] = rand() % 256;
			pixels[1] = rand() % 256;
			pixels[2] = rand() % 256;
			pixels[(height - 1) * width * 4] = rand() % 256;
			pixels[(height - 1) * width * 4 + 1] = rand() % 256;
			pixels[(height - 1) * width * 4 + 2] = rand() % 256;
			pixels[(width - 1) * 4] = rand() % 256;
			pixels[(width - 1) * 4 + 1] = rand() % 256;
			pixels[(width - 1) * 4 + 2] = rand() % 256;
			pixels[((width - 1) + (height - 1) * width) * 4] = rand() % 256;
			pixels[((width - 1) + (height - 1) * width) * 4 + 1] = rand() % 256;
			pixels[((width - 1) + (height - 1) * width) * 4 + 2] = rand() % 256;
			rec(pixels, 0, (width - 1), 0, (height - 1), width, bias_color);
			sf::Texture tx;
			tx.create(width, height);
			tx.update((sf::Uint8*)pixels, width, height, 0, 0);
			sf::Sprite sprite(tx);
			sprite.setPosition(50, 50);
			wnd.draw(sprite);
			sf::ConvexShape convex;
			convex.setPointCount(4);
			convex.setPoint(0, sf::Vector2f(1850, 0));
			convex.setPoint(1, sf::Vector2f(1850, 50));
			convex.setPoint(2, sf::Vector2f(1900, 50));
			convex.setPoint(3, sf::Vector2f(1900, 0));
			wnd.draw(convex);
			wnd.display();
			fl_paint = 0;
		}
		sf::Event event;
		while (wnd.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				wnd.close();
				break;
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					int x_mouse = event.mouseButton.x;
					int y_mouse = event.mouseButton.y;
					if (x_mouse < 1900 && x_mouse > 1850 && y_mouse > 0 && y_mouse < 50) {
						contin = 0;
					}
				}
			}
		}
		if (!contin) {
			break;
		}
	}
	return 0;
}
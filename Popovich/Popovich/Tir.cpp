#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

struct point {
	int x, y;
	point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	point()
	{
		point(0, 0);
	}
};

class Shoot {
	int startX;
	int startY;
	int a, b, c;
public:
	Shoot(point p1, point p2)
	{
		this->a = p2.y - p1.y;
		this->b = p1.x - p2.x;
		this->c = -a * p1.x - b * p1.y;
		startX = p1.x;
		startY = p1.y;
	}

	int point_in_line(point p)
	{
		int s = a * p.x + b * p.y + c;
		return s < 0 ? -1 : s > 0 ? 1 : 0;
	}

	bool is_parallel_line(Shoot l2)
	{
		return abs(a * l2.b - l2.a * b) <= 0;
	}
	// совпадают ли прямые?
	bool is_equal_line(Shoot l2)
	{
		return abs(a * l2.b - l2.a * b) <= 0 &&
			abs(a * l2.c - l2.a * c) <= 0 &&
			abs(b * l2.c - l2.b * c) <= 0;
	}

	int cross_line(Shoot l2, point& p)
	{
		if (is_equal_line(l2)) return 2;
		if (is_parallel_line(l2)) return 0;

		p.x = (l2.b * c - b * l2.c) / (l2.a * b - a * l2.b);
		p.y = (b != 0 ? (-c - a * p.x) / b : (-l2.c - l2.a * p.x) / l2.b);
		return 1;
	}

	bool point_in_box(point t, point p1, point p2)
	{
		return  (abs(t.x - min(p1.x, p2.x)) <= 0 || min(p1.x, p2.x) <= t.x) &&
			(abs(max(p1.x, p2.x) - t.x) <= 0 || max(p1.x, p2.x) >= t.x) &&
			(abs(t.y - min(p1.y, p2.y)) <= 0 || min(p1.y, p2.y) <= t.y) &&
			(abs(max(p1.y, p2.y) - t.y) <= 0 || max(p1.y, p2.y) >= t.y);
	}

	int cross_segment_line(point p1, point p2, point& p)
	{
		Shoot t(p1, p2);
		int flag = cross_line(t, p);
		if (flag == 0) return 0;
		if (flag == 2) return 2;

		if (point_in_box(p, p1, p2)) return 1;
		return 0;
	}

};


class Target {
	vector<point> p;
public:
	Target(vector<point> p) {
		this->p = p;
	}
	int polygon_for_line(Shoot l)
	{
		int i, j;
		int s = -2; // знак
		for (i = 0; i < p.size(); ++i)
		{
			int t = l.point_in_line(p[i]); // положение вершины относительно прямой
			if (t != 0)        // если точка не принадлежить прямой
				if (s != -2)     // если s мы вычислили
					if (t != s)        // если знаки различны, то прямая пересекает сторону многоугольника
						return 0;
					else
					{
					}
				else
					s = t; // если s мы ещё не вычислили, присваиваем ему вычисленное значение
		}
		if (s == -2) return 0;
		return s;
	}
};



int main() {
	int d, r;
	
	return 0;
}
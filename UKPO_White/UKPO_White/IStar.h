//#include <iostream>
#include <queue>
#include <string>
#include <math.h>
#include <time.h>
//#include <stdio.h>  



const int n = 20; // размер карты
const int m = 20; // размер карты
static int map[n][m];
static int closed_nodes_map[n][m]; // массив уже пройденных вершин
static int open_nodes_map[n][m]; // массив ещЄ не рассмотренныхт вершин
static int dir_map[n][m]; // массив направлений
const int dir = 8; // число возможных направлений 4-только по пр€мой, 8-по диагонал€м
static int dx[dir] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int dy[dir] = { 0, 1, 1, 1, 0, -1, -1, -1 };


class node
{
	// исходна€ позици€
	int xPos;
	int yPos;
	// уже пройденна€ дистанци€
	int level;

	int priority;  // приоритет

public:
	node(int xp, int yp, int d, int p)
	{
		xPos = xp; yPos = yp; level = d; priority = p;
	}

	int getxPos() const { return xPos; }
	int getyPos() const { return yPos; }
	int getLevel() const { return level; }
	int getPriority() const { return priority; }

	void updatePriority(const int & xDest, const int & yDest)
	{
		priority = level + estimate(xDest, yDest) * 10; //A*
	}

	//приоритет отдаетс€ движению по пр€мой, чем по диагонали
	void nextLevel(const int & i) // i: конечна€
	{
		level += (dir == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
	}

	// Ёвристическа€ оценка
	const int & estimate(const int & xDest, const int & yDest) const
	{
		static int xd, yd, d;
		xd = xDest - xPos;
		yd = yDest - yPos;

		// по Ёвклиду
		d = static_cast<int>(sqrt(xd*xd + yd*yd));

		// по „ебышеву
		//d=max(abs(xd), abs(yd));

		return(d);
	}
};


bool operator<(const node & a, const node & b)
{
	return a.getPriority() > b.getPriority();
}

// јлгоритм
std::string pathFind(const int & xStart, const int & yStart,
	const int & xFinish, const int & yFinish)
{
	static std::priority_queue<node> pq[2]; // список не посещенных вершин
	static int pqi; // штвулс вспомогательный
	static node* n0;
	static node* m0;
	static int i, j, x, y, xdx, ydy;
	static char c;
	pqi = 0;

	// обнуление
	for (y = 0; y<m; y++)
	{
		for (x = 0; x<n; x++)
		{
			closed_nodes_map[x][y] = 0;
			open_nodes_map[x][y] = 0;
		}
	}

	// создать первую точку и сунуть в стек непосещенных вершин
	n0 = new node(xStart, yStart, 0, 0);
	n0->updatePriority(xFinish, yFinish);
	pq[pqi].push(*n0);
	open_nodes_map[x][y] = n0->getPriority(); // пометить еЄ в карте

	// A* 
	while (!pq[pqi].empty())
	{
		// пометить текущую вершину новым приоритетом
		n0 = new node(pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
			pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

		x = n0->getxPos(); y = n0->getyPos();

		pq[pqi].pop(); // удалим
		open_nodes_map[x][y] = 0;
		//пометим в карте посещенныз вершин
		closed_nodes_map[x][y] = 1;

		// проверим, не достигли ли конца
		if (x == xFinish && y == yFinish)
		{
			// создадим дорогу от начала к концу
			std::string path = "";
			while (!(x == xStart && y == yStart))
			{
				j = dir_map[x][y];
				c = '0' + (j + dir / 2) % dir;
				path = c + path;
				x += dx[j];
				y += dy[j];
			}

			// уберем мусор
			delete n0;
			// очистим стек
			while (!pq[pqi].empty()) pq[pqi].pop();
			return path;
		}

		//пересчитаем показатели дл€ дочерних вершин
		for (i = 0; i<dir; i++)
		{
			xdx = x + dx[i]; ydy = y + dy[i];

			if (!(xdx<0 || xdx>n - 1 || ydy<0 || ydy>m - 1 || map[xdx][ydy] == 1
				|| closed_nodes_map[xdx][ydy] == 1))
			{
				// дочерн€€ вершина
				m0 = new node(xdx, ydy, n0->getLevel(),
					n0->getPriority());
				m0->nextLevel(i);
				m0->updatePriority(xFinish, yFinish);

				// если вершина ещЄ не посещена, добавим в стек и карту
				if (open_nodes_map[xdx][ydy] == 0)
				{
					open_nodes_map[xdx][ydy] = m0->getPriority();
					pq[pqi].push(*m0);
					// пересчитаем показатели дл€ родител€
					dir_map[xdx][ydy] = (i + dir / 2) % dir;
				}
				else if (open_nodes_map[xdx][ydy]>m0->getPriority())
				{
					// приоритет
					open_nodes_map[xdx][ydy] = m0->getPriority();
					//родительский приоритет
					dir_map[xdx][ydy] = (i + dir / 2) % dir;

					//≈сли вершина в стеке уже провер€лась и был высчитан маршрут, заменим еЄ
					while (!(pq[pqi].top().getxPos() == xdx &&
						pq[pqi].top().getyPos() == ydy))
					{
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pq[pqi].pop();

					// изменение веса пути на наименьший
					if (pq[pqi].size()>pq[1 - pqi].size()) pqi = 1 - pqi;
					while (!pq[pqi].empty())
					{
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pqi = 1 - pqi;
					pq[pqi].push(*m0); // ¬ыбор лучшей вершины
				}
				else delete m0; 
			}
		}
		delete n0; 
	}
	return ""; // Ќет найденного рути
}


std::string start(int xA,int  yA, int xB,int yB, bool test)
{
	if (!(xA < 0 || yA < 0 || xB < 0 || yB < 0))
	{
		/*std::cout << "Map Size (X,Y): " << n << "," << m << std::endl;
		std::cout << "Start: " << xA << "," << yA << std::endl;
		std::cout << "Finish: " << xB << "," << yB << std::endl;*/
		// ѕолучение пути
		clock_t start = clock();
		std::string route = pathFind(xA, yA, xB, yB);
		if (route == "")
		{
			route = "найденный путь пуст!";
			//std::cout << "An empty route generated!" << std::endl;*/

		}
		clock_t end = clock();
		double time_elapsed = double(end - start);
		/*cout << "Time to calculate the route (ms): " << time_elapsed << endl;
		cout << "Route:" << endl;
		cout << route << endl << endl;*/
		if (!test)
		{
			// ѕроследуем по пути 
			if (route.length() > 0)
			{
				int j; char c;
				int x = xA;
				int y = yA;
				map[x][y] = 2;
				for (int i = 0; i < route.length(); i++)
				{
					c = route.at(i);
					j = atoi(&c);
					x = x + dx[j];
					y = y + dy[j];
					map[x][y] = 3;
				}
				map[x][y] = 4;

				// ¬ыведем путь на карте
				for (int y = 0; y < m; y++)
				{
					//for (int x = 0; x < n; x++)
					//	if (map[x][y] == 0)
					//		cout << ".";
					//	else if (map[x][y] == 2)
					//		cout << "S"; //Ќачало
					//	else if (map[x][y] == 3)
					//		cout << "R"; //ѕуть
					//	else if (map[x][y] == 4)
					//		cout << "F"; // онец
					//cout << endl;
				}
			}
		}
		return route;
	}
	else
	{
		std::string route = "невозможно найти путь, проверьте входные данные!";
		return route;
	}
}

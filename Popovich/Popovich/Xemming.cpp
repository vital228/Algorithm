#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> createMatrix(int row, int col);
vector<vector<int>> readMatrix(string name, int row, int col);
int character(vector<vector<int>> matrix, int col, int row, int c, int d, int a, int b)
{
	bool f = false;
	bool g = false;
	int put;
	if (row != col)
	{//" Матрица должна быть размером n*n";
		f = false;
		return f;
	}
	else if (row == col)
	{
		if ((matrix[d][c] != 0) && (matrix[b][a] == 0)) {
			g = true;
		}
		if (g == false) {
			return g;
		}
		else if (g == true) {
			return g;
		}

	}
}
void printMatrixInConsole(vector<vector<int>> matrix, int col)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}
void printMatrixInFile(string name, vector<vector<int>> matrix, int col)
{
	ofstream fout(name);
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			fout << matrix[i][j] << " ";
		}
		fout << "\n";
	}
	fout.close();
}

vector<pair<int,int>> findPut(vector<vector<int>> matrix, int n, int a, int b, int c, int d) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	matrix[a][b] = -1;
	while (!q.empty()) {
		pair<int, int> s = q.front();
		q.pop();
		if (s.first > 0 && matrix[s.first - 1][s.second] == 0) {
			q.push({ s.first - 1,s.second });
			matrix[s.first - 1][s.second] = matrix[s.first][s.second] - 1;
		}
		if (s.second > 0 && matrix[s.first][s.second - 1] == 0) {
			q.push({ s.first,s.second - 1 });
			matrix[s.first][s.second - 1] = matrix[s.first][s.second] - 1;
		}
		if (s.first < n - 1 && matrix[s.first + 1][s.second] == 0) {
			q.push({ s.first + 1,s.second });
			matrix[s.first + 1][s.second] = matrix[s.first][s.second] - 1;
		}
		if (s.second < n - 1 && matrix[s.first][s.second + 1] == 0) {
			q.push({ s.first,s.second + 1 });
			matrix[s.first][s.second + 1] = matrix[s.first][s.second] - 1;
		}
	}
	vector<pair<int, int>> ans;
	if (matrix[c][d] == 0) {
		return ans;
	}
	else {
		pair<int, int> s = { c,d };	
		while (matrix[s.first][s.second] != -1) {
			ans.push_back(s);
			if (s.first > 0 && matrix[s.first - 1][s.second] == matrix[s.first][s.second] + 1) {
				s = { s.first - 1,s.second };
				continue;
			}
			if (s.second > 0 && matrix[s.first][s.second - 1] == matrix[s.first][s.second] + 1) {
				s={ s.first,s.second - 1 };
				continue;
			}
			if (s.first < n - 1 && matrix[s.first + 1][s.second] == matrix[s.first][s.second] + 1) {
				s={ s.first + 1,s.second };
				continue;
			}
			if (s.second < n - 1 && matrix[s.first][s.second + 1] == matrix[s.first][s.second] + 1) {
				s={ s.first,s.second + 1 };
				continue;
			}
		}
		return ans;
	}
}
int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Ввод матрицы с клавиатуры: 1\n";
	cout << "Ввод матрицы с файла: 2\n";
	cout << "Характеристика: 3\n";
	cout << "Преобразование матрицы: 4\n";
	cout << "Печать матрицы в консоль: 5\n";
	cout << "Печать матрицы в файл: 6\n";
	cout << "Выход: 7\n";
	int enter;
	int put;
	int c, d;//координаты шарика
	int a, b;//координаты пустого места
	int row = 0, col = 0;
	vector<vector<int>> v;
	vector<vector<int>> nova;
	cout << "Введите номер: ";
	cin >> enter;
	bool fl = true;
	while (fl)
	{
		switch (enter)
		{
		case (1):
		{
			cout << "Размерность матрицы ";
			cin >> row >> col;
			if (row != col) {
				cout << "Матрица должна быть квадратной";
				return 0;
			}
			cout << "Иницилизируйте матрицу:\n";
			v = createMatrix(row, col);
			cin >> c >> d;
			c--; d--;
			cin >> a >> b;
			a--; b--;
			vector<pair<int, int>> puts = findPut(v, row, c, d, a, b);
			put = puts.size();
			break;
		}
		case (2):
		{
			cout << "Введите имя файла: ";
			string name;
			cin >> name;
			ifstream fin(name);
			fin >> row >> col;
			v = readMatrix(name, row, col);
			fin.close();
			break;
		}
		case (3):
		{
			if (row == 0 || col == 0)
			{
				cout << "Нужно инициализировать матрицу.\n";
				break;
			}
			if (character(v, col, row, c, d, a, b) == false)
			{
				cout << "В данной клетке не пустое место нельзя перемесить шарик.\n";
			}
			else
			{
				cout << "Минимальный путь : ";
				cout << put << endl;
			}
			break;
		}
		/*case (4):
		{
			if (row == 0 || col == 0)
			{
				cout << "Нужно инициализировать матрицу.\n";
				break;
			}
			//nova = transformation(v, col);
			cout << "Матрица A преобразлвалась в В\n";
			break;
		}*/
		case (5):
		{
			if (row == 0 || col == 0)
			{
				cout << "Нужно инициализировать матрицу.\n";
				break;
			}

			printMatrixInConsole(v, col);

			break;
		}
		case (6):
		{
			if (row == 0 || col == 0)
			{
				cout << "Нужно инициализировать матрицу.\n";
				break;
			}
			cout << "Введите имя файла для вывода матрицы";
			string name;
			cin >> name;
			printMatrixInFile(name, v, col);

			break;
		}
		case (7):
		{
			fl = false;
			cout << "Выход";
			return 0;
		}
		default:
		{
			cout << "Неверный номер.\n";
			break;
		}
		}
		cout << "Введите номер из меню: ";
		cin >> enter;
	}
}
vector<vector<int>> createMatrix(int row, int col)
{
	vector<vector<int>> matrix(row, vector<int>(col));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	return matrix;
}
vector<vector<int>> readMatrix(string name, int row, int col)
{
	ifstream fin(name);
	vector<vector<int>> matrix(row, vector<int>(col));
	fin >> row >> col;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			fin >> matrix[i][j];
		}
	}
	return matrix;
	fin.close();
}
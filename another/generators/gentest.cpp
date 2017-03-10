#include <random>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>


const char* out_name_file = {"input.txt"}; //--название выходного файла
//--варианты операций, дублирование для повышения частоты выпадения вставок:
std::vector<std::string> v = {"delete", "exists", "next", "prev", "insert", "insert"}; 

using namespace std;

int main(int argc, char const *argv[])
{
	const size_t n = 4; //--диапазон выпадаемых индексов, в нашем случае не больше 6
	const size_t m = 100; //--количество операций
	const int s = 20; //--размах принимаемых значений для элементов (дерева, в нашем случае)

	mt19937 gen; //---ГПСЧ - вихрь Мерсенна
	gen.seed(time(0)); //---зерно генератора задаем временем (для пущей случайности результатов)

	ofstream fout;
	fout.open(out_name_file);
	
	for (size_t i = 0; i < m; ++i)
	{
		fout << v[gen() % n] << " " << static_cast<int>(gen() % s) - (s / 2) << "\n";
	}
}
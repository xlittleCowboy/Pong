#include <random>

using namespace std;

class Random
{
public:
	template<typename T>
	T getRandomNumber(T a, T b)
	{
		random_device rd;
		mt19937 mt(rd());
		uniform_real_distribution<T> distribution(a, b);
		return distribution(mt);
	}
};
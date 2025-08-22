#include "Calculator.hpp"

template <class T>
T Calculator<T>::add(T a, T b) const {
	return a + b;
}

template <class T>
T Calculator<T>::sub(T a, T b) const {
	return a - b;
}

template <class T>
T Calculator<T>::mul(T a, T b) const {
	return a * b;
}

template <class T>
T Calculator<T>::div(T a, T b) const {
	return a / b;
}

/*	"solution 1"	*/
/*void temporary() {
	Calculator<int> cInt;
	Calculator<double> cDouble;
}*/
#ifndef COLOR_BOTTLE_HPP
#define COLOR_BOTTLE_HPP
#include <iostream>

namespace Color {
	class Bottle {
		public:
			Bottle() {}
			virtual ~Bottle() {}

			void drinkFromBottle();
			void fillBottle();
			/* ... */
	};

	/*
	* By defining functions in your namespace it may happen,
	* that these might be "redefined" elsewhere.
	*
	* To solve that issue, make sure to define such
	* functions with the inline keyword.
	*
	* By the way, when you define your function as a function
	* prototype instead, => inline void doSomething(); <= the compiler will also complain:
	* "main.cpp: undefined reference to 'Color::doDomething()'"
	*
	* This works only for functions without >>inline<< keyword.
	*/
	inline void doSomething() {
		std::cout << "working..." << std::endl;
	}

	/* that works instead */
	void bruh();

	/* readonly expressions */
	const int a = 100;
}
#endif
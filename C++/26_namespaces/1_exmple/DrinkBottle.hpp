#ifndef DRINK_BOTTLE_HPP
#define DRINK_BOTTLE_HPP

namespace Drink {
	class Bottle {
		public:
			Bottle() {}
			virtual ~Bottle() {}

			void drinkFromBottle();
			void fillBottle();
			/* ... */
	};
}
#endif
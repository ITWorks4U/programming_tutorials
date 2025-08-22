/*
* Singleton classes can be useful to declare only
* a single instance of a class.
*
* But not every time a singleton class is useful.
* In combination with threads, clusters, inheritance there's
* no guarantee to work well with it.
*/

#ifdef _WIN32
#warning "On Windows if you're using an old (mingw) compiler, this code below can't possibly be build. Use MinGW-w64 instead."
#endif

#include <iostream>
#include <thread>
using namespace std;

class Singleton {
	/*	private area by default	*/
	string tmp;
	Singleton() {}

	public:
		static Singleton *getInstance() {
			static Singleton itself;
			return &itself;
		}

		virtual ~Singleton() {}

		void meme() {
			cout << "This function goes brrrrrrrr." << endl;
		}

		void updateTmp(string tmp) {
			this->tmp = tmp;
		}

		string getTmp() const {
			return this->tmp;
		}
};

int main() {
	/*
	* Singleton classes can also be used in threads, however,
	* there's a high risk to do this, because in threads
	* the singleton schema might not work well.
	*/
	cout << "main thread: " << this_thread::get_id() << endl;
	auto t1 = thread([]{
		Singleton *s = Singleton::getInstance();
		s->updateTmp("Updated by thread 1...");
		cout << "location: " << s << " | content: " << s->getTmp() << endl;
	});

	auto t2 = thread([]{
		Singleton *s = Singleton::getInstance();
		s->updateTmp("Updated by thread 2...");
		cout << "location: " << s << " | content: " << s->getTmp() << endl;
	});

	t1.join();
	t2.join();

	return 0;
}
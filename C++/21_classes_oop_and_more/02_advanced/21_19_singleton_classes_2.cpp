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
#include <queue>
#include <string>

using namespace std;
using namespace chrono;

/// @brief Job class with a certain ID and a message, which shall be handled with a queue.
class Job {
	int queueId;
	string queueMessage;

	public:
		Job(int id, string message) {
			this->queueId = id;
			this->queueMessage = message;
		}

		void printQueueJob() {
			cout << "ID: " << this->queueId << ", message: " << this->queueMessage << endl;
		}
};

/// @brief Since a queue is thread safe, it's no guarantee, that a singleton class an be covered by a queue.
class QueueJob {
	QueueJob() {}
	queue<Job> __jobs;

	public:
		static QueueJob *getInstance() {
			static QueueJob itself;
			return &itself;
		}

		virtual ~QueueJob() {}

		bool onEmptyQueue() const {
			return __jobs.empty();
		}

		void enqueue(Job &&q) {
			__jobs.push(move(q));
		}

		Job dequeue() {
			auto gottenJob = __jobs.front();
			__jobs.pop();

			return gottenJob;
		}
};

int main() {
	/*
	* Singleton classes can also be used in threads, however,
	* there's a high risk to do this, because in threads
	* the singleton schema might not work well.
	*
	* On runtime you might get a segmentation fault,
	* queue ID's with 0 or it also might work "well".
	*/
	// cout << "main thread: " << this_thread::get_id() << endl;

	auto t1 = thread([]{
		QueueJob *qj = QueueJob::getInstance();
		for(int i = 0; i < 100; i++) {
			qj->enqueue(Job(i, "comes from thread 1"));
		}

		for(int i = 0; i < 100; i++) {
			if (qj->onEmptyQueue()) {
				cout << "thread 1: the queue has no more content" << endl;
				break;
			}

			auto gottenJob = qj->dequeue();
			gottenJob.printQueueJob();
		}
	});

	auto t2 = thread([]{
		QueueJob *qj = QueueJob::getInstance();
		for(int i = 100; i < 200; i++) {
			qj->enqueue(Job(i, "comes from thread 2"));
		}

		/*	attention:	We're starting from 0, NOT from 100!	*/
		for(int i = 0; i < 200; i++) {
			if (qj->onEmptyQueue()) {
				cout << "thread 2: the queue has no more content" << endl;
				break;
			}

			auto gottenJob = qj->dequeue();
			gottenJob.printQueueJob();
		}
	});

	t1.join();
	t2.join();

	return 0;
}
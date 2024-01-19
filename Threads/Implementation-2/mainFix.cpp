#include <iostream>
#include <thread>
#include <mutex>

// I want it static for it to be shared by both threads
static int sum = 0;
// may work if we declare it inside task, but we may not want 2 mil declarations.
std::mutex mutex;

void task () {
	
	mutex.lock();

        for (int i = 0; i < 1000000; i++) {
		sum += 1;
	}
	mutex.unlock();
}

int main () {
        // creates thread and runs it without blocking execution
        std::thread t1(task), t2(task);
	
	
        // we wait for t1, t2 to finish execution, blocking execution
        t1.join();
	t2.join();
	
	// we expect the output to be 2 mil
	std::cout << sum << std::endl;
} 

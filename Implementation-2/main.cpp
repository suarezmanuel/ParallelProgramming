#include <iostream>
#include <thread>

// I want it static for it to be shared by both threads
static int sum = 0;


void task () {
        for (int i = 0; i <= 1000000; i++) {
		sum += 1;
	}
}

int main () {
        // creates thread and runs it without blocking execution
        std::thread t1(task), t2(task);
	
	
        // we wait for t1, t2 to finish execution, blocking execution
        t1.join();
	t2.join();

	std::cout << sum << std::endl;
} 

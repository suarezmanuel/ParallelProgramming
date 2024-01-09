#include <iostream>
#include <thread>

int sum = 0;


void task (int num) {
        std::cout << num << std::endl;
}

int main () {
        // creates thread and runs it without blocking execution
        std::thread t1(task, 10);

        for (int i = 20; i <= 100; i++) {
                std::cout << i << std::endl;
        }

        // we wait for t to finish execution, blocking execution

        t1.join();
}
       

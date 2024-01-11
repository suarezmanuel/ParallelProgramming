#include <isotream>
#include <thread>
#include <mutex>
#include <semaphore>
#include <chrono>

#define EATTIME 0.01
#define STARVATIONTIME EATTIME*100

enum STATE {
	THINK, WAIT, EAT
};

void think () {
	if (!forks_available()) {
		
	}
}

void take_forks () {
	while (!has_both_forks()) {

	}
}

void eat () {
	// sleep for random amount of time
}

void put_forks () {

}

/*
	spaghetti has to be eaten with two forks
	
	think unless the left fork is available; when it is, pick it up;
	think unless the right fork is available; when it is, pick it up;
	when both forks are held, eat for a fixed amount of time;
	put the left fork down;
	put the right fork down;
	repeat from the beginning.
*/
void philosopher () {
	while (true) {
		think();
		take_forks();
		eat();
		put_forks();
	}	
}

bool check_starvation () {
	
}

int main () {
	std::thread p1 (philosopher);	
	std::thread p2 (philosopher);	
	std::thread p3 (philosopher);	
	std::thread p4 (philosopher);

	while (true) {
		if (check_starvation ()) {
			std::cout << "philosopher has starved" << std::endl;
			exit(1);
		}
	}
}	

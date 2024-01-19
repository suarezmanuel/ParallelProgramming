for compilation: g++ main.cpp -std=c++0x -pthread  -o main.

Intresting to see that 10 appears in the middle of the printing of 20 up to 100.
Even more so, we can see that the std::endl doesn't take effect (as they are printing at the same time at the same line)
such that we see two numbers stuck together

````
manuel@Manuels-Laptop Threadin1 % ./main
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
1040

41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
manuel@Manuels-Laptop Threadin1 % 
````
<br><br>

**Implementation-2** <br><br>

Example of threads colliding and overwriting each other's changes. <br>
We expect a sum of 2 mil.


````
// I want it static for it to be shared by both threads 
static int sum = 0; 
        
void task () {
        for (int i = 0; i < 1000000; i++) { 
                sum += 1; 
        }
}
````
<br><br>

````
manuel@Manuels-Laptop Implementation-2 % ./main
1022754
````
<br>

It's intresting to see that the output is almost half of the expected value, may mean that the threads 
run almost at the same time / the same amout of times.

<br><br>

**Implementation-2 Fix** <br><br>

We can fix the previous code by adding a mutex, preventing collisions.

````
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
````

<br><br>

````
manuel@Manuels-Laptop Implementation-2 % ./mainFix                                      
2000000
````
<br>
We Won!

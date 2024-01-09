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

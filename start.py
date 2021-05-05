import matplotlib.pyplot as plt
from os import system
import sys
exec(open('read_csv.py').read())
system('testprogram.exe')
sys.stdin = open("timings.out", "r")
x = list(map(int, input().split()))
y = []
for i in range(len(x)):
    y.append(list(map(float, input().split())))
n = len(y[0])
result = [[y[j][i] for j in range(len(y))] for i in range(len(y[0]))]
for i in range(n):
    plt.plot(x, result[i])
plt.xlabel("input size")
plt.ylabel("execution time")
plt.title("Comparison of different sorting algorithms")
plt.legend(["Selection Sort", "Insertion Sort", "Heap Sort", "Quick Sort"])
plt.savefig('plot.png', bbox_inches='tight')
plt.show()

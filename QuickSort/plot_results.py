import pandas as pd
import matplotlib.pyplot as plt

# Загрузка данных из CSV
data = pd.read_csv("results.csv")

# Построение графиков
plt.figure(figsize=(10, 6))

plt.plot(data['size'], data['random_insertion_sort_times'], label="Random Insertion Sort", marker='o')
plt.plot(data['size'], data['random_quick_sort_times'], label="Random Quick Sort", marker='o')
plt.plot(data['size'], data['reverse_insertion_sort_times'], label="Reverse Insertion Sort", marker='o')
plt.plot(data['size'], data['reverse_quick_sort_times'], label="Reverse Quick Sort", marker='o')

plt.xlabel("Array Size")
plt.ylabel("Execution Time (seconds)")
plt.title("Performance Benchmark")
plt.legend()
plt.grid(True)

# Сохраняем график как изображение
plt.savefig("benchmark_results.png")
plt.show()

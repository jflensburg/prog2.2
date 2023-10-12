#!/usr/bin/env python3

from person import Person
from numba import njit
from time import perf_counter as pc
import matplotlib.pyplot as plt

def main():
	# f = Person(5)
	# print(f.get())
	# f.set(7)
	# print(f.get())
        
	# print(f.fib())
	print(fib_time(n_lst))

def fib_py(n):
        if n <= 1:
                return n
        else:
                return(fib_py(n-1) + fib_py(n-2))
@njit       
def fib_py_numba(n):
        if n <= 1:
                return n
        else:
                return(fib_py_numba(n-1) + fib_py_numba(n-2))
        

# --- mina funktioner för olika n ---

n_lst = [x for x in range(30, 46)]

def fib_time(lst):

	py_lst = []
	nu_lst = []
	cpp_lst = []
    
	for i in lst:

		start1 = pc()
		fib_py(i)
		end1 = pc()
		py_lst += [round(end1-start1, 3)]
		start2 = pc()
		fib_py_numba(i)
		end2 = pc()
		nu_lst += [round(end2-start2, 3)]
		start3 = pc()
		f = Person(i)
		f.fib()
		end3 = pc()
		cpp_lst += [round(end3-start3, 3)]
		print(i) # vill se vilket tal i listan jag är på

	print(' ')            
	print('Python: ', py_lst)
	print(' ')
	print('Python & Numba: ', nu_lst)
	print(' ')
	print('C++: ', cpp_lst)
	print(' ')

	plt.figure(figsize=(8, 6))

	plt.plot(lst, py_lst, marker='o', label='Python')
	plt.plot(lst, nu_lst, marker='o', label='Python and Numba')
	plt.plot(lst, cpp_lst, marker='o', label='C++')

	plt.xlabel('Input (Age)')
	plt.ylabel('Time [s]')
	plt.legend()

	plt.title("Time to get Fibonacci's number")
	plt.grid(True)
	plt.savefig('fig_fib_time.png', format='png', bbox_inches='tight')
	plt.show()

# ------

if __name__ == '__main__':
	main()

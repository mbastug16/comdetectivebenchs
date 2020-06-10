arg=prodcons_2p6c
gcc: $(arg).c
	gcc -o $(arg).out $(arg).c -fopenmp -lm
clean:
	rm -rf 1*;rm -f core;rm -f *.out
run:
	make gcc
	ComDetectiverun --enable-object-level ./$(arg).out

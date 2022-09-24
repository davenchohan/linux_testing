all: my_version.c my_current_processes.c my_memory_util.c
	gcc -o my_version my_version.c
	gcc -o my_current_processes my_current_processes.c
	gcc -o my_memory_util my_memory_util.c

clean:
	$(RM) my_version my_current_processes my_memory_util
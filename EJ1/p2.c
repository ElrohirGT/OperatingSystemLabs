// Flavio Galán 22386

#include <stdio.h>
#include <unistd.h>

int main() {
	int f = fork();

	// No uso NULL pues clang me tira errores ya que espera un valor y no NULL
	// Por lo tanto simplemente le paso una cadena vacía!
	if (f == 0) {
		execl("p1.out", "");
	} else {
		printf("%d\n", (int)getpid());
		execl("p1.out", "");
	}

	return 0;
}

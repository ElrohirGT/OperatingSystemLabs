// Flavio Galán 22386

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // Used for open

int main(int argc, char* argv[]) {
	// printf("Arg count: %d\n", argc);

	if (argc != 3) {
		printf("Please supply a source file and a destination file!\n");
		return 1;
	}

	int srcFile = open(argv[1], O_RDONLY);
	if (srcFile == -1) {
		printf("Can't open src file!\n");
		return 1;
	}

	int destFile = open(argv[2], O_WRONLY);
	if (destFile == -1) {
		printf("Can't open destination file!\n");
		return 1;
	}

	int bufferSize = 255;
	int buffer[bufferSize];
	ssize_t readResult = read(srcFile, &buffer, bufferSize);

	while (readResult > 0) {
		ssize_t writeResult = write(destFile, &buffer, readResult);

		if (writeResult == -1) {
			printf("An error occurred while writing to destination file!\n");
			break;
		} else {
			readResult = read(srcFile, &buffer, bufferSize);
		}
	}

	if (readResult == -1) {
		printf("An error occurred while reading file bytes!\n");
	}

	close(srcFile);
	close(destFile);

	return 0;
}

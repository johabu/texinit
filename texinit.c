#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *datei;
	printf("Open file %s ...",argv[1]);
	datei = fopen(argv[1], "w+");
	if (datei == NULL) {
		printf("\nError in opening\n");
		return EXIT_FAILURE;
	}
	printf(" OK\n");
	fclose(datei);
	return EXIT_SUCCESS;
}

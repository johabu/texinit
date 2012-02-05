/*
*	texinit.c
*	Developed by Johabu <http://johabu.spheniscida.de>; <http://github.com/johabu>
*	
	This file is part of texinit.
*	texinit is free software; you can modify it or redistribute it
*	under the terms of the GNU General Public License as published by
*	the Free Software Foundation <http://www.fsf.org>, either version 3,
*	or (at your option) any later version.
*	See <http://www.gnu.org/licenses> for the license, if you
*	haven't received a copy of it (GNU_GPL.txt).
*	
*	texinit is distributed without any warranty!
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *datei;
	printf("Open file: \"%s\" ...",argv[1]);
	datei = fopen(argv[1], "w+");
	if (datei == NULL) {
		printf("\nError in opening\n");
		return EXIT_FAILURE;
	}
	printf(" OK\n");
	fclose(datei);
	return EXIT_SUCCESS;
}

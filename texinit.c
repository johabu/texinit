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
#include <string.h>

int show_help(void) {
	printf("\t====================HELP====================\n\n"\
		"texinit - program for generating TeX files.\n\n"\
		"USAGE:\n\t./texinit <file>\n"\
		"Attention: If <file> already exists, the program will ALL DATA OVERWRITE!\n"\
		"<file> must be a name without a file extension!\n\n");
	return EXIT_FAILURE;
}

int getopt(char *argument, char *option) {
	if( argument[0] == '-' && argument[1] == option[1]) 
		return 1;
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc == 1 || getopt(argv[1],"h") == 1) {
		show_help();
	}
	FILE *datei;
	printf("\n\nOpen file: \"%s\" ...",argv[1]);
	datei = fopen(strncat(argv[1],".tex",40), "w+");
	if (datei == NULL) {
		printf("\nError in opening\n");
		return EXIT_FAILURE;
	}
	printf(" OK\n");
	fclose(datei);
	return EXIT_SUCCESS;
}

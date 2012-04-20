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
#define TRUE 1
#define FALSE 0

void show_help(void) {
	printf("\t====================HELP====================\n\n"\
		"texinit - program for generating TeX files.\tversion 0.3.0\n\n"\
		"USAGE:\n\t./texinit <file>\n"\
		"Attention: If <file> already exists, the program will ALL DATA OVERWRITE!\n"\
		"<file> must be a name without a file extension.\n\n");
}

int getopt(char *argument, char *option) {
	if( argument[0] == '-' && argument[1] == option[1]) 
		return 1;
	return 0;
}

int main(int argc, char *argv[]) {
	char *paper_size, *doc_type, *lang, *title, *toc;
	char *paper_format[] = {"A4","A5","A6","B5","Letter","Legal"};
	char *paper_code[] = {"a4paper","a5paper","a6paper","b5paper","letterpaper","legalpaper"};
	char *doctype_code[] = {"scrartcl","scrreprt","scrbook","scrlttr2"};
	char *doctype[] = {"Article","Report","Book","Letter"};
	char *listoflang[] = {"english","german","french","spanish","italian","greek","russian"};
	int font_size, i, paper_choise, doc_choise, lang_choise, title_choise, toc_choise;
	if (argc == 1 || getopt(argv[1],"h") == 1) {
		show_help();
		return EXIT_FAILURE;
	}
	FILE *texfile;
	strncat(argv[1],".tex",40);
	printf("\n\nOpen file: \"%s\" ...",argv[1]);
	texfile = fopen(argv[1], "w+");
	if (texfile == NULL) {
		printf("\nError in opening\n");
		return EXIT_FAILURE;
	}
	printf(" OK\n\nChoose a paper format\n");
	for (i = 1; i <= 6; i++) {
		printf("%i:\t%s\n",i,paper_format[i-1]);
	}
	scanf("%i",&paper_choise);
	paper_size = paper_code[paper_choise-1];
	printf("\nNow choose the class of your document:\n");
	for (i = 1; i<=4; i++) {
		printf("%i:\t%s\n",i,doctype[i-1]);
	}
	scanf("%i",&doc_choise);
	doc_type = doctype_code[doc_choise-1];
	printf("\nChoose the language:\n");
	for (i = 1; i <= 7; i++) {
		printf("%i:\t%s\n",i,listoflang[i-1]);
	}
	scanf("%i",&lang_choise);
	lang = listoflang[lang_choise-1];
	printf("\nEnter font size in pt:\n");
	scanf("%i",&font_size);
	printf("\nMake a title? (0=no, 1=yes)\n");
	scanf("%i",&title_choise);
	title = "";
	if (title_choise == FALSE) {
		title = "%";
	}
	printf("\nMake a table of contents? (0=no, 1=yes)\n");
	scanf("%i",&toc_choise);
	toc = "";
	if (toc_choise == FALSE) {
		title = "%";
	}
	printf("\nWriting...\n");
	fprintf(texfile,"\\documentclass[%s, %ipt]{%s}\n"\
			"\\usepackage[%s]{babel}\n"\
			"\\usepackage[utf8]{inputenc}\n"\
			"\\usepackage[T1]{fontenc}\n\n"\
			"\\begin{document}\n"\
			"\\author{AUTHOR}\n"\
			"\\title{TITLE}\n"\
			"%s\\maketitle\n"\
			"%s\\tableofcontents\n\n"\
			"\\end{document}",paper_size,font_size,doc_type,lang,title,toc);
	printf(" Done.\nCreated file %s successfully.\n\n",argv[1]);
	fclose(texfile);
	return EXIT_SUCCESS;
}

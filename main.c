#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#define version = 0.1
static int print_version_flag;
static int print_help_flag;

int main(int argc, char **argv) {
  int c;

  while (1) {
    static struct option long_options[] = {
        {"version", no_argument, &print_version_flag, 1},
        {"help", no_argument, 0, 'h'},
        {"group", required_argument, 0, 'g'},
        {"variable", required_argument, 0, 'v'},
        {"matrix", required_argument, 0, 'm'},
        {"out", required_argument, 0, 'o'},
        {"file", required_argument, 0, 'f'},
        {0, 0, 0, 0}};
    /* getopt_long stores the option index here. */
    int option_index = 0;

    c = getopt_long(argc, argv, "g:v:m:o:f:", long_options, &option_index);

    /* Detect the end of the options. */
    if (c == -1)
      break;

    switch (c) {
    case 0:
      break;
    case 'g':
      puts("option -a\n");
      break;

    case 'v':
      puts("option -b\n");
      break;

    case 'm':
      printf("option -c with value `%s'\n", optarg);
      break;

    case 'o':
      printf("option -d with value `%s'\n", optarg);
      break;

    case 'f':
      printf("option -f with value `%s'\n", optarg);
      break;

    case '?':
      /* getopt_long already printed an error message. */
      break;

    default:
      abort();
    }
  }
  if (print_version_flag){
    puts("Version 0.1");
  }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc) {
    printf("non-option ARGV-elements: ");
    while (optind < argc)
      printf("%s ", argv[optind++]);
    putchar('\n');
  }

  exit(0);
}


#include <stdio.h>
#include <string.h>

// print_usage
//
//   this function prints a usage string to stderr. It is used in the code
//   below to indicate that the command line parameters passed at runtime were
//   invalid.
//
// parameters:
//
//   program_name - this is usually the value of argv[0]
static void
print_usage(char *program_name)
{
  fprintf(stderr, "usage: %s <cmd...> \\; <cmd...>\n", program_name);
}

// extract_commandns_from_argv
//
//   this function attemts to comprehend the command line arguments passed to
//   the program. The arguments are expected to be of the form:
//
//   <cmd> [arguments...] \; <cmd> [arguments...]
//
// parameters:
//
//   argc - the number of arguments passed to the program at runtime
//
//   argv - the array of arguments passed to the program at runtime
//
//   cmd1 - a pointer to a variable of type char** where the pointer to the
//   array of strings corresponding to the first command and its parameters
//   will be placed
//
//   cmd2 - a pointer to a variable of type char** where the pointer to the
//   array of strings corresponding to the second command and its parameters
//   will be placed
//
// return value:
//
//   the function returs 0 on success, and 1 otherwise
//
// errors:
//
//   the function will fail if the input is invalid and does not correspond to
//   the required form of:
//
//   <cmd> [arguments...] \; <cmd> [arguments...]
static int
extract_commands_from_argv(int argc, char *argv[], char ***cmd1, char ***cmd2)
{
  if (argc < 2)
    {
      print_usage(argv[0]);
      return 1;
    }

  *cmd1 = argv + 1;

  int i;
  for (i = 0; i < argc - 1; ++i)
    {
      if (!strcmp(argv[i], ";"))
        {
          argv[i] = NULL;
          *cmd2 = argv + i + 1;
        }
    }

  if (*cmd1 == NULL || *cmd2 == NULL)
    {
      print_usage(argv[0]);
      return 1;
    }

  return 0;
}

// print_array
//
//   this function prints an array of strings in python-esque list-style format
//   to stdout, optionally prefixed by the given string. The output format is:
//
//   <optional prefix> [ "value 1", "value 2", ... ]
//
// parameters:
//
//   prefix - the optional prefix for the output string
//
//   array - the zero-terminated array of strings to print
static void
print_array (char *prefix, char **array)
{
  char **ptr;

  printf("%s[ \"%s\"", prefix, *array);
  for (ptr = array + 1; *ptr != NULL; ++ptr)
    printf(", \"%s\"", *ptr);
  printf(" ]\n");
}


// this is the main function. Program execution begins here.
int
main (int argc, char *argv[])
{
  // prepare variables for both process commands
  char **cmd1 = NULL;
  char **cmd2 = NULL;

  // extract process commands from the command line arguments
  int res = extract_commands_from_argv(argc, argv, &cmd1, &cmd2);
  if (res != 0)
    return res;

  // display the parsed commands for convenience
  print_array("Command 1 is: ", cmd1);
  print_array("Command 2 is: ", cmd2);

  // TODO:
  //
  //   create a new process for both passed commands, and connect both
  //   processes with a pipe.
  //
  //   On POSIX, you will need the functions "fork", "exec*", "pipe" and "dup"
  //   to accomplish this task. On Windows, you will need at least the
  //   functions "CreateProcess" and "CreatePipe".
  //
  // Example:
  //
  //   Run the following command on a typical shell on a UNIX-like system:
  //
  //     $> date | wc
  //            1       6      30
  //
  //   Your code should produce the same output when invoking this program as:
  //
  //     $> processes_pipes date \; wc
  //            1       6      30
  //
  //   An alternative command for the Windows operating system could be this:
  //
  //     C:\> date /T | find /c /v ""
  //     1

  return 0;
}


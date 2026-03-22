#ifndef UTIL_H_
#define UTIL_H_
#include "Simulator.h"
#include "Type.h"

Command hashCommand(char*);
Subcommand hashSubcommand(char*);
TreeType hashTreeType(char*);
char* reverseHashTreeType(TreeType);

char* commandFormat(Command);
void printCommandFormat(Command);
void todo(char*);
#endif // UTIL_H
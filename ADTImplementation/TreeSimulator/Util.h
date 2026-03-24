#ifndef UTIL_H_
#define UTIL_H_
#include "Simulator.h"
#include "Type.h"
#include <stdbool.h>

Command hashCommand(char*);
char* reverseHashCommand(Command);
Subcommand hashSubcommand(char*);
TreeType hashTreeType(char*);
char* reverseHashTreeType(TreeType);

void printCommandFormat(Command);
void todo(char*);

bool readAndParseSubcommandToInt(int*, Command);
#endif // UTIL_H
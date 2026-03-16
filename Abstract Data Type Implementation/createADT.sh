filename=$1
touch "${filename}.h"
touch "${filename}.c"
echo "#include \"${filename}.h\"" > "${filename}.c"
touch "${filename}Main.c"
echo "#include \"${filename}.h\"
#include <stdio.h>

int main() {

}" > "${filename}Main.c"
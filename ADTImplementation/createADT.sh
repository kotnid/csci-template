ADT=$1
mkdir "${ADT}"
cd "./${ADT}"
touch "${ADT}.h"
touch "${ADT}.c"
echo "#include \"${ADT}.h\"" > "${ADT}.c"
touch "${ADT}Main.c"
echo "#include \"${ADT}.h\"
#include <stdio.h>

int main() {

}" > "${ADT}Main.c"
cd ..
exit 0
#include <string.h>
#include "security.h"
int verifyPin(const char *input_pin, const char *stored_pin) {
return strcmp(input_pin, stored_pin) == 0;
}
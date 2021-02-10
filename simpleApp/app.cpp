#include <stdio.h>

#include "GraalSample.h"

static graal_isolatethread_t * createGraalVM(__graal_uword gb) {
  graal_isolatethread_t* thread = 0;
    graal_create_isolate_params_t params = {
    __graal_create_isolate_params_version,
    gb * 1024 * 1024 * 1024
  };

  int error = graal_create_isolate(&params, 0, &thread);
  if (error != 0) {
    fprintf(stderr, "graal_create_isolate failed with %d\n", error);
    fflush(stderr);
    thread = 0;
  }
  return thread;
}


int main() {
  graal_isolatethread_t* graalThread = createGraalVM(2);
  if (graalThread) {
    int add4 = EntryPoints__add__e294c015aa64461959a1b2cb50ba9cc185789b28(graalThread, 4);
    int sub7 = EntryPoints__sub__f889e49a63b079c60481eb876fa6a0a0575f8f04(graalThread, 7);
    fprintf(stdout, "graal results: add(4) = %d, sub(7) = %d", add4, sub7);
    fflush(stdout);
    int error = graal_tear_down_isolate(graalThread);
  }
}

#include <metacall/metacall.h>

int main(int argc, char* argv[]) {

  if (argc < 2) {
    printf("Bad args\n");
    exit(1);
  }

  const char *rs_script = argv[1];

  metacall_initialize();

  metacall_load_from_package("rs", rs_script, NULL);


  void* arg = metacall_value_create_int(3);

  void *ret = metacallv_s("rocketvale_rust_test_call", &arg, 1);

  int result = (int)metacall_value_to_int(ret);

  printf("result: %d\n", result);

  metacall_value_destroy(arg);
  metacall_value_destroy(ret);
}
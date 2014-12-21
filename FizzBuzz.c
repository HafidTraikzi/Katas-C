#include <stdio.h>
#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#define true 1
#define false 0

int init_suite(void) {
  return 0;
}

int clean_suite(void) {
  return 0;
}

void test_fizzbuzz_1_donne_1(void) {
  CU_ASSERT_EQUAL(fizzbuzz(1), 1);
}

void test_fizzbuzz_3_donne_fizz(void) {
  CU_ASSERT_EQUAL(fizzbuzz(3), *"fizz");
}

void test_fizzbuzz_5_donne_buzz(void) {
  CU_ASSERT_EQUAL(fizzbuzz(5), *"buzz");
}

void test_fizzbuzz_15_donne_fizzbuzz(void) {
  CU_ASSERT_EQUAL(fizzbuzz(15), *"fizzbuzz");
}

void test_fizzbuzz_6_donne_fizz(void) {
  CU_ASSERT_EQUAL(fizzbuzz(6), *"fizz");
}

int fizzbuzz(number) {

  int sound_of_success = 0;
  
  if (number % 3 == 0) {
    sound_of_success += *"fizz";
    }
  else if (number % 5 == 0) {
    sound_of_success += *"buzz";
    }
  else {
     sound_of_success = number;
     }
}
  
int main(int argc, char *argv[]) {
  CU_pSuite pSuite = NULL;

        if(CU_initialize_registry() != CUE_SUCCESS)
        {
                return CU_get_error();
        }

        pSuite = CU_add_suite("First Suite", init_suite, clean_suite);
        if(pSuite == NULL)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }
        
        if((CU_add_test(pSuite, "Test Pass", test_fizzbuzz_1_donne_1) == NULL) ||
          (CU_add_test(pSuite, "Test Pass", test_fizzbuzz_3_donne_fizz) == NULL) ||
          (CU_add_test(pSuite, "Test Pass", test_fizzbuzz_5_donne_buzz) == NULL) ||
          (CU_add_test(pSuite, "Test Pass", test_fizzbuzz_15_donne_fizzbuzz) == NULL) ||
          (CU_add_test(pSuite, "Test Pass", test_fizzbuzz_6_donne_fizz) == NULL))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        
exit:
        CU_cleanup_registry();
        return CU_get_error();
}  
  

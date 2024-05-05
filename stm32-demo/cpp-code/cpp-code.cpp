#include "cpp-code.h"
#include <map>
#include <string>
#include <cstdint>
#include <cstdio>

#include "stm32f1xx_hal.h"

extern "C" uint32_t get_sbrk_call_count(void);
extern "C" uint32_t get_malloc_call_count(void);
extern "C" uint32_t get_free_call_count(void);

static const char cpp_text[] = "Hello, stm32 C++ developer!\r\n";

void function_to_investigate()
{
    std::map<std::string, int> m;
    for (int i = 1; i <= 10; ++i)
    {
        m[std::to_string(i)] = i;
    }
}

void print_stat()
{
    // Some code here should print statistic of _sbrk, malloc, free usage
    printf(cpp_text);
    printf("malloc() calls: %lu\r\n", get_malloc_call_count());
    printf("free() calls: %lu\r\n", get_free_call_count());
    printf("_sbrk() calls: %lu\r\n", get_sbrk_call_count());
}

void cpp_code_entry_point()
{
    function_to_investigate();
    print_stat();
}

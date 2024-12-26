#include "ry/ry.hpp"

class TestClass
{
    u32 i = 20;
    public:

    __attribute__((noinline)) void callback_example(u32* number)
    {
        u32 local_num = *number;
        i += local_num;
        RY_LOG("TestClass", "from method - arg is: " << number <<", number: " << std::dec << local_num << ", I: " << i )
    }
};
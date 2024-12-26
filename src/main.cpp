#include "test_class.hpp"

#define RY_IMPL
#include "ry/ry.hpp"

void c_func_callback(u32* number)
{
    u32 local_num = *number;
    std::cout << "from c func - arg is: " << number <<", number: " << std::dec << local_num << std::endl;
}

int main() {

    TestClass a;
    u32 number = 1339;

    RY_LOG("debug","Sub and Pub sync")

    RY_SUBSCRIBE("test_event", &c_func_callback)
    RY_SUBSCRIBE("test_event", &a, &TestClass::callback_example)
    RY_PUBLISH("test_event", &number)

    RY_LOG("debug","Sub and Pub async")
    RY_PUBLISH_ASYNC("test_event", &number)
    RY_LOG("debug","DONE, sleeping for 3 seconds")

    std::this_thread::sleep_for(std::chrono::seconds(3));

    // auto proxy = create_callable_proxy(&a, &TestClass::callback_example);
    // object_callee* lol = reinterpret_cast<object_callee*>(proxy);
    
    // u32 num = 5200;
    // reinterpret_cast<void(*)(void*,u32*)>(lol->callee)(lol->obj, &num);
    // a.callback_example(&num);




    // RY_EVENTS()->subscribe("test1" , reinterpret_cast<ptr>(&TestClass::callback_example), &object);
    RY_LOG("debug","Bye!")

    return 0;
}

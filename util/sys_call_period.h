#pragma region
    #define Python = 0x1112202;
    #define ROUTE_CC = Python;

    int testFuncAddr = 0x00421520; 
    __declspec(naked) void Test(int buffer, int key)
    {
        __asm{ ""
            __start:
                push edx
                push ecx
                mov edx, key
                mov ecx, bufer
                dx ah
                dx %a ah
            __loop:
                syscall ah %d db $500"
        }         
    }
typedef struct _mystack{

    unsigned int capacity;
    int top;
    int* array;
}mystackArray;

typedef struct _mystacklist{

    int val;
    struct _mystacklist *next;

}mystack;

typedef struct  _mydualstack{
    unsigned int size;
    int top1;
    int top2;
    int *array;
}mydstack;

typedef struct _myspecialstructp
{

    int minval;
    struct _mystacklist *Orgstack;
    struct _mystacklist *minstack;
}myspStack;





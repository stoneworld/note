指针相关注意点：

1. 指针只能指向某种特定类型的对象，也就是说，每个指针都必须指向某个特定的数据类型
一个例外情况是指向 void 类型的指针可以存放指向任何类型的指针，但它不能间接引用其自身。
2. 一元运算符 * 和 & 的优先级比算数运算符的优先级高。 
*ip += 1 等价于 (*ip)++这个括号是必须的，因为类似 * 和 ++ 这样的一元运算符遵循从右至左的结合顺序。
3. double atof(char *) 说明参数是一个指向 char 类型的指针。
4. 指针与整数之前不能相互转换，但 0 是唯一的例外：常量 0 可以赋值给指针，指针也可以和常量 0 进行比较。
5. 如果指针 p 和 q 指向同一个数组的成员，那么他们之间就可以进行类似于 == 、!= 、 < 关系比较运算。
如果 p 指向的数组元素的位置在 q 指向的数组元素位置之前，那么关系表达式 p < q 的值为真。
6. 所有的指针运算都会自动考虑它所指向的对象的长度。float *p 指针 p++ 将指向下一个浮点数的地址。

指针与数组：
一般情况下 数组名所代表的是该数组最开始的一个元素的地址。
在以下两中场合下，数组名并不是用指针常量来表示，
就是当数组名作为sizeof操作符和单目操作符&的操作数时,sizeof返回整个数组的长度，而不是指向数组的指针的长度。 
取一个数组名的地址所产生的是一个指向数组的指针，而不是一个指向某个指针常量的指针。
所以&a后返回的指针便是指向数组的指针，跟a（一个指向a[0]的指针）在指针的类型上是有区别的。

字符指针与函数：
1. 字符串常量是一个字符数组，例如 "I am a string", 
printf("hello world\n") 示例中 printf 接受的是一个指向字符数组的第一个字符的指针，
也就是说，字符串常量可通过一个指向其第一个元素的指针访问。
2. 数组 && 字符指针
```
    char amessage[] = "now is the time";
    char sme = amessage;
    char *pmessage = "now is the time";
    printf("%s\n", amessage); // now is the time
    printf("%p\n", amessage); //0x7ffee0fd8920 指针地址
    printf("%p\n", sme); 
    amessage[2] = 'e';
    printf("%s\n", amessage); //noe is the time
    printf("%p\n", amessage); //0x7ffee0fd8920 指针地址 保持不变 

    printf("%s\n", pmessage); //now is the time
    printf("%p\n", pmessage); //0x10ec27f90

    pmessage = "is time";

    printf("%s\n", pmessage); //is time
    printf("%p\n", pmessage); // 0x10ec27fa8 修改后指针指向其它地址
```
以上说明: amessage 是一个仅仅足以存放初始化字符串以及空字符串 '\0' 的一维数组。数组中的单个字符可以进行修改，
但 amessage 始终指向同一个存储位置。另一方面，pmessage 是一个指针，其初值指向一个字符串常量，之后可以被修改以指向其它地址。


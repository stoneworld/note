# EOF是什么？
#计算机原理

作者： [阮一峰](http://www.ruanyifeng.com)

我学习C语言的时候，遇到的一个问题就是 [EOF](http://en.wikipedia.org/wiki/End-of-file) 。

它是end of file的缩写，表示"文字流"（stream）的结尾。这里的"文字流"，可以是文件（file），也可以是标准输入（stdin）。

比如，下面这段代码就表示，如果不是文件结尾，就把文件的内容复制到屏幕上。

```c
int c;
while ((c = fgetc(fp)) != EOF) {
	putchar (c);
}
```


很自然地，我就以为，每个文件的结尾处，有一个叫做EOF的特殊字符，读取到这个字符，操作系统就认为文件结束了。

但是，后来我发现，EOF不是特殊字符，而是一个定义在头文件stdio.h的常量，一般等于-1。

```c
＃define EOF (-1)
```

于是，我就困惑了。

如果EOF是一个特殊字符，那么假定每个文本文件的结尾都有一个EOF（也就是-1），还是可以做到的，因为文本对应的ASCII码都是正值，不可能有负值。但是，二进制文件怎么办呢？怎么处理文件内部包含的-1呢？

这个问题让我想了很久，后来查了资料才知道， **在Linux系统之中，EOF根本不是一个字符，而是当系统读取到文件结尾，所返回的一个信号值（也就是-1）。** 至于系统怎么知道文件的结尾，资料上说是通过比较文件的长度。

所以，处理文件可以写成下面这样：

```c
int c;
while ((c = fgetc(fp)) != EOF) {
	do something
}
```

这样写有一个 [问题](http://www.cplusplus.com/reference/clibrary/cstdio/fgetc/) 。fgetc()不仅是遇到文件结尾时返回EOF，而且当发生错误时，也会返回EOF。因此，C语言又提供了feof()函数，用来保证确实是到了文件结尾。上面的代码feof()版本的写法就是：

```c
int c;
while (!feof(fp)) {
	c = fgetc(fp);
	do something;
}
```

但是，这样写也有 [问题](http://www.drpaulcarter.com/cs/common-c-errors.php#4.2) 。fgetc()读取文件的最后一个字符以后，C语言的feof()函数依然返回0，表明没有到达文件结尾；只有当fgetc()向后再读取一个字符（即越过最后一个字符），feof()才会返回一个非零值，表示到达文件结尾。

所以，按照上面这样写法，如果一个文件含有n个字符，那么while循环的内部操作会运行n+1次。所以，最保险的 [写法](http://www.geeksforgeeks.org/archives/9797) 是像下面这样：

```c
int c = fgetc(fp);
while (c != EOF) {
	do something;
	c = fgetc(fp);
}
if (feof(fp)) {
	printf("\n End of file reached.");
} else {
	printf("\n Something went wrong.");
}
```


除了表示文件结尾，EOF还可以表示标准输入的结尾。

```c
int c;
while ((c = getchar()) != EOF) {
	putchar(c);
}
```

但是，标准输入与文件不一样，无法事先知道输入的长度，必须手动输入一个字符，表示到达EOF。

Linux中，在新的一行的开头，按下Ctrl-D，就代表EOF（如果在一行的中间按下Ctrl-D，则表示输出"标准输入"的缓存区，所以这时必须按两次Ctrl-D）；Windows中，Ctrl-Z表示EOF。（顺便提一句，Linux中按下Ctrl-Z，表示将该进程中断，在后台挂起，用fg命令可以重新切回到前台；按下Ctrl-C表示终止该进程。）

那么，如果真的想输入Ctrl-D怎么办？这时必须先按下Ctrl-V，然后就可以输入Ctrl-D，系统就不会认为这是EOF信号。 [Ctrl-V](http://en.wikipedia.org/wiki/Ctrl-V) 表示按"字面含义"解读下一个输入，要是想按"字面含义"输入Ctrl-V，连续输入两次就行了。

（完）
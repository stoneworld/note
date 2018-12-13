## awk 常见使用教程

awk 使用的时候有两个要求就是脚本必须放到{}中,由于awk命令假定脚本是单个文本字符串，所以必须将脚本放到单引号中。

> gawk 是Unix 中的原始awk程序的GNU版本 所以 mac 中需要 brew install gawk && echo 'alias awk=gawk' \>\> ~/.zshrc

```shell

gawk '{print "hello world"}' test.txt

```
`gawk` 会对数据流中的每行文本执行脚本程序，所以上面的程序结果是打印和 test.txt 同样行数的 `hello world`

在每个文本行中，gawk 会根据 `字段分隔符` 给行元素分配变量，默认的字段分割符是任意的空白字符，但我们可以通过参数 -F 设定。
分配的数据字段如下：

* $0 代表整个文本行
* $1 代表文本行中的第一个数据字段
* $n 代表的事文本行中的第n个数据字段

```shell

gawk -F : '{print $1}' /etc/passwd # 在此用冒号指定为字段分割符

nobody
root
daemon
[...]

```

gawk 允许你将多条命令组合成一个正常的程序。命令行之间添加分号即可, `BEGIN` 允许你在处理数据之前运行相关脚本, `END` 关键字允许指定一个脚本程序在 `gawk` 读取完数据后执行。

```shell

echo "My name is Rich" | gawk '{$4="test"; print $0}'

My name is test

echo "My name is Rich" | gawk 'BEGIN {print "start"} {$4="test";p
rint $0} END {print "End of File"}'
start
My name is test
End of File
```

## sed 编辑器基础

> Mac 的 sed 是 BSD 版本 注意：brew install gnu-sed --with-default-names

### 常见替换选项

```shell
echo "this is test a test" | sed 's/test/big test/'
this is big test a test
```

上面的例子使用了 s 命令，s 命令会用斜线的第二个文本替换第一个文本，但我们可以看到只是第一处进行了替换，如果要处理这种问题可以使用 `替换标记`，有以下四种替换标记：
* 数字，表明新文本将替换第几处模式匹配的地方。
* g, 表明新文本将会替换所有匹配的文本。
* p, 表明原先行的内容要打印出来,用于显示模式缓存区的内容
* w file, 将替换的结果写入到文件中。

```shell

echo "this is test a test" | sed 's/test/big test/g'

this is big test a big test

```

### 使用地址

正常情况下 sed 会作用到文本数据的每一行，如果只想将命令作用到特定行或者某些行，需要使用 `行寻址`,有以下形式：

数字方式的行寻址

```shell

sed '2s/dog/cat/' test.txt #第二行
sed '2,3s/dog/cat/' test.txt #行地址区间
sed '2,$s/dog/cat/' test.txt # 从某行开始的所有行，使用 $ 符号标记

```

文本模式过滤

```shell

sed '/wang/s/bash/csh/' /etc/passwd  # 前面的 wang 说明只处理匹配到该文本的行,当然使用正则是最方便。

```

### 删除行

删除命令 d 可以配合寻址模式进行删除文本

```shell
sed '2d' test.txt

sed '/number 1/d' test.txt #删除匹配到 number 的第一行
```

### 插入和附件文本

* 插入 (insert) 命令 i 会在指定行前增加一个新行
* 附件 (append) 命令 a 会在指定行后增加一个新行

> sed '[address]command\ new line'

```shell
sed '1i\this is new line.' test.txt

this is new line.
the quick brown fox
the quick brown fox1
the quick brown fox2

sed '1a\this is new line.' test.txt

the quick brown fox
this is new line.
the quick brown fox1
the quick brown fox2

sed '$a\this is new line.' test.txt  # $ 代表最后一行

```

### 修改行


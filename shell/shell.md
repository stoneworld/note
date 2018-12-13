## shell 基础学习记录
#shell

###常见使用技巧

1. 从命令行输出中提取信息并赋值给变量，通过以下两种形式：反引号字符`或者$()格式。
> testing=\`date\` testing=$(date)

2. 输出重定向通过 `>` 符号完成该项功能, `>>` 可以追加到文件
> command > outputfile

3. 输入重定向和输出重定向正好相反。输入重定向将文件的内容重定向到命令，而非将命令的输出重定向到文件。
> command < inputfile

4. 管道 `|` 可以将一个命令的输出作为另一个命令的输入，类似：
> command1 | command2  
> rpm -qa | sort  > rpm.list

5. 文件比较
```shell
-d file # 检查file是否存在并是一个目录
-e file # 检查file文件是否存在
-f file # 检查file是否存在并是一个文件
-r file # 检查file是否存在并可读
-s file # 检查file是否存在并非空
-w file # 检查file是否存在并可写
-x file # 检查file是否存在并执行


#!/bin/bash
jump_directory=/home/arthur
if [ -d $jump_directory ]; then
    echo "The $jump_directory directory exists"
else
    echo "The $jump_directory directory does not exist"
fi

```

6. 用于双括号的数学表达式的比较
> if (( $val ** 2 > 90 )); then

7. 用户双方括号的字符串比较
> if [[ $user ==  r* ]]; then  # r* 是一个匹配模式 看是否是以字母r开头

8. for 循环，此次的循环 手动设定了 IFS 环境变量，因为默认的字段分隔符包含空格、制表符、换行符，就不能按照我们设想的按行输出，所以在此设定了IFS使其只能识别换行符

```shell

#!/bin/bash

file="shell.md"
IFS.OLD=$IFS
IFS=$'\n'
for state in $(cat $file)
do
    echo "$state"
done
IFS=$IFS.OLD #重置

```

9. while 循环 

```shell
#!/bin/bash

var1=10
while [ $var1 -gt 0 ]
do
    echo $var1
    var1=$[ $var1 - 1 ]
done

```

10. 重定向错误和数据，可以使用特殊重定向符号 `&>`
标准文件描述符如下：

```
0   STDIN   标准输入
1   STDOUT  标准输出
2   STDERR  标准错误
```

11. 阻止命令输出 

>  >/dev/null 2>&1 # 首先表示标准输出重定向到空设备文件，也就是不输出任何信息到终端，说白了就是不显示任何信息。接着，标准错误输出重定向（等同于）标准输出，因为之前标准输出已经重定向到了空设备文件，所以标准错误输出也重定向到空设备文件。

12. 以后台模式运行脚本

有时候一个脚本要执行很长一段时间，而你不想在命令行界面干等着，那么在命令后几个&符就可以了。
> command &
但这种方式会在登出控制台后退出相关进程，但有些时候需要在终端会话中启动shell脚本，让脚本一直以后台模式运行到结束，即使退出终端会话。这我们可以用到 `nohup` 命令来实现, `nohup` 会将 `STDOUT` 和 `STDERR` 的消息重定向到一个名为 `nohup.out` 的文件中
> nohup ./test.sh &
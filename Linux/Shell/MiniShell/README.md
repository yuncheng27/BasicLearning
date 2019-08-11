### MiniShell


> - setup信号安装部分在初始化模块中，分为两个部分init.h和init.c
> - externs.h主要是一些外部变量的声明
> - def.h声明一些各个模块中用到的宏
> - shell_loop的主循环在parse.h和parse.cc这两个命令解析模块中
> - 在shell_loop的主循环while(1)中解析完命令就是执行命令，执行命令在execute.h和execute.c两个文件中实现

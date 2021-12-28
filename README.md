# alarmclock
windows 控制台定时闹钟

命令行 或者 批处理 使用以下命令， 到技时 20秒后开启指定的程序
```C
alarmclock.exe  20 "C:\soft\foobar2000\foobar2000.exe"
```


分享: 控制台写个闹钟程序 分解,解释文章
http://bbs.csdn.net/topics/392285253


编写和调试工具 IDE
CodeBlocks SVN 11112版 双11特别版
http://bbs.csdn.net/topics/392284220

![](http://img.bbs.csdn.net/upload/201711/10/1510289090_391006.png)


## 定时闹钟 For Linux 版本

源码: [tt.cpp下载](https://github.com/hongwenjun/alarmclock/commit/e2f96dee4c898159d15b09004390073dea305a4c)

## 使用 g++ 编译

    g++ tt.cpp -o tt

## 定时器无限循环使用示例,tmux 开启一个后台窗口，输入下面命令

    while :
    do
    ./tt 10  "curl -sL 262235.xyz/index.php"
    done


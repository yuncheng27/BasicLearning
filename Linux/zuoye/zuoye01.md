(py3env) pyvip@VIP:~/code$ ls
C  DataStruct  Linux  README.md  test
(py3env) pyvip@VIP:~/code$ clear
(py3env) pyvip@VIP:~/code$ ls
C  DataStruct  Linux  README.md  test
(py3env) pyvip@VIP:~/code$ ls -l
总用量 20
drwxrwxr-x  4 pyvip pyvip 4096 11月 29 15:55 C
drwxrwxr-x 10 pyvip pyvip 4096 12月  5 13:22 DataStruct
drwxrwxr-x  8 pyvip pyvip 4096 12月  7 21:05 Linux
-rw-rw-r--  1 pyvip pyvip   25 11月 29 12:39 README.md
drwxrwxr-x  4 pyvip pyvip 4096 12月  2 13:13 test
(py3env) pyvip@VIP:~/code$ ls -a
.  ..  C  DataStruct  .git  Linux  README.md  test
(py3env) pyvip@VIP:~/code$ ls .
C  DataStruct  Linux  README.md  test
(py3env) pyvip@VIP:~/code$ ls ..
AI  code  core  Linux  other  公共的  模板  视频  图片  文档  下载  音乐  桌面
(py3env) pyvip@VIP:~/code$ ls /
bin   cdrom  etc   initrd.img      lib    lib64       media  opt   root  sbin  srv       sys  usr  vmlinuz
boot  dev    home  initrd.img.old  lib32  lost+found  mnt    proc  run   snap  swapfile  tmp  var  vmlinuz.old
(py3env) pyvip@VIP:~/code$ ls ./
C  DataStruct  Linux  README.md  test
(py3env) pyvip@VIP:~/code$ pwd
/home/pyvip/code
(py3env) pyvip@VIP:~/code$ mkdir -p hh1/hh2/hh3
(py3env) pyvip@VIP:~/code$ touch hh1/hh2/hh3/hh.h
(py3env) pyvip@VIP:~/code$ ls hh1/hh2/hh3
hh.h
(py3env) pyvip@VIP:~/code$ mv hh1/hh2/hh3/hh.h ./
(py3env) pyvip@VIP:~/code$ ls
C  DataStruct  hh1  hh.h  Linux  README.md  test
(py3env) pyvip@VIP:~/code$ rm hh.h
(py3env) pyvip@VIP:~/code$ rm -r hh1
(py3env) pyvip@VIP:~/code$ ls
C  DataStruct  Linux  README.md  test


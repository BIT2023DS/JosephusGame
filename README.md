# JosephusGame
BIT 2023 Data Structure Project1 JosephusGame 

关于git的使用
自己去看教程，为了保持项目持有的是最核心的源码，不要把.vscode add和commit到github,不要把x64commit和push到github,build也不要上传，因为每个机器编译结果不同，别人的可执行文件不一定可以在你的电脑上跑

当前源文件只包含主菜单，注册和查找，其他部分需要我们先把项目clone到本地，然后修改，再push到github上


## 关于cmake
我写了一个cmake（其实很简单），这样在vscode上也可以跑我们组的项目。一直用VS也不是个事吧，你连文件都不知道怎么连在一起的，到时候VS不给你用了，啥项目都写不出来了，而且现在众多开源cpp项目都是cmake,正好借此机会学一下
下面是具体方法：
首先需要你进一个文件夹 ，然后把github上的文件clone到本地

```
git clone --recursive https://github.com/BIT2023DS/JosephusGame
```

因为用了其他的模型，有submodule,所以要recursive去clone module

把项目拷贝到当前文件夹，在该文件夹下创建build文件夹（用来存储编译文件），然后进入build文件夹

```
cd build
```

在build文件夹下


(linux)
```
cmake ..
```

(windows)
```
cmake .. -G "MinGW Makefiles"
```

//..表示告诉cmake从上一级文件夹中找我们的源文件和CMakelists.txt

然后
make
就会产生一个可执行文件JosephusGame
（在build文件夹下）

./JosephusGame 
来运行程序

windows下操作
```
git clone --recursive https://github.com/BIT2023DS/JosephusGame
cd JosephusGame
mkdir build
cd build 
cmake .. -G "MinGW Makefiles"
make
.\JosephusGame.exe
```
如果windows没有make命令，下载chocolatey，然后choco install make

在linux系统下
```
git clone --recursive https://github.com/BIT2023DS/JosephusGame
cd JosephusGame
mkdir build
cd build 
cmake ..
make
./JosephusGame
```

### Debug in vscode
USER MENU一级目录里面的CMakeLists.txt已经set
(CMAKE_BUILD_TYPE debug) 故在vscode里面添加断点是可以调试的

在make后，我们需要设置一下.vscode/里的launch.json(一般是自动生成一份，然后修改)

"Configuration":"program": "${workspaceFolder}/build/JosephusGame",
表示debug的是build文件夹下JosephusGame文件

### 关于vscode引用头文件报错
Ctrl+Shift+P输入C/C++打开edit configuration,会在.vscode目录下生成c_cpp_properties.json文件，这个包含了vscode从哪里include 头文件(平时我们直接把头文件堆在当前目录，他能找到，是因为vscode默认了在当前文件夹最高级的目录下找),为了显示调用的包3rdparty里面的.h文件
我们在c_cpp_properties的"configuration":"includePath" 加上
                "${workspaceFolder}/3rdparty/**"就可以了

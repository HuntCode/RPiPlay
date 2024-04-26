# RPiPlay
基于开源RPiPlay，实现AirPlay接收端

## 编译

### Android平台

#### 交叉编译配置
1.下载NDK文件
https://developer.android.com/ndk/downloads?hl=zh-cn
android-ndk-r26c-linux.zip

2.Ubuntu上配置对应值

1）将下面内容写入~/.bashrc文件最后
```bash
export NDK=/home/wanglv/workspace/tools/android-ndk-r26c

# Only choose one of these, depending on your build machine...
#export TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/darwin-x86_64
export TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/linux-x86_64

# Only choose one of these, depending on your device...
export TARGET=aarch64-linux-android
#export TARGET=armv7a-linux-androideabi
#export TARGET=i686-linux-android
#export TARGET=x86_64-linux-android

# Set this to your minSdkVersion.
export API=21
```

2）可以执行source ~/.bashrc使生效

3）写一个简单的hello world
```C++
#include <stdio.h>

int main()
{
        printf("Hello Ubuntu\n");
        return 0;
}
```

4）用交叉编译器编译
```bash
$TOOLCHAIN/bin/$TARGET$API-clang main.cpp -o main
```

```
$TOOLCHAIN/bin/$TARGET$API-clang可以赋值给CC，用于make或者cmake体系，具体根据情况而定
```


3.进入项目目录~/RPiPlay,在Ubuntu上执行命令
```shell
mkdir build_android && cd build_android

cmake -DCMAKE_TOOLCHAIN_FILE=$NDK/build/cmake/android.toolchain.cmake \
      -DANDROID_ABI="armeabi-v7a" \
      -DANDROID_NDK=$NDK \
      -DANDROID_PLATFORM=android-21 ..

make
```

TODO:
1.验证可行性
2.对于多个架构分别生成到指定路径，armeabi-v7a、arm64-v8a、x86、x86_64

### Windows平台

项目依赖相关库：
pthread
plist
openssl

借助vcpkg直接安装即可，具体参考https://github.com/microsoft/vcpkg

进入项目目录~/RPiPlay
```shell
mkdir build_Win32 && cd build_Win32

cmake -G "Visual Studio 17 2022" -A "Win32" ..

```

<div align=center>
<img src="https://s2.loli.net/2022/08/10/POZxDkeq7vISwRo.png" width="150"/>
</div>

# MinecraftCerver
 使用C++ 重写 Minecraft 服务端核心

由于 Minecraft 原版服务端核心对多线程的支持并不友好，为了更好的支持多线程，使用 C++ 重写 Minecraft 服务端核心。

## 任务计划

1. 完成 Minecraft 服务端核心的 C++ 重写；  0.75%
2. 使用 C++ 特性对重写后的 Minecraft 服务端核心进行优化；
3. 针对一些重计算任务进行多线程优化；
4. 设计 Java 兼容层，提供原版/Spigot API 以支持插件；
5. GPU 计算加速支持；  X

## 使用的三方库

- [glog](https://github.com/google/glog)

2012年，Mozilla 的工程师 Alon Zakai 在研究 LLVM 编译器时突发奇想：许多 3D 游戏都是用 C / C++ 语言写的，如果能将 C / C++ 语言编译成 JavaScript 代码，它们不就能在浏览器里运行了吗？众所周知，JavaScript 的基本语法与 C 语言高度相似。

于是，他开始研究怎么才能实现这个目标，为此专门做了一个编译器项目 Emscripten。这个编译器可以将 C / C++ 代码编译成 JS 代码。

参考文章：
1. https://developer.mozilla.org/en-US/docs/WebAssembly/Concepts
2. https://www.ibm.com/developerworks/cn/web/wa-lo-webassembly-status-and-reality/index.html
3. https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html
4. https://github.com/mbasso/asm-dom(c++实现简版vdom)

### 编译c++代码
c++代码在hello.cc里，使用以下命令编译

```
emcc hello.cc -o hello.html
```

命令的安装请参考<a href="https://github.com/antgod/webassembly/blob/master/install.md">`install.md`</a>。

### 运行
直接使用node或者服务器运行html都可以
```
node hello.js
```

结果
```
val2 == 42
```

或者启动服务器
```
npm -g http-server
http-server
```

浏览器直接访问: localhost:3000/hello.html即可

结果
```
val2 == 42
```

### 性能报告
to be continue...
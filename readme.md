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
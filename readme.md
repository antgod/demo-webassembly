### 简介
2012年，Mozilla 的工程师 Alon Zakai 在研究 LLVM 编译器时突发奇想：许多 3D 游戏都是用 C / C++ 语言写的，如果能将 C / C++ 语言编译成 JavaScript 代码，它们不就能在浏览器里运行了吗？众所周知，JavaScript 的基本语法与 C 语言高度相似。

于是，他开始研究怎么才能实现这个目标，为此专门做了一个编译器项目 Emscripten。这个编译器可以将 C / C++ 代码编译成 JS 代码。

参考文章：
1. https://developer.mozilla.org/en-US/docs/WebAssembly/Concepts
2. https://www.ibm.com/developerworks/cn/web/wa-lo-webassembly-status-and-reality/index.html
3. https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html
4. https://github.com/mbasso/asm-dom(c++实现简版vdom)

### 编译c++代码
c++代码在helloworld.cpp里

#### 直接编译

```bash
emcc helloworld.cpp -o helloworld.js
```

- 命令的安装请参考
<a href="https://github.com/antgod/webassembly/blob/master/install.md">`install.md`</a>。

#### 容器内编译
```bash
docker run \
  --rm \
  -v $(pwd):/src \
  -u $(id -u):$(id -g) \
  emscripten/emsdk \
  emcc helloworld.cpp -o helloworld.js
```

- 命令的安装请参考
<a href="https://yuque.antfin.com/ait-fe/nlp/vmhwf1">`install.md`</a>。
### 运行
#### 运行JS
直接使用node或者服务器运行html都可以
```bash
node helloworld.js
```

结果
```
42
```

#### 运行wasm
```js
fetch('./helloworld.wasm').then(response =>
  response.arrayBuffer()
).then(buffer =>{
  return WebAssembly.compile(buffer)
}).then(module =>{
  return WebAssembly.instantiate(module, importObject)
}).then(instance => {
  debugger
  console.log('instance.exports.main() :>> ', instance.exports.main());
});
```


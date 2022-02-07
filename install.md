### C++编译器 Emscripten 安装

官网：https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html

经过一天的努力，终于把Emscripten安装上了。网上有各种方案，但到最后你会发现，大部分都会安装失败。

千万记住，不要按照官网文档安装、不要修改系统默认python版本。

按照以下方式：一次安装成功（切记要先切换python默认版本再安装Emscripten）。

#### 切换系统默认python版本
```shell
brew upgrade python
python3 -V
vim ~/.bash_profile
```

记录下刚才-V的版本号，在最后一行添加，并替换{version}位置的版本号：

比如你的版本是3.7.0，那就替换成（替换前可以先去终端查看下路径是否存在）

```
alias python="/usr/local/Cellar/python/3.7.5/Frameworks/Python.framework/Versions/3.7/bin/python3.7"
```
然后运行

```
source ~/.bash_profile
python -V
```

如果看到以下结果，证明切换默认python版本成功
```
Python 3.7.0
```

### 安装 Emscripten
如果你按照官网的方式安装，各种网络问题以及报错，安装了一天都没有成功。然后看到这篇文章，会不会像我一样想打人？

http://brewformulas.org/Emscripten

没错，一行代码搞定。

然后还得切换下配置，这个运行emcc命令会提示的，修改下LLVM的路径。

```
vim ~/.emscripten
```

第十行改成下面的内容

```
LLVM_ROOT = os.path.expanduser(os.getenv('LLVM', '/usr/local/opt/emscripten/libexec/llvm/bin')) # directory
```

#### 安装cmake

```
brew install cmake
```


#### 如果你先安装Emscripten，后切换python，这种必须卸载Emscripten才可以。

```
rm -rf /usr/local/opt/emscripten
rm -f ~/.emscripten
brew uninstall emscripten
```

这样才能清理干净，否则都由于卸载不全，Emscripten仍然使用内置的phthon2.7导致各种报错。
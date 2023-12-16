# Linux 系统

# Linux的目录结构

Linux的目录结构是一个树型结构，没有盘符概念，只有一个根目录 **/**，所有文件都在它下面。

<img src="/home/kano/.config/Typora/typora-user-images/image-20231216143447861.png" alt="image-20231216143447861" style="zoom: 50%;" />

### Linux路径描述方式

在Linux中，路径之间的层级关系，使用**/**来表示。

<img src="/home/kano/.config/Typora/typora-user-images/image-20231216143843533.png" alt="image-20231216143843533" style="zoom: 50%;" />

如图中文件的路径：/usr/local/hello.txt

## Linux命令入门

### Linux命令基础

无论是什么命令，用于什么用途，在Linux中，命令有其通用的格式：

`command [-options] [parameter]` 

* command: 命令本身
* -options:[可选]命令的一些选项，可以通过选项控制命令的行为细节
* parameter:[可选]命令的参数，多数用于命令的指向目标等



示例：

* ls -l /home/itheima, ls是命令本身, -l是选项,/home/itheima是参数
	*  **意思是以列表的形式，显示/home/itheima目录内的内容**
* cp -r test1 test2,cp是命令本身，-r是选项,test1和test2是参数
  * **意思是复制文件夹test1成为test2**

#### ls命令

ls命令的作用是列出目录下的内容，语法细节如下：

`ls [-a -l -h] [Linux路径]`

* -a -l -h 是可选的选项
  * -a选项：表示all，即列出全部文件（包括隐藏文件）
  * -l选项：表示list，即以列表的形式展示内容，并展示更多信息
  * -h选项：表示以易于阅读的方式，列出文件大小（必须搭配-l使用）

> **注意**：
>
> ​	语法中的选项是可以组合使用的，如-a和-l

* Linux路径是此命令可选的参数，表示要查看的Linux路径。

当不使用选项和参数，直接使用ls命令本体，表示：以平铺形式列出当前工作目录下的内容


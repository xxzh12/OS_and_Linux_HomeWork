# Killer Queen 杜王町聊天室

> 小组成员：纪宇豪、徐宇航、宋煜、徐宸宇
>
> 项目开展时间：4/26-5/14

[TOC]

## 项目概述

本次Linux大作业我们组实现了一个基于TCP与SQL的网络聊天室。客户端具有**图形化界面**，支持修改字体的**格式**、**大小**、**颜色**，以及**图片上传**、显示**在线成员列表**、查看**历史消息**等功能。用户通过输入用户名和账号登录之后即可在我们的网络聊天室畅所欲言！

本项目主要由**客户端**、**服务器**、**数据库**三部分组成，其中客户端使用Qt框架实现，服务器由C++代码编写而成，数据库使用MySQL进行管理。在进行数据通信时，项目的工作流程如下：

* 项目工作流程

![ChatRoom流程图](./Images/ChatRoom流程图.png)

* 项目框架

本项目的客户端部分使用跨平台的C++图形用户界面应用程序开发框架[Qt](https://www.qt.io/zh-cn/)及其IDE [Qt Creator](https://www.qt.io/zh-cn/development-tools?hsLang=zh-cn)开发而成，主要分为登陆界面[logwidgt](./OS_and_Linux_HomeWork-main/client/logwidget.cpp)、聊天界面[clientwindow](./OS_and_Linux_HomeWork-main/client/clientwindow.cpp)、数据头解码[dataparser](./OS_and_Linux_HomeWork-main/client/dataparser.cpp)、信息获取与编码[readclient](./OS_and_Linux_HomeWork-main/client/readclient.cpp)以及主程序[main](./OS_and_Linux_HomeWork-main/client/main.cpp)共五个部分。

服务器端使用C++代码编写，主要有数据头编码[ProtocolHead](./OS_and_Linux_HomeWork-main/server/ProtocolHead)、数据头解码[DataProcessor](./OS_and_Linux_HomeWork-main/server/DataProcessor)、用户管理[Online](./OS_and_Linux_HomeWork-main/server/Online)以及主程序[main](./OS_and_Linux_HomeWork-main/server/main)这几个部分。

数据库部分基于Qt开发框架对MySQL进行管理，并整理出相关函数接口用于客户端调用，主要代码存放于[mysqldb](./OS_and_Linux_HomeWork-main/client/mysqldb.cpp)中。

* 代码管理

本项目全程在linux中使用git进行代码管理，并使用GitHub进行代码托管，小组成员每个人各自管理一个分支，并在项目的最后将验证过的完善代码合并到主分支main下。

![GitHub](./Images/GitHub.png)

项目源码可以见[本地附录](./OS_and_Linux_HomeWork-main)，或是[GitHub仓库](https://github.com/xxzh12/OS_and_Linux_HomeWork)

## 主要技术点

* 通用技术
  1. TCP通信
  2. 数据头协议编解码

* 客户端
  1. 常用的QT控件
  2. QT信号发送与槽函数实现
  3. QT对Html解析

* 服务器
  1. Epoll实现IO端口复用
  2. 常用STL

* 数据库
  1. MySQL基本操作
  2. QSqlDatabase等类的基本操作

## 界面效果展示

<video id="video" controls="" preload="none"> <source id="mp4" src="./show.mp4" type="video/mp4"> </video>

## 功能说明

### 界面说明

* 图标及应用背景

项目程序编译运行后，应用程序的图标会显示为<img src="./Images/Chats.png" alt="项目图标" style="zoom:25%;" />

登录界面的背景为<img src="./Images/login.jpg" alt="login" style="zoom: 20%;" />

聊天界面的背景为<img src="./Images/backgroud.jpg" alt="background" style="zoom:20%;" />

### 功能说明

* 登陆界面

用户可以通过输入用户名（UserName）和账号（Account），通过点击`login`登录，或者点击`reset`重置已输入的用户名与账号。

* 聊天界面

登录成功后，在聊天窗口的消息界面上方可以看到数条历史消息。输入窗口的上方有一系列用于修改文本格式的按键，其中左侧两个分别用于修改字体和大小，右侧按键`I`可将字体修改为斜体，按键`B`可将字体修改为粗体，按键`U`可为文本添加下划线，按键`Col`可用于修改文本颜色，按键`C`用于清空输入文本，按键`F`点击后可传输文件。聊天窗口的右侧用于显示在线成员列表，下方显示在线成员人数，以及提示当前客户端在线用户的用户名等信息。另有两个功能键`send`和`exit`分别用于发送消息和退出聊天室。

当登录聊天界面时，消息界面的最上方会自动以<font color="#DAA520">金色</font>显示最近五条**消息记录**，并包含相应的消息发送者与发送时间。当有人登录本聊天程序时，消息界面会自动弹出南大紫色彩的提示信息：<font color="#6A006F"> (UserName) login</font>；当有人登出时，消息界面会弹出灰色的提示信息：<font color="#A9A9A9">(UserName) logout</font>。

## 遇到的问题及解决方案

* 为数据添加数据协议头后，处理字符串时意外终止

问题描述：将已处理的字符串打印出来后发现在字符串的头部常出现一些乱码字符，并且无法按照预想读完整条信息，而是往往在数据的头部就已停止读取。

原因判断：考虑到数据头的格式为$Protocol\_id(1\ Byte)+Account(2\ Bytes)+Data\_type(1\ Byte)+Data\_size(4\ Bytes)$，而数据头格式的宏定义如下

```c++
#define BASE_BUFFER_SIZE 8
// size of the protocols
#define PROTOCOL_ID_SIZE 1	
#define ACCOUNT_SIZE 2		
#define DATA_TYPE_SIZE 1	
#define DATA_SIZE 4
// DEFINE of protocol ID
#define LOGIN 1				//0x01
#define SEND 2				//0x02
#define READ 3				//0x03
#define NOTICE 4			//0x04
#define ACK 5				//0x05
#define LOGOUT 6			//0x06
#define REGISTER 7			//0x07
#define ONLINELIST 8		//0x08
#define CLOSE 9				//0x09
// DEFINE of data type
#define TEXT 1				//0x01
#define IMAGE 2				//0x02
#define LOGIN_SUCCESS 0		//0x00
#define LOGIN_FAIL 1		//0x01
#define LOGIN_EXIST 2		//0x02
#define REGISTER_SUCCESS 0	//0x00
#define REGISTER_FAIL 1		//0x01
```

有可能在数据头处提前引入字符串终止符`\0`而导致程序读取字符串时提前终止。

解决方案：在读取、写入字符串等信息时人为指定读取、写入或转换的长度，即$Operate\_Length = Data\_Length+8(Length\ of\ Datahead)$，而不是自动判断字符串的结束位置，这样可以防止读写字符串时出现提前终止的问题。

* 从数据库下载含有二进制格式文件的消息列表时，文件内容损坏

问题描述：当向数据库传输图片等二进制文件后，若从数据库中直接读取此条消息列表再在客户端做进一步解析，会导致文件内容损坏而无法读取

原因解释：文件在数据库中以二进制形式存储，但从数据库以消息列表的形式导出时会将二进制文件格式自动转换为QString类型，而在客户端解析文件内容时还需要将QString类型转换回二进制文件，从而导致文件内容在多次转换过程中损坏。

解决方案：在导出消息时进行类型判断，如果是二进制格式的文件，则在导出消息列表（含有文件上传者、上传时间、文件类型等信息）后再单独以二进制格式导出一次该文件，从而规避类型转换过程中含有的隐患。

## 项目总结

### 项目特色

本项目在课上所讲的TCP通信协议的基础上，基于应用程序开发框架Qt搭建了一套较为完备的聊天室生态。

* 客户端部分采用Qt开发了一个较为优美、流畅的UI界面，并基于Qt的“信号与槽”机制实现了各类消息和文件的发送、接收与显示，同时使用MySQL对消息记录等数据进行管理，保证能够留存有历史消息，并能实现不同客户端之间的流畅交流。服务器端则采用纯C++开发，避免了不必要的UI界面设计，并提高了服务器的可移植性。
* 通过给传输的消息添加数据头的方法，提高了消息类型的多样性，也提高了功能代码的可复用性。本项目目前可传输的消息包括文本消息、登入登出消息、在线成员列表等各类型消息。
* 客户端支持以HTML格式发送文本消息，大大提高了文本消息样式的多样新，如字体、颜色、大小等。
* 本项目全程使用git进行代码管理，在提高项目成员自身代码编写能力的同时也熟悉了git的各类操作，对git代码管理的原理有了更加深入的了解。

### 项目存在的不足

本项目在具体实现过程中仍存在一些不足，例如在传输图片时没能实现在聊天窗口内实时显示图片，而是需要用户到指定路径下根据时间查看相应文件。

### 项目成果

项目源码中包含部分由于思路变化或是用于打印信息而最终被注释掉的代码，代码行数总计约1700+。从4月26日开始项目的调研、分工开始计，项目四人总投入时长约170+h。

[源码附录](./OS_and_Linux_HomeWork-main)


# 人脸识别(考勤)
# 技术涉及
Linux，opencv，百度智能云
# 项目简单描述
基于Linux系统下添加opencv库,使用C++（C++ 11）调用各种借口函数，实现调用摄像头后对其图像进行处理
从而识别出人脸，再接入百度智能云对识别出来的人脸进行分类，实现哪张脸对于哪个人。

# 安装百度AI开放平台 C++ SDK

**C++ SDK目录结构**

    ├── base
    │  ├── base.h                             // 授权相关类
    │  ├── base64.h                           // base64加密类
    │  ├── http.h                             // http请求类
    │  └── utils.h                            // 工具类
    ├── face.h                                // 人脸识别交互类
    ├── image_censor.h                        // 图像审核交互类
    ├── image_classify.h                      // 图像识别交互类
    ├── image_search.h                        // 图像搜索交互类
    ├── kg.h                                  // 人脸识别交互类
    ├── nlp.h                                 // 人脸识别交互类
    ├── ocr.h                                 // 人脸识别交互类
    └── speech.h                              // 语音识别交互类

**支持 C++ 11+**

**直接使用开发包步骤如下：**

1.在[官方网站](http://ai.baidu.com/sdk)下载C++ SDK压缩包。

2.将下载的`aip-cpp-sdk-version.zip`解压, 其中文件为包含实现代码的头文件。

3.安装依赖库curl(需要支持ssl) openssl jsoncpp(>1.6.2版本，0.x版本将不被支持)。

4.编译工程时添加 C++11 支持 (gcc/clang 添加编译参数 -std=c++11), 添加第三方库链接参数 lcurl, lcrypto, ljsoncpp。

5.在源码中include 您需要使用的交互类头文件（face.h image_censor.h image_classify.h kg.h nlp.h ocr.h speech.h等），引入压缩包中的头文即可使用aip命名空间下的类和方法。

# 详细使用文档

参考[百度AI开放平台官方文档](http://ai.baidu.com/docs)

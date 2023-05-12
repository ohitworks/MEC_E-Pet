# MEC_E-Pet

## 项目介绍

电子桌面宠物 (植物版)

1. 电子宠物：距离过近会有反应（超声波），阳光很好的时候会提示天气好该出去走走（光感），关灯会说晚安（光感）
2. 时钟：久坐提示（超声波 + 时钟）、提示不要熬夜（时钟）
3. 提醒浇水（土壤湿度）

| **Tags**     |                              |
| ------------ | ---------------------------- |
| **美观**     | 好看！                       |
| **人机交互** | 显示屏，按键交互             |
| **物联网**   | 与桌面设备互联               |
| **环保**     | 识别到用户不在桌前，自动待机 |
| **生活助手** | 备忘录，久坐提醒，时钟……     |
| **方便**     | 插入花盆即可使用             |
| **安全**     | 异常声响激活并发送提示       |

```text
                         _ _ _ _ _ _ _ _ _  
                        /                 \ 
        /+ - - +        |                 | 
    +==/ | LED |        |                 | 
\   |   /+ - - +        |                 | 
 |  |  |                |                 | 
 | {=} |                \_ _ _ _ _ _ _ _ _/ 
 |  |  |                        + +         
 \_____/                      =======       

```

- 开发板

  - Ardunio UNO

- 传感器:

  - 超声波测距传感器 

  - 温度传感器

  - 紫外线传感器

  - 红外传感器

  - 声音模块

  - 屏幕 (可以展示颜文字)

  - 土壤湿度传感器

  - 生物心电传感器

- 面包板

### 应用场景: 

当你回到房间坐下，LED 屏亮起，你的桌面小猫/小狗带来了温馨的问候。你挥手，电子宠物跑开，显示了你在学校用手机写下的今日事项清单。打开显示器，这时电脑已被自动唤醒，无聊的开机时间在桌面宠物的陪伴中不知不觉过去了。

阅读学术论文时，枯燥中你不知不觉间神游天外。桌面宠物发现你许久没有翻页，便悄悄出现，闪烁的 LED 灯光打断你的注意，并提醒你已经久坐，应该站起身运动。

(还在编)

## 项目目标

项目功能:

- 屏幕
  - 屏幕模块
- 靠近检测
  - 红外传感器
  - 超声波传感器
- 阳光检测
  - 紫外线传感器
- 温度提醒
  - 温度传感器 (是不是需要特殊的结构)
- 声音模块
  - 发声

程序功能:

- 硬件驱动和功能集成
- 屏幕显示控制(消息处理)
- 计数器中断们

## 开发者

[**oh it works**](https://www.github.com/ohitworks)

[**1cas**](https://github.com/1cas)

[**Minghao Wang**](https://github.com/Double-Shark)

[**YanzhangWang**](https://github.com/YanzhangWang)

## 任务分配和时间线

4/28 ~ 5/5:

> Warning:  EAP 口语考试

- [x] Arduino 串口数据打印 @YanzhangWang

  相关资料:

  - [官方资料](https://www.arduino.cc/reference/en/language/functions/communication/serial/println/)

  - [Arduino-串口函数Serial](https://www.cnblogs.com/gaosheng-221/p/6641060.html)

- [x] 紫外线驱动 @Minghao Wang

- [x] 红外线驱动 @YanzhangWang

- [x] 超声波驱动 @1cas

- [x] 点亮屏幕 @oh it works

- [x] 消息控制流程 @oh it works

- [x] 布线图 @oh it works

@YanzhangWang

- [x] 土壤湿度传感器
- [x] 语音传感器

5/5 ~ 5/12:

- [x] 表情包(大小: 128x64)(太阳, Smile, Sad, Water) 类型为 bitmap @YanzhangWang
- [x] 土壤传感器消息发送 @YanzhangWang
- [x] 红外线传感器消息发送 @YanzhangWang
- [ ] git 操作教程 @1cas @YanzhangWang
- [ ] 项目 Arduino 创建文档 @1cas @oh it works
- [x] 超声波传感器消息发送 @1cas
- [ ] 完成消息库代码以及文档 @oh it works
- [x] 紫外线传感器消息发送 @Minghao Wang
- [x] Report Building (5/12 together)

5/13:

- [ ] 拍摄视频
- [ ] 更新文档

- [ ] Finish Report

## 工具链

开发软件:

- Arduino
- CLion

做图软件 (网站):

- [draw.io](https://draw.io)
- [tinkercad.com](https://www.tinkercad.com/)
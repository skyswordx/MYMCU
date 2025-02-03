# 裸机系统架构

事件驱动型状态机 `event-drive-state-machine`
- [xiaoliang314/eventRTOS: 一个无栈的纯事件驱动的带优先级抢占的实时OS (github.com)](https://github.com/xiaoliang314/eventRTOS)

多定时器调度

时间片轮询

# 实时操作系统

## 作者 ：感动自己  

链接：https://www.zhihu.com/question/438340661/answer/3943714038  
来源：知乎  
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。  
  

1）系统框架。[freertos](https://zhida.zhihu.com/search?content_id=692073847&content_type=Answer&match_order=1&q=freertos&zhida_source=entity)或者rtthread。一个框架，最重要的就是资源要丰富、用户要多，小众的rtos不推荐，除非是安全相关的产品，那么需要额外付费。我个人使用freertos配合tracealyzer开发，非常高效

2）单片机的ui框架，我是用lvgl，直接代码编写，没啥说的，免费，外加有很多工具如果你想用也能用（譬如[nxp](https://zhida.zhihu.com/search?content_id=692073847&content_type=Answer&match_order=1&q=nxp&zhida_source=entity)的gui guider）。当然，[stm32](https://zhida.zhihu.com/search?content_id=692073847&content_type=Answer&match_order=1&q=stm32&zhida_source=entity)资源有限，非必要不要弄ui。

3）控制框架，如果做实时控制，那么就是matlab或者[simulink](https://zhida.zhihu.com/search?content_id=692073847&content_type=Answer&match_order=1&q=simulink&zhida_source=entity)的mbd代码生成，以及[stateflow](https://zhida.zhihu.com/search?content_id=692073847&content_type=Answer&match_order=1&q=stateflow&zhida_source=entity)做状态机。

4）开发分离思路，你可以弄个[bootloader](https://zhida.zhihu.com/search?content_id=692073847&content_type=Answer&match_order=1&q=bootloader&zhida_source=entity)，把rtos和单片机启动做好分离。然后在rtos里，设计一个程序动态加载的task，这样就可以实现APP和系统的分离设计。

4.1）应用层app开发可以用任何ide都行，采用相对地址编译出bin文件，可在任意内存段进行app在线加载运行。

5）如果是中断服务程序或者是需求高性能的应用程序，就不建议动态加载，而是采用注册机制，事先约定好函数入口地址。编译采用固定地址编译即可。单独烧录程序到flash后，单片机起电自动识别相关程序是否存在，若存在，就注册中断程序，在中断内，根据注册情况决定是否跳转。

以上整体实现的就是一个比较完善的裸机系统。具有 [ota](https://zhida.zhihu.com/search?content_id=692073847&content_type=Answer&match_order=1&q=ota&zhida_source=entity)、在线烧录、在线下载和动态运行程序等功能，同时完成中断等实时控制（比如平衡车的平衡控制）。

## 
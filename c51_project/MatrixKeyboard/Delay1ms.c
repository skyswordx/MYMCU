#include <INTRINS.H>

//#################################################################################
//##
//##                                        演示延时函数
//##
//#################################################################################
void Delay1ms( unsigned int Xms){   
    //使用某个软件，根据特定单片机开发板上的晶振频率，生成的相应的延时函数
    //这是@11.0592MHz的延时1ms函数
    //利用写死的延迟1ms，传入Xms参数进行给定次的循环，实现任意个以1ms为单位的延迟函数
    unsigned char i, j; 
    while(Xms){
        _nop_();
        _nop_();
        _nop_();
        i = 11;
        j = 190;
        do{
            while (--j);
        } while (--i);
        --Xms;
    }
}
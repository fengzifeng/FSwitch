//
//  MacroToolHeader.h
//  FSwitch
//
//  Created by fengzifeng on 16/6/8.
//  Copyright © 2016年 fengzifeng. All rights reserved.
//


#ifndef HLMagic_MacroToolHeader_h
#define HLMagic_MacroToolHeader_h

//#ifdef DEBUG
//#define FLOG(fmt,...)    NSLog((@"[%@][%d] " fmt),[[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__,##__VA_ARGS__)
//#else
//#define FLOG(str, args...) ((void)0)
//#endif


#define IS_IPAD              (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE            (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define SCREEN_HEIGHT        ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_WIDTH         ([[UIScreen mainScreen] bounds].size.width)
#define WINDOW_MAX_LENGTH    (MAX(WINDOW_WIDTH, WINDOW_HEIGHT))

#define IS_IPHONE_4          (IS_IPHONE && WINDOW_MAX_LENGTH < 568.0)
#define IS_IPHONE_5          (IS_IPHONE && WINDOW_MAX_LENGTH == 568.0)
#define IS_IPHONE_6          (IS_IPHONE && WINDOW_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P         (IS_IPHONE && WINDOW_MAX_LENGTH == 736.0)


#define ShortSystemVersion   [[UIDevice currentDevice].systemVersion floatValue]
#define IS_IOS_6             (ShortSystemVersion < 7)
#define IS_IOS_7             (ShortSystemVersion >= 7 && ShortSystemVersion < 8)
#define IS_IOS_8             (ShortSystemVersion >= 8)

#define radians(degrees)     ((degrees)*M_PI/180.0f)


#define userDefaults        [NSUserDefaults standardUserDefaults]
#define KeyWindow           [[[UIApplication sharedApplication] delegate] window]
#define WindowZoomScale     (WINDOW_WIDTH/320.f)
#define UniversalZoomScale  (MIN(1.8, WindowZoomScale))  //适配iPad

#define DocumentPath        [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]    //获取Document文件夹的路径
#define ResourcePath        [[NSBundle mainBundle] resourcePath]    //获取自定义文件的bundle路径
#define ImageNamed(name)    [UIImage imageWithContentsOfFile:[ResourcePath stringByAppendingPathComponent:name]]
#define RGBCOLOR(r,g,b)     [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]         //RGB进制颜色值
#define RGBACOLOR(r,g,b,a)  [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]       //RGBA进制颜色值
#define HexColor(hexValue)  [UIColor colorWithRed:((float)(((hexValue) & 0xFF0000) >> 16))/255.0 green:((float)(((hexValue) & 0xFF00) >> 8))/255.0 blue:((float)((hexValue) & 0xFF))/255.0 alpha:1]   //16进制颜色值，如：#000000 , 注意：在使用的时候hexValue写成：0x000000

#define ThemColor            HexColor(0x096096)


#define kFont_10 [UIFont systemFontOfSize:10]
#define kFont_11 [UIFont systemFontOfSize:11]
#define kFont_12 [UIFont systemFontOfSize:12]
#define kFont_13 [UIFont systemFontOfSize:13]
#define kFont_14 [UIFont systemFontOfSize:14]
#define kFont_15 [UIFont systemFontOfSize:15]
#define kFont_16 [UIFont systemFontOfSize:16]
#define kFont_17 [UIFont systemFontOfSize:17]
#define kFont_18 [UIFont systemFontOfSize:18]
#define kFont_19 [UIFont systemFontOfSize:19]
#define kFont_20 [UIFont systemFontOfSize:20]
#define kFont_21 [UIFont systemFontOfSize:21]

//获取随机数
#define Random(from, to) (int)(from + (arc4random() % (to - from + 1))); //+1,result is [from to]; else is [from, to)!!!!!!!
#define ARC4RANDOM_MAX (0x100000000 * 20)



#endif

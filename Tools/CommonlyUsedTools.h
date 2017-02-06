//
//  CommonlyUsedTools.h
//  CategoryTest
//
//  Created by ZHS on 2017/2/4.
//  Copyright © 2017年 ZHS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CommonlyUsedTools : NSObject

/// 常用工具类 初始化
+ (CommonlyUsedTools *)shareInstance;

/// 正则匹配邮箱号
+ (BOOL)checkMailInput:(NSString *)mail;

/// 正则匹配手机号
+ (BOOL)checkTelNumber:(NSString *)telNumber;

/// 正则匹配用户密码6-18位数字和字母组合
+ (BOOL)checkPassword:(NSString *)password;

@end

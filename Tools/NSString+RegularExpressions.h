//
//  NSString+RegularExpressions.h
//  CategoryTest
//
//  Created by ZHS on 2017/2/4.
//  Copyright © 2017年 ZHS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (RegularExpressions)

/// 是否是QQ号
- (BOOL)isQQ;
    
/// 是否是手机号
- (BOOL)isPhoneNumber;
    
/// IP地址是否正确
- (BOOL)isIPAddress;
    
@end

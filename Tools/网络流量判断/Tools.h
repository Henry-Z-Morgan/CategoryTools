//
//  Tools.h
//  ActiveFeedbackTest
//
//  Created by 左恒松 on 2017/2/21.
//  Copyright © 2017年 左恒松. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Tools : NSObject

// 用的是苹果的API来判断的网络状态
+ (NSString *)getNetWorkType;

// 用的是导航栏上的网络状态
+ (NSString *)getNetWorkStates;


//
//NSString *str = [Tools getNetWorkStates];
//
//NSLog(@"function : %s line : %d getNetWorkStates : %@",__func__,__LINE__,str);
//
//NSString *str1 = [Tools getNetWorkType];
//
//NSLog(@"function : %s line : %d getNetWorkType : %@",__func__,__LINE__,str1);



@end

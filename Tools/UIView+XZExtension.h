//
//  UIView+XZExtension.h
//  CategoryTest
//
//  Created by ZHS on 2017/2/6.
//  Copyright © 2017年 ZHS. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (XZExtension)

///设置 x 坐标
@property (nonatomic, assign) CGFloat x;
/// 设置 y 坐标
@property (nonatomic, assign) CGFloat y;
/// 设置 宽度
@property (nonatomic, assign) CGFloat width;
/// 设置 高度
@property (nonatomic, assign) CGFloat height;
/// 设置 size
@property (nonatomic, assign) CGSize size;
/// 设置 origin
@property (nonatomic, assign) CGPoint origin;

@end

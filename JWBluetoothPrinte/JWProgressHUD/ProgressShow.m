//
//  ProgressShow.m
//  JWBluetoothPrinte
//
//  Created by 张竟巍 on 2017/6/14.
//  Copyright © 2017年 张竟巍. All rights reserved.
//

#import "ProgressShow.h"
#import "MBProgressHUD.h"

@implementation ProgressShow


+(void)alertView:(UIView *)view Message:(NSString*)msg cb:(ALertCompletion) completion{
    MBProgressHUD *HUD = (MBProgressHUD *)[view viewWithTag:8012];
    if(!HUD){
        HUD =  [[MBProgressHUD alloc] initWithView:view];
        
        HUD.tag = 8012;
        HUD.mode = MBProgressHUDModeText;
        [view addSubview:HUD];
        HUD.removeFromSuperViewOnHide = YES;
        HUD.contentColor = [UIColor whiteColor];
        HUD.bezelView.color = [UIColor blackColor];
    }
    HUD.label.text = msg;
    [HUD showAnimated:YES];
    HUD.completionBlock = ^{
        if(completion){
            completion(YES);
        }
    };
    dispatch_async(dispatch_get_main_queue(), ^{
        [HUD hideAnimated:YES afterDelay:1.5f];
    });
    
}

+ (NSString *)getBluetoothErrorInfo:(CBManagerState)status{
    NSString * tempStr = @"未知错误";
    switch (status) {
        case CBManagerStateUnknown:
            tempStr = @"未知错误";
            break;
        case CBManagerStateResetting:
            tempStr = @"正在重置";
            break;
        case CBManagerStateUnsupported:
            tempStr = @"设备不支持蓝牙";
            break;
        case CBManagerStateUnauthorized:
            tempStr = @"蓝牙未被授权";
            break;
        case CBManagerStatePoweredOff:
            tempStr = @"蓝牙关闭";
            break;
        default:
            break;
    }
    return tempStr;
}

@end

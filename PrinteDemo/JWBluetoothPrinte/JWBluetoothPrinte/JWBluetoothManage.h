//
//  JWBluetoothManage.h
//  JWBluetoothPrinte
//
//  Created by 张竟巍 on 2017/6/14.
//  Copyright © 2017年 张竟巍. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWBluetoothBlocks.h"
#import "ProgressShow.h"
#import "JWPrinter.h"


@interface JWBluetoothManage : NSObject
//单例方法
+ (instancetype)sharedInstance;

@property (nonatomic, strong,readonly)CBPeripheral                *connectedPerpheral;    //  当前连接的外设蓝牙

/**
 开始扫描蓝牙外设，block方式返回结果
 @param success 扫描成功的回调
 @param failure 扫描失败的回调
 
 */
- (void)beginScanPerpheralSuccess:(JWScanPerpheralsSuccess)success failure:(JWScanPeripheralFailure)failure;

/**
 连接蓝牙外设，连接成功后会停止扫描蓝牙外设，block方式返回结果
 
 @param peripheral 要连接的蓝牙外设
 @param completion 连接成功回调(有成功 跟失败判断error是否为空就可以了)
 */
- (void)connectPeripheral:(CBPeripheral *)peripheral completion:(JWConnectPeripheralCompletion)completion;

/**
 自动连接上次连接的蓝牙
 //因为使用自动连接的话同样也会扫描设备  所以如果单一只是想要连接外设，用此API就可以了

 @param completion 连接成功回调(有成功 跟失败判断error是否为空就可以了)
 */
- (void)autoConnectLastPeripheralCompletion:(JWConnectPeripheralCompletion)completion;

/**
  需要判断JWScanStage来进行打印，如果只是连接 不需要关心，
 */
@property (nonatomic, assign) JWScanStage stage;

/**
 断开连接的block
 */
@property (nonatomic, copy) JWDisconnectPeripheralBlock disConnectBlock;


/**
 停止扫描设备
 */
- (void)stopScanPeripheral;

/**
 取消某个设备的连接

 @param peripheral 设备
 */
- (void)cancelPeripheralConnection:(CBPeripheral *)peripheral;

/**
 进行打印

 @param data 打印数据
 @param result 结果回调
 */
- (void)sendPrintData:(NSData *)data completion:(JWPrintResultBlock)result;


@end

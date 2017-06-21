//
//  JWBluetoothBlocks.h
//  JWBluetoothPrinte
//
//  Created by 张竟巍 on 2017/6/14.
//  Copyright © 2017年 张竟巍. All rights reserved.
//
#import <CoreBluetooth/CoreBluetooth.h>
#ifndef JWBluetoothBlocks_h
#define JWBluetoothBlocks_h

// 打印流程:   搜索蓝牙外设 -->连接蓝牙  -->搜索服务 -->搜索特性 -->写入数据 -->打印成功
// 连接上打印机，需要判断扫描的阶段，如果直接进行打印会有可能导致 没有搜索到特性阶段，调用打印API是打印不成功的，所以等待特性回调之后打印 万无一失

typedef NS_ENUM(NSInteger, JWScanStage) {
    JWScanStageConnection = 0,            //蓝牙连接阶段
    JWScanStageServices,             //服务阶段
    JWScanStageCharacteristics,     //特性阶段   //注意  只有到达特性阶段才能进行打印
};


/**
 蓝牙外设扫描结束成功之后的block

 @param peripherals 蓝牙外设列表
 @param rssis 蓝牙信号强度
 */
typedef void(^JWScanPerpheralsSuccess)(NSArray<CBPeripheral *> *peripherals,NSArray<NSNumber *> *rssis);

/**
 扫描失败的block
 @param status 失败的枚举  CBManagerStatePoweredOn 是正常使用的
 */
typedef void(^JWScanPeripheralFailure)(CBManagerState status);

/**
 连接完成的block
 @param perpheral 要连接的蓝牙外设
 */
typedef void(^JWConnectPeripheralCompletion)(CBPeripheral *perpheral, NSError *error);


/**
 蓝牙断开连接
 @param perpheral 蓝牙外设
 @param error        错误
 */
typedef void(^JWDisconnectPeripheralBlock)(CBPeripheral *perpheral, NSError *error);


/**
 打印之后回调

 @param completion 是否完成打印
 @param peripheral 外设
 @param errorString 出错的原因
 */
typedef void(^JWPrintResultBlock)(BOOL completion, CBPeripheral *peripheral,NSString * errorString);



#endif /* JWBluetoothBlocks_h */

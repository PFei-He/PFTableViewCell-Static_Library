//
//  RootModel.h
//  PFTableViewCell
//
//  Created by PFei_He on 14-11-15.
//  Copyright (c) 2014年 PFei_He. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RootModel : NSObject <UITableViewDataSource, UITableViewDelegate>

/**
 *  @brief 初始化
 *  @param imageArray: 图片数组
 *  @param nameArray: 姓名数组
 */
- (id)initWithImageArray:(NSArray *)imageArray nameArray:(NSArray *)nameArray;

/**
 *  @brief 设置列表
 */
- (void)setupTableView:(UITableView *)tableView;

@end

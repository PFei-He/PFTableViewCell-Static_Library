//
//  RootVC.m
//  PFTableViewCell
//
//  Created by PFei_He on 14-11-12.
//  Copyright (c) 2014年 PFei_He. All rights reserved.
//

#import "RootVC.h"
#import "DetailVC.h"
#import "RootModel.h"

@interface RootVC ()

@property (nonatomic, strong) RootModel *root;

@end

@implementation RootVC

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

#pragma mark - View Management

- (void)viewDidLoad
{
    [super viewDidLoad];

    //标题
    self.title = @"个人资料";
    
    //设置列表
    [self setupTableView];
}

//设置列表
- (void)setupTableView
{
    //图片数组
    NSArray *imageArray = @[@"images.bundle/belle_1", @"images.bundle/belle_2", @"images.bundle/belle_3", @"images.bundle/belle_4", @"images.bundle/belle_5"];
    
    //姓名数组
    NSArray *nameArray = @[@"美美", @"小珍", @"李丽", @"嘉欣", @"绮梦"];
    
    //列表视图
    UITableView *tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, 320, self.view.frame.size.height)];
    [self.view addSubview:tableView];
    
    //模型
    self.root = [[RootModel alloc] initWithImageArray:imageArray nameArray:nameArray];
    //传入列表视图
    [self.root setupTableView:tableView];
}

#pragma mark - Memory Management

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
 #pragma mark - Navigation

 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
 {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

@end

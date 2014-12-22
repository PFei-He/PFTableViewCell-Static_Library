//
//  DetailVC.m
//  Demo
//
//  Created by PFei_He on 14-12-3.
//  Copyright (c) 2014年 PF-Lib. All rights reserved.
//

#import "DetailVC.h"
#import "DetailModel.h"
#import "PFTableViewCell.h"

@interface DetailVC ()

@property (nonatomic, strong) DetailModel *detail;

@end

@implementation DetailVC

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.title = @"2";
    self.view.backgroundColor = [UIColor whiteColor];

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
    self.detail = [[DetailModel alloc] initWithImageArray:imageArray nameArray:nameArray];

    //传入列表视图
    [self.detail setupTableView:tableView];
}

#pragma mark - Memory Management

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc
{
    //移除高度设定
    [PFTableViewCell removeAllHeightSettings];
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

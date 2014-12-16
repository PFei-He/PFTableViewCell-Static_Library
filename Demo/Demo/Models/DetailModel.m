//
//  DetailModel.m
//  Demo
//
//  Created by PFei_He on 14-12-3.
//  Copyright (c) 2014年 PF-Lib. All rights reserved.
//

#import "DetailModel.h"
#import "PFTableViewCell.h"
#import "PFImageBrowser.h"

@interface DetailModel ()
{
    CGFloat cellModelOneHeight; //模型一高度
    CGFloat cellModelTwoHeight; //模型二高度
}

///图片数组
@property (nonatomic, strong) NSArray       *imageArray;

///姓名数组
@property (nonatomic, strong) NSArray       *nameArray;

///列表视图
@property (nonatomic, strong) UITableView   *tableView;

@end

@implementation DetailModel

#pragma mark - Initialization

//初始化
- (id)initWithImageArray:(NSArray *)imageArray nameArray:(NSArray *)nameArray
{
    self = [super init];
    if (self) {
        //图片数组
        self.imageArray = imageArray;

        //姓名数组
        self.nameArray = nameArray;

        //模型一高度
        cellModelOneHeight = 80;

        //模型二高度
        cellModelTwoHeight = 200;
    }
    return self;
}

#pragma mark - Private Methods

//设置列表
- (void)setupTableViewCell:(PFTableViewCell *)cell indexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row %2 == 0) {
        //设置背景
        cell.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"images.bundle/cell_even_background" ofType:@"jpg"]]];

        //设置内容页
        cell.firstContentViewShow = YES;
        cell.firstContentView.frame = CGRectMake(0, 45, 320, 30);
        cell.firstContentView.backgroundColor = [UIColor cyanColor];

        //设置图片
        cell.firstImageViewShow = YES;
        cell.firstImageView.frame = CGRectMake(5, 15, 60, 60);
        cell.firstImageView.userInteractionEnabled = YES;
        [cell setRoundedImageView:cell.firstImageView];
        [cell imageViewTouchUsingBlock:^(PFTableViewCell *tableViewCell, NSIndexPath *indexPath, NSInteger controlIndex) {
            NSLog(@"One");
            NSLog(@"%d", indexPath.row);

            //浏览大图
            [PFImageBrowser showImage:tableViewCell.firstImageView];
        }];
    } else {
        //设置背景
        cell.backgroundColor = [UIColor colorWithRed:255 / 255.0f green:180 / 255.0f blue:190 / 255.0f alpha:1];

        //设置按钮
        cell.firstButtonShow = YES;
        [cell.firstButton setTitle:@"更多" forState:UIControlStateNormal];
        [cell.firstButton setTitleColor:[UIColor cyanColor] forState:UIControlStateNormal];
        [cell buttonTouchUsingBlock:^(PFTableViewCell *tableViewCell, NSIndexPath *indexPath, NSInteger controlIndex) {
            NSLog(@"One");
            NSLog(@"%d", indexPath.row);

            //刷新列表
            PFTableViewCellReload = YES;
            [PFTableViewCell setHeight:500 atIndexPath:indexPath];
            [self.tableView reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationNone];
        }];
    }
    //设置分割线
    cell.lineShow = YES;
    cell.lineColor = [UIColor orangeColor];
}

#pragma mark - Public Methods

//设置列表视图
- (void)setupTableView:(UITableView *)tableView
{
    self.tableView = tableView;
    self.tableView.separatorStyle = NO;
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
}

#pragma mark - UITableViewDataSource

//设置每个分层的列表数
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    //设置总数
    [PFTableViewCell heightSettingsCount:self.imageArray.count * 2];

    return self.imageArray.count * 2;
}

//设置列表
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *cellIdentifier;
    if (indexPath.row % 2 == 0) cellIdentifier = @"cellIdentifierModelOne";
    else cellIdentifier = @"cellIdentifierModelTwo";
    PFTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (!cell) {
        CGSize size = CGSizeMake(320, indexPath.row %2 == 0 ? cellModelOneHeight : cellModelTwoHeight);
        cell = [[PFTableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier delegate:nil size:size];

        [self setupTableViewCell:cell indexPath:indexPath];
    }

    //设置序号
    cell.indexPath = indexPath;

    //设置按钮
    cell.firstButton.frame = CGRectMake(cell.bounds.size.width - 65, cell.bounds.size.height - 35, 60, 30);

    //设置图片
    cell.firstImageView.image = [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@", self.imageArray[indexPath.row / 2]] ofType:@"png"]];

    //设置分割线
    cell.lineFrame = CGRectMake(0, cell.bounds.size.height - 1, cell.bounds.size.width, 1.0f);

    return cell;
}

#pragma mark - UITableViewDelegate

//设置高度
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([PFTableViewCell heightAtIndexPath:indexPath]) {

        //获取高度
        return [PFTableViewCell heightAtIndexPath:indexPath];
    } else {
        if (indexPath.row %2 == 0) {
            //设置高度
            [PFTableViewCell setHeight:80 atIndexPath:indexPath];
            return 80;
        } else {
            //设置高度
            [PFTableViewCell setHeight:200 atIndexPath:indexPath];
            return 200;
        }
    }
}

//点击事件
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSLog(@"点击事件已经发生");
}

@end

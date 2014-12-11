//
//  RootVC.m
//  Demo
//
//  Created by PFei_He on 14-12-3.
//  Copyright (c) 2014年 PF-Lib. All rights reserved.
//

#import "RootVC.h"
#import "DetailVC.h"

@interface RootVC ()

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

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.title = @"1";
    self.view.backgroundColor = [UIColor whiteColor];

    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    button.frame = CGRectMake(120, 100, 80, 30);
    [button setTitle:@"点击" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(buttonTouch) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}

- (void)buttonTouch
{
    DetailVC *detail = [[DetailVC alloc] init];
    [self.navigationController pushViewController:detail animated:YES];
}

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

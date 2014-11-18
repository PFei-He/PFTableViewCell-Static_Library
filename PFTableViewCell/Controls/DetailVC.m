//
//  DetailVC.m
//  PFTableViewCell
//
//  Created by PFei_He on 14-11-12.
//  Copyright (c) 2014年 PFei_He. All rights reserved.
//

#import "DetailVC.h"
#import "PFTableViewCell.h"

@interface DetailVC () <UITableViewDelegate>

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

#pragma mark - Views Management

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.title = @"细节";
    self.view.backgroundColor = [UIColor whiteColor];
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

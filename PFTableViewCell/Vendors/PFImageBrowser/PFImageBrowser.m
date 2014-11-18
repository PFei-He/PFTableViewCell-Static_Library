//
//  PFImageBrowser.m
//  PFTableViewCell
//
//  Created by PFei_He on 14-11-12.
//  Copyright (c) 2014年 PFei_He. All rights reserved.
//

#import "PFImageBrowser.h"

static CGRect oldFrame;

@implementation PFImageBrowser

+ (void)showImage:(UIImageView *)oldImageView
{
    UIWindow *window = [UIApplication sharedApplication].keyWindow;
    UIView *backgroundView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
    oldFrame = [oldImageView convertRect:oldImageView.bounds toView:window];
    backgroundView.backgroundColor = [UIColor blackColor];
    backgroundView.alpha = 0;
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:oldFrame];
    imageView.image = oldImageView.image;
    imageView.tag = 1;
    [backgroundView addSubview:imageView];
    [window addSubview:backgroundView];

    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(hideImage:)];
    [backgroundView addGestureRecognizer:tap];

    [UIView animateWithDuration:0.3 animations:^{
        imageView.frame = CGRectMake(0, ([UIScreen mainScreen].bounds.size.height - oldImageView.image.size.height * [UIScreen mainScreen].bounds.size.width / oldImageView.image.size.width) / 2, [UIScreen mainScreen].bounds.size.width, oldImageView.image.size.height * [UIScreen mainScreen].bounds.size.width / oldImageView.image.size.width);
        backgroundView.alpha = 1;
    } completion:^(BOOL finished) {

    }];
}

+ (void)hideImage:(UITapGestureRecognizer *)tap
{
    UIView *backgroundView = tap.view;
    UIImageView *imageView = (UIImageView*)[tap.view viewWithTag:1];
    [UIView animateWithDuration:0.3 animations:^{
        imageView.frame = oldFrame;
        backgroundView.alpha = 0;
    } completion:^(BOOL finished) {
        [backgroundView removeFromSuperview];
    }];
}

@end

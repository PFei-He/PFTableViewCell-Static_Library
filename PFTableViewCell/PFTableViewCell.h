//
//  PFTableViewCell.h
//  PFTableViewCell
//
//  Created by PFei_He on 14-11-12.
//  Copyright (c) 2014年 PF-Lib. All rights reserved.
//
//  https://github.com/PFei-He/PFTableViewCell-Static_Library
//
//  vesion: 0.3.3
//

#import <UIKit/UIKit.h>

/**
 *  强弱引用转换，用于解决代码块（block）与强引用self之间的循环引用问题
 *  调用方式: `@weakify_self`实现弱引用转换，`@strongify_self`实现强引用转换
 *
 *  示例：
 *  @weakify_self
 *  [obj block:^{
 *  @strongify_self
 *      self.property = something;
 *  }];
 */
#ifndef	weakify_self
    #if __has_feature(objc_arc)
        #define weakify_self autoreleasepool{} __weak __typeof__(self) weakSelf = self;
    #else
        #define weakify_self autoreleasepool{} __block __typeof__(self) blockSelf = self;
    #endif
#endif
#ifndef	strongify_self
    #if __has_feature(objc_arc)
        #define strongify_self try{} @finally{} __typeof__(weakSelf) self = weakSelf;
    #else
        #define strongify_self try{} @finally{} __typeof__(blockSelf) self = blockSelf;
    #endif
#endif

/**
 *  强弱引用转换，用于解决代码块（block）与强引用对象之间的循环引用问题
 *  调用方式: `@weakify(object)`实现弱引用转换，`@strongify(object)`实现强引用转换
 *
 *  示例：
 *  @weakify(object)
 *  [obj block:^{
 *      @strongify(object)
 *      strong_object = something;
 *  }];
 */
#ifndef	weakify
    #if __has_feature(objc_arc)
        #define weakify(object)	autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
    #else
        #define weakify(object)	autoreleasepool{} __block __typeof__(object) block##_##object = object;
    #endif
#endif
#ifndef	strongify
    #if __has_feature(objc_arc)
        #define strongify(object) try{} @finally{} __typeof__(object) strong##_##object = weak##_##object;
    #else
        #define strongify(object) try{} @finally{} __typeof__(object) strong##_##object = block##_##object;
    #endif
#endif

@class PFTableViewCell;

@protocol PFTableViewCellDelegate <NSObject>

@optional

/**
 *  @brief 加载完成
 *  @param indexPath: 列表序号
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell loadedAtIndexPath:(NSIndexPath *)indexPath;

/**
 *  @brief 被选中
 *  @param indexPath: 列表序号
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell selectedAtIndexPath:(NSIndexPath *)indexPath;

/**
 *  @brief 按钮点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell buttonTouchAtIndexPath:(NSIndexPath *)indexPath controlIndex:(NSInteger)controlIndex;

/**
 *  @brief 图片点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 *  @waring 若要使用此方法，请将视图的用户交互打开（设置属性`***.userInteractionEnabled = YES;`）
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell imageViewTouchAtIndexPath:(NSIndexPath *)indexPath controlIndex:(NSInteger)controlIndex;

/**
 *  @brief 文本点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 *  @waring 若要使用此方法，请将视图的用户交互打开（设置属性`***.userInteractionEnabled = YES;`）
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell textLabelTouchAtIndexPath:(NSIndexPath *)indexPath controlIndex:(NSInteger)controlIndex;

@end

/**
 *  @brief 是否重新加载列表
 *  @warning 若要动态设置列表高度，在刷新列表时将该参数设置为YES
 */
extern BOOL PFTableViewCellReload;

@interface PFTableViewCell : UITableViewCell

#pragma mark - Base

///序号
@property (nonatomic, strong)           NSIndexPath     *indexPath;

#pragma mark - View

///是否显示分割线
@property (nonatomic, assign)           BOOL            lineShow;

///分割线尺寸
@property (nonatomic, assign)           CGRect          lineFrame;

///分割线颜色（默认为浅灰色）
@property (nonatomic, strong)           UIColor         *lineColor;

#pragma mark -

///是否显示内容页
@property (nonatomic, assign)           BOOL            firstContentViewShow;

///内容页
@property (nonatomic, strong, readonly) UIView          *firstContentView;

#pragma mark -

///是否显示内容页
@property (nonatomic, assign)           BOOL            secondContentViewShow;

///内容页
@property (nonatomic ,strong, readonly) UIView          *secondContentView;

#pragma mark - Button

///是否显示按钮（type: custom）
@property (nonatomic, assign)           BOOL            firstButtonShow;

///按钮
@property (nonatomic, strong, readonly) UIButton        *firstButton;

#pragma mark -

///是否显示按钮（type: custom）
@property (nonatomic, assign)           BOOL            secondButtonShow;

///按钮
@property (nonatomic, strong, readonly) UIButton        *secondButton;

#pragma mark - Image

///是否显示图片
@property (nonatomic, assign)           BOOL            firstImageViewShow;

///图片视图
@property (nonatomic, strong, readonly) UIImageView     *firstImageView;

#pragma mark -

///是否显示图片
@property (nonatomic, assign)           BOOL            secondImageViewShow;

///图片视图
@property (nonatomic, strong, readonly) UIImageView     *secondImageView;

#pragma mark - Label

///是否显示文本
@property (nonatomic, assign)           BOOL            firstTextLabelShow;

///文本视图
@property (nonatomic, strong, readonly) UILabel         *firstTextLabel;

#pragma mark -

///是否显示文本
@property (nonatomic, assign)           BOOL            secondTextLabelShow;

///文本视图
@property (nonatomic, strong, readonly) UILabel         *secondTextLabel;

#pragma mark - Methods

/**
 *  @brief 初始化
 *  @param delegate: 代理（使用块方法时设为nil）
 *  @param size: 尺寸
 */
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier delegate:(id<PFTableViewCellDelegate>)delegate size:(CGSize)size;

/**
 *  @brief 设置圆形图片
 */
- (void)setRoundedImageView:(UIImageView *)imageView;

/**
 *  @brief 设置圆形图片
 *  @param borderWidth: 边框宽度
 *  @param borderColor: 边框颜色
 */
- (void)setRoundedImageView:(UIImageView *)imageView borderWidth:(CGFloat)borderWidth borderColor:(UIColor *)borderColor;

#pragma mark -

/**
 *  @brief 设置总数
 */
+ (void)heightSettingsCount:(NSInteger)count;

/**
 *  @brief 获取高度
 *  @param indexPath: 列表序号
 */
+ (CGFloat)heightAtIndexPath:(NSIndexPath *)indexPath;

/**
 *  @brief 设置高度
 *  @param height: 高度
 *  @param indexPath: 列表序号
 */
+ (void)setHeight:(CGFloat)height atIndexPath:(NSIndexPath *)indexPath;

/**
 *  @brief 重设高度（该方法暂未开放，请勿使用）
 *  @param onsetHeight: 起始高度
 *  @param resetHeight: 重置高度
 *  @param indexPath: 列表序号
 */
//+ (void)onsetHeight:(CGFloat)onsetHeight resetHeight:(CGFloat)resetHeight atIndexPath:(NSIndexPath *)indexPath;

/**
 *  @brief 移除高度设置
 */
+ (void)removeAllHeightSettings;

#pragma mark -

/**
 *  @brief 加载完成
 *  @param indexPath: 列表序号
 */
- (void)loadedUsingBlock:(void(^)(NSIndexPath *indexPath))block;

/**
 *  @brief 被选中
 *  @param indexPath: 列表序号
 */
- (void)selectedUsingBlock:(void(^)(NSIndexPath *indexPath))block;

/**
 *  @brief 按钮点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 */
- (void)buttonTouchUsingBlock:(void(^)(NSIndexPath *indexPath, NSInteger controlIndex))block;

/**
 *  @brief 图片点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 *  @waring 若要使用此方法，请将视图的用户交互打开（设置属性`***.userInteractionEnabled = YES;`）
 */
- (void)imageViewTouchUsingBlock:(void(^)(NSIndexPath *indexPath, NSInteger controlIndex))block;

/**
 *  @brief 文本点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 *  @waring 若要使用此方法，请将视图的用户交互打开（设置属性`***.userInteractionEnabled = YES;`）
 */
- (void)textLabelTouchUsingBlock:(void(^)(NSIndexPath *indexPath, NSInteger controlIndex))block;

@end

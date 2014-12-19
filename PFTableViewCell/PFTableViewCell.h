//
//  PFTableViewCell.h
//  PFTableViewCell
//
//  Created by PFei_He on 14-11-12.
//  Copyright (c) 2014年 PF-Lib. All rights reserved.
//
//  https://github.com/PFei-He/PFTableViewCell-Static_Library
//
//  vesion: 0.3.0
//

#import <UIKit/UIKit.h>

/**
 *  弱引用`self`。用于解决代码块（block）与强引用self之间的循环引用问题
 *  调用方式: `@weakify_self`实现弱引用转换，而后使用`weakSelf`代替`self`
 *
 *  示例:
 *  @weakify_self
 *  [obj block:^{
 *      weakSelf.property = something;
 *  }];
 *
 */
#ifndef	weakify_self
    #if __has_feature(objc_arc)
        #define weakify_self autoreleasepool{} __weak __typeof__(self) weakSelf = self;
    #else
        #define weakify_self autoreleasepool{} __block __typeof__(self) blockSelf = self;
    #endif
#endif

/**
 *  弱引用`object`。用于解决代码块（block）与强引用对象之间的循环引用问题
 *  调用方式: `@weakify`实现弱引用转换，`@normalize`把转换后的对象改回原来的对象名
 *
 *  示例:
 *  @weakify(object)
 *  [obj block:^{
 *      @normalize(object)
 *      object = something;
 *  }];
 *
 */
#ifndef	weakify
    #if __has_feature(objc_arc)
        #define weakify(object)	autoreleasepool{} __weak __typeof__(object) __weak_##object##__ = object;
    #else
        #define weakify(object)	autoreleasepool{} __block __typeof__(object) __block_##object##__ = object;
    #endif
#endif
#ifndef	normalize
    #if __has_feature(objc_arc)
        #define normalize(object) try{} @finally{} __typeof__(object) object = __weak_##object##__;
    #else
        #define normalize(object) try{} @finally{} __typeof__(object) object = __block_##object##__;
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
 *  @brief 点击
 *  @param indexPath: 列表序号
 *  @waring 若要使用此方法，请将列表的点击手势打开（设置属性`***.useTapGestureRecognizer = YES;`）
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell didSelectRowAtIndexPath:(NSIndexPath *)indexPath;

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

///是否使用点击手势（默认为关闭）
@property (nonatomic, assign)           BOOL            useTapGestureRecognizer;

///是否可以刷新列表（默认为是）
@property (nonatomic, assign)           BOOL            refreshEnable;

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
 *  @warning 请于列表所在的视图控制器类的`- (void)dealloc{}`方法使用
 */
+ (void)removeAllHeightSettings;

#pragma mark -

/**
 *  @brief 加载完成
 *  @param indexPath: 列表序号
 */
- (void)loadedUsingBlock:(void (^)(PFTableViewCell *tableViewCell, NSIndexPath *indexPath))block;

/**
 *  @brief 点击
 *  @param indexPath: 列表序号
 *  @waring 若要使用此方法，请将列表的点击手势打开（设置属性`***.useTapGestureRecognizer = YES;`）
 */
- (void)didSelectRowUsingBlock:(void (^)(PFTableViewCell *tableViewCell, NSIndexPath *indexPath))block;

/**
 *  @brief 按钮点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 */
- (void)buttonTouchUsingBlock:(void (^)(PFTableViewCell *tableViewCell, NSIndexPath *indexPath, NSInteger controlIndex))block;

/**
 *  @brief 图片点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 *  @waring 若要使用此方法，请将视图的用户交互打开（设置属性`***.userInteractionEnabled = YES;`）
 */
- (void)imageViewTouchUsingBlock:(void (^)(PFTableViewCell *tableViewCell, NSIndexPath *indexPath, NSInteger controlIndex))block;

/**
 *  @brief 文本点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二
 *  @waring 若要使用此方法，请将视图的用户交互打开（设置属性`***.userInteractionEnabled = YES;`）
 */
- (void)textLabelTouchUsingBlock:(void (^)(PFTableViewCell *tableViewCell, NSIndexPath *indexPath, NSInteger controlIndex))block;

@end

//
//  PFTableViewCell.h
//  PFTableViewCell
//
//  Created by PFei_He on 14-11-12.
//  Copyright (c) 2014年 PFei_He. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PFTableViewCell;

@protocol PFTableViewCellDelegate <NSObject>

@optional

/**
 *  @brief 加载完成
 */
- (void)tableViewCellLoaded;

/**
 *  @brief 点击
 *  @param indexPath: 列表序号
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell didSelectRowAtIndexPath:(NSIndexPath *)indexPath;

/**
 *  @brief 按钮点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二，3为控件三
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell buttonDidSelectRowAtIndexPath:(NSIndexPath *)indexPath controlIndex:(NSInteger)controlIndex;

/**
 *  @brief 图片点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二，3为控件三
 */
- (void)tableViewCell:(PFTableViewCell *)tableViewCell imageViewDidSelectRowAtIndexPath:(NSIndexPath *)indexPath controlIndex:(NSInteger)controlIndex;

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

///是否使用自定义手势（默认为关闭）
@property (nonatomic, assign)           BOOL            useGestureRecognizer;

#pragma mark - View

///是否显示内容页
@property (nonatomic, assign)           BOOL            firstContentViewShow;

///内容页
@property (nonatomic, strong, readonly) UIView          *firstContentView;

#pragma mark -

///是否显示分割线
@property (nonatomic, assign)           BOOL            lineShow;

///分割线尺寸
@property (nonatomic, assign)           CGRect          lineFrame;

///分割线颜色
@property (nonatomic, strong)           UIColor         *lineColor;

#pragma mark - Button

///自定义按钮
@property (nonatomic, strong, readonly) UIButton        *firstButton;

///自定义按钮类型
@property (nonatomic, assign)           UIButtonType    firstButtonType;

#pragma mark -

///自定义按钮
@property (nonatomic, strong, readonly) UIButton        *secondButton;

///自定义按钮类型
@property (nonatomic, assign)           UIButtonType    secondButtonType;

#pragma mark - Image

///是否显示自定义图片
@property (nonatomic, assign)           BOOL            firstImageViewShow;

///自定义图片视图
@property (nonatomic, strong, readonly) UIImageView     *firstImageView;

///是否打开自定义图片的用户交互
@property (nonatomic, assign)           BOOL            firstImageViewUserInteractionEnabled;

#pragma mark -

///是否显示自定义图片
@property (nonatomic, assign)           BOOL            secondImageViewShow;

///自定义图片视图
@property (nonatomic, strong, readonly) UIImageView     *secondImageView;

///是否打开自定义图片的用户交互
@property (nonatomic, assign)           BOOL            secondImageViewUserInteractionEnabled;

#pragma mark - Label

///是否显示自定义文本
@property (nonatomic, assign)           BOOL            firstTextLabelShow;

///自定义文字视图
@property (nonatomic, strong, readonly) UILabel         *firstTextLabel;

#pragma mark -

///是否显示自定义文本
@property (nonatomic, assign)           BOOL            secondTextLabelShow;

///自定义文字视图
@property (nonatomic, strong, readonly) UILabel         *secondTextLabel;

#pragma mark - Methods

/**
 *  @brief 初始化
 *  @param delegate: 代理（使用块方法时设为nil）
 *  @param size: 尺寸
 */
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier delegate:(id<PFTableViewCellDelegate>)delegate size:(CGSize)size;

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
 *  @warning 请在`- (void)dealloc{}`方法使用
 */
+ (void)removeAllHeightSettings;

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
 *  @brief 加载完成
 */
- (void)tableViewCellLoadedUsingBlock:(void (^)())block;

/**
 *  @brief 点击
 *  @param indexPath: 列表序号
 */
- (void)didSelectRowAtIndexPathUsingBlock:(void (^)(PFTableViewCell *tableViewCell, NSIndexPath *indexPath))block;

/**
 *  @brief 按钮点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二，3为控件三
 */
- (void)buttonDidSelectRowAtIndexPathUsingBlock:(void (^)(PFTableViewCell *tableViewCell, NSIndexPath *indexPath, NSInteger controlIndex))block;

/**
 *  @brief 图片点击
 *  @param indexPath: 列表序号
 *  @param controlIndex: 控件序号，1为控件一，2为控件二，3为控件三
 */
- (void)imageViewDidSelectRowAtIndexPathUsingBlock:(void (^)(PFTableViewCell *tableViewCell, NSIndexPath *indexPath, NSInteger controlIndex))block;

@end

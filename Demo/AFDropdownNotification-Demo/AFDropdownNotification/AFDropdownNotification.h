//
//  AFDropdownNotification.h
//  AFDropdownNotification-Demo
//
//  Created by Alvaro Franco on 21/08/14.
//  Copyright (c) 2014 AluanaLabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@protocol AFDropdownNotificationDelegate <NSObject>

-(void)dropdownNotificationTopButtonTapped;
-(void)dropdownNotificationBottomButtonTapped;

@end

@interface AFDropdownNotification : NSObject

typedef NS_ENUM(NSInteger, AFDropdownNotificationEvent) {
    
    AFDropdownNotificationEventTopButton,
    AFDropdownNotificationEventCentralButton,
    AFDropdownNotificationEventBottomButton,
    AFDropdownNotificationEventTap
};

typedef void (^block)(AFDropdownNotificationEvent event);

@property (nonatomic, strong) id<AFDropdownNotificationDelegate> notificationDelegate;

@property (nonatomic, strong) UIView *notificationView;

@property (nonatomic, strong) NSString *titleText;
@property (nonatomic, strong) NSString *subtitleText;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) NSString *topButtonText;
@property (nonatomic, strong) NSString *bottomButtonText;
@property (nonatomic, strong) UIColor *dropdownBackgroundColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIImage *centralButtonImage;
@property (nonatomic, strong) UIImageView *imageView;

@property (nonatomic, assign) BOOL forceStatusbarStyleUpdate;
@property (nonatomic, assign) UIStatusBarStyle forceStatusbarStyle;

@property (nonatomic) BOOL isBeingShown;

- (void)updateImage:(UIImage *)image animated:(BOOL)animated;

-(void)listenEventsWithBlock:(block)block;

-(void)presentInView:(UIView *)view withGravityAnimation:(BOOL)animation;
-(void)dismissWithGravityAnimation:(BOOL)animation;

@property (nonatomic) BOOL dismissOnTap;

@end
